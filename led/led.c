/*********************************************************
 *
 *  led.c - Blink an LED connected to GPIO5
 *  Test code to verify the use of libgpiod 
 *  digital_write, digital_read functions are added for reference but not used in the main code below
 *  
 ********************************************************/
 
#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>


#define HIGH 1
#define LOW 0
#define GPIO_LED 5

// required if you plan to use digital_write and digital_read functions
struct gpiod_chip *chip;
struct gpiod_line *line;

// This an exact similar function to digital_write function available on wiring pi
int digital_write(int gpio_pin, int value)
{

	if(value >= 1)
		value = 1;
	else
		value = 0;
	
	int rv;
	chip = gpiod_chip_open("/dev/gpiochip0");

    	if (!chip)
	  return -1;	
	 
	line = gpiod_chip_get_line(chip, gpio_pin);

	if (!line) 
	{
	     	gpiod_chip_close(chip);
     	     	return -1; 
	}
	
	rv = gpiod_line_request_output(line, "example", 0); // default value

	if (rv) 
	{
     		gpiod_chip_close(chip);
     		return -1;
	}

	gpiod_line_set_value(line, value); 
	
	gpiod_chip_close(chip);
	
	return 0;

}

// This an exact similar function to digital_read function available on wiring pi
int digital_read(int gpio_pin)
{

	int rv, value;
	chip = gpiod_chip_open("/dev/gpiochip0");

    	if (!chip)
		return -1;	
	 
    	line = gpiod_chip_get_line(chip, gpio_pin);

    	if (!line) 
    	{
     	    	gpiod_chip_close(chip);
            	return -1; 
    	}
    	
    	rv = gpiod_line_request_input(line, "example");

    	if (rv) 
    	{
		gpiod_chip_close(chip);
	    	return -1;
    	}

    	value = gpiod_line_get_value(line);
	
   	gpiod_chip_close(chip);
    	
   	return value;
}

int main(int argc, char **argv)
{

  	const char *chipname = "gpiochip0";
  	struct gpiod_chip *chip;
  	struct gpiod_line *line;    // line for LED GPIO
  	int counter = 0;
  
  	// Open GPIO chip
  	chip = gpiod_chip_open_by_name(chipname);

  	// Open GPIO line
  	line = gpiod_chip_get_line(chip, GPIO_LED);
  
 	// Open LED lines for output
  	gpiod_line_request_output(line, "test", 0); // default value - set to 0

  	while(counter < 5) // blink for 5 seconds
  	{
  		gpiod_line_set_value(line , HIGH);
  		usleep(500*1000); // sleep for 500 milliseconds
  		gpiod_line_set_value(line, LOW);
  		usleep(500*1000); // sleep for 500 milliseconds
  		counter++;
  	}
  
  	// Release line and chip
  	gpiod_line_release(line);
  	gpiod_chip_close(chip);
  
  	return 0;
}
