#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gpiod.h>

struct gpiod_chip *chip;
struct gpiod_line *line;

#define LCD_E 23
#define LCD_RS 22
#define LCD_D4 24
#define LCD_D5 25
#define LCD_D6 8
#define LCD_D7 7

#define HIGH 1
#define LOW 0

int gpio_write(int gpio_pin, int value)
{
	if(value >= 1)
	{
		value = 1;
	}
	else
	{
		value = 0;
	}
	int rv;
	chip= gpiod_chip_open("/dev/gpiochip0");

    	if (!chip)
	 return -1;	
	 
	line = gpiod_chip_get_line(chip, gpio_pin);

	if (!line) 
    	{
	     gpiod_chip_close(chip);
	     return -1; 
    	}
    	
    	rv = gpiod_line_request_output(line, "foobar", 1);

	if (rv) 
    	{
	     gpiod_chip_close(chip);
	     return -1;
    	}

	gpiod_line_set_value(line, value); 
	printf("GPIO%d value is set to %d\n", gpio_pin, value);
	//sleep(1);
	gpiod_chip_close(chip);

	return 0;
}


int gpio_read(int gpio_pin)
{
	int rv, value;
	chip= gpiod_chip_open("/dev/gpiochip0");

    	if (!chip)
	 return -1;	
	 
	line = gpiod_chip_get_line(chip, gpio_pin);

	if (!line) 
    	{
	     gpiod_chip_close(chip);
	     return -1; 
    	}
    	
    	rv = gpiod_line_request_input(line, "foobar");

	if (rv) 
	{
	     gpiod_chip_close(chip);
	     return -1;
	}

	value = gpiod_line_get_value(line);
	
	printf("GPIO%d value is %d\n", gpio_pin, value);
    	gpiod_chip_close(chip);
    	
    	return value;
}


void pulseEnable ()
{
   printf("Pulse Enable high\n");
   gpio_write(LCD_E, HIGH) ; 
   usleep(0.5); // 0.5 useconds - enable pulse must be > 450ns
   printf("Pulse Enable low\n");
   gpio_write(LCD_E, LOW) ; 
}

/*
  send a byte to the lcd in two nibbles
  before calling use SetChrMode or SetCmdMode to determine whether to send character or command
*/
void lcd_byte(char bits)
{
  gpio_write(LCD_D4,(bits & 0x10)) ;  
  gpio_write(LCD_D5,(bits & 0x20)) ;  
  gpio_write(LCD_D6,(bits & 0x40)) ;  
  gpio_write(LCD_D7,(bits & 0x80)) ;  
  pulseEnable();

  gpio_write(LCD_D4,(bits & 0x1)) ;  
  gpio_write(LCD_D5,(bits & 0x2)) ;  
  gpio_write(LCD_D6,(bits & 0x4)) ;  
  gpio_write(LCD_D7,(bits & 0x8)) ;  
  pulseEnable();      	
}

void SetCmdMode() 
{
  gpio_write(LCD_RS, 0); // set for commands
}

void SetChrMode() 
{
  gpio_write(LCD_RS, 1); // set for characters
}

void lcd_text(char *s)
{
  while(*s) 
	lcd_byte(*s++);
 }

void lcd_init()
{  
   // initialise LCD
   SetCmdMode(); // set for commands
   lcd_byte(0x33); // full init 
   lcd_byte(0x32); // 4 bit mode
   lcd_byte(0x28); // 2 line mode
   lcd_byte(0x0C); // display on, cursor off, blink off
   lcd_byte(0x01);  // clear screen
   usleep(5);       // clear screen is slow!
}

int main (int argc, char *argv []) 
{
  lcd_init();
  printf("Initialization Done\n");
  SetChrMode(); 
  printf("Writing Text\n");
  lcd_text("hello world");
  //if (argc>1) 
     //lcd_text(argv[1]);
  //else 
     //lcd_text("hello world!");
	 
  return 0 ;
}






