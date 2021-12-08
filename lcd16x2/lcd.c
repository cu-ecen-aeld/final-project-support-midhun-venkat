#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>


#define HIGH 1
#define LOW 0

int main(int argc, char **argv)
{
  const char *chipname = "gpiochip0";
  struct gpiod_chip *chip;
  struct gpiod_line *lineE;    // Red LED
  struct gpiod_line *lineRS;  // Green LED
  struct gpiod_line *lineD4; // Yellow LED
  struct gpiod_line *lineD5; // Pushbutton
  struct gpiod_line *lineD6; // Yellow LED
  struct gpiod_line *lineD7; // Pushbutton
  int i, val;

  // Open GPIO chip
  chip = gpiod_chip_open_by_name(chipname);

  // Open GPIO lines
  lineE = gpiod_chip_get_line(chip, 23);
  lineRS = gpiod_chip_get_line(chip, 22);
  lineD4 = gpiod_chip_get_line(chip, 24);
  lineD5 = gpiod_chip_get_line(chip, 25);
  lineD6 = gpiod_chip_get_line(chip, 8);
  lineD7 = gpiod_chip_get_line(chip, 7);
  

  // Open LED lines for output
  gpiod_line_request_output(lineE, "example1", 0);
  gpiod_line_request_output(lineRS, "example1", 0);
  gpiod_line_request_output(lineD4, "example1", 0);
  gpiod_line_request_output(lineD5, "example1", 0);
  gpiod_line_request_output(lineD6, "example1", 0);
  gpiod_line_request_output(lineD7, "example1", 0);

  // Initialize LCD
  gpiod_line_set_value(lineRS, 0); // SetCmdMode
  
  // lcd_byte(0x33); // full init
  gpiod_line_set_value(lineD4,(0x33 & 0x10)) ;  
  gpiod_line_set_value(lineD5,(0x33 & 0x20)) ;  
  gpiod_line_set_value(lineD6,(0x33 & 0x40)) ;  
  gpiod_line_set_value(lineD7,(0x33 & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,(0x33 & 0x1)) ;  
  gpiod_line_set_value(lineD5,(0x33 & 0x2)) ;  
  gpiod_line_set_value(lineD6,(0x33 & 0x4)) ;  
  gpiod_line_set_value(lineD7,(0x33 & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  
  // lcd_byte(0x32); // full bit mode
  gpiod_line_set_value(lineD4,(0x32 & 0x10)) ;  
  gpiod_line_set_value(lineD5,(0x32 & 0x20)) ;  
  gpiod_line_set_value(lineD6,(0x32 & 0x40)) ;  
  gpiod_line_set_value(lineD7,(0x32 & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,(0x32 & 0x1)) ;  
  gpiod_line_set_value(lineD5,(0x32 & 0x2)) ;  
  gpiod_line_set_value(lineD6,(0x32 & 0x4)) ;  
  gpiod_line_set_value(lineD7,(0x32 & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  
  // lcd_byte(0x28); 2 line mode
  gpiod_line_set_value(lineD4,(0x28 & 0x10)) ;  
  gpiod_line_set_value(lineD5,(0x28 & 0x20)) ;  
  gpiod_line_set_value(lineD6,(0x28 & 0x40)) ;  
  gpiod_line_set_value(lineD7,(0x28 & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,(0x28 & 0x1)) ;  
  gpiod_line_set_value(lineD5,(0x28 & 0x2)) ;  
  gpiod_line_set_value(lineD6,(0x28 & 0x4)) ;  
  gpiod_line_set_value(lineD7,(0x28 & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  
  // lcd_byte(0x0C); // display On, Cursor Off, Blink off
  gpiod_line_set_value(lineD4,(0x0C & 0x10)) ;  
  gpiod_line_set_value(lineD5,(0x0C & 0x20)) ;  
  gpiod_line_set_value(lineD6,(0x0C & 0x40)) ;  
  gpiod_line_set_value(lineD7,(0x0C & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,(0x0C & 0x1)) ;  
  gpiod_line_set_value(lineD5,(0x0C & 0x2)) ;  
  gpiod_line_set_value(lineD6,(0x0C & 0x4)) ;  
  gpiod_line_set_value(lineD7,(0x0C & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  
  // lcd_byte(0x01); // clear screen
  gpiod_line_set_value(lineD4,(0x01 & 0x10)) ;  
  gpiod_line_set_value(lineD5,(0x01 & 0x20)) ;  
  gpiod_line_set_value(lineD6,(0x01 & 0x40)) ;  
  gpiod_line_set_value(lineD7,(0x01 & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,(0x01 & 0x1)) ;  
  gpiod_line_set_value(lineD5,(0x01 & 0x2)) ;  
  gpiod_line_set_value(lineD6,(0x01 & 0x4)) ;  
  gpiod_line_set_value(lineD7,(0x01 & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  
  usleep(5*1000); // wait for clearing the screen
  
  
  gpiod_line_set_value(lineRS, 1); // SetChrMode
  
  // print H
  // lcd_byte('H');
  gpiod_line_set_value(lineD4,('H' & 0x10)) ;  
  gpiod_line_set_value(lineD5,('H' & 0x20)) ;  
  gpiod_line_set_value(lineD6,('H' & 0x40)) ;  
  gpiod_line_set_value(lineD7,('H' & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,('H' & 0x1)) ;  
  gpiod_line_set_value(lineD5,('H' & 0x2)) ;  
  gpiod_line_set_value(lineD6,('H' & 0x4)) ;  
  gpiod_line_set_value(lineD7,('H' & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  
  // print e
  // lcd_byte('e');
  gpiod_line_set_value(lineD4,('e' & 0x10)) ;  
  gpiod_line_set_value(lineD5,('e' & 0x20)) ;  
  gpiod_line_set_value(lineD6,('e' & 0x40)) ;  
  gpiod_line_set_value(lineD7,('e' & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,('e' & 0x1)) ;  
  gpiod_line_set_value(lineD5,('e' & 0x2)) ;  
  gpiod_line_set_value(lineD6,('e' & 0x4)) ;  
  gpiod_line_set_value(lineD7,('e' & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  
  // print l
  // lcd_byte('l');
  gpiod_line_set_value(lineD4,(0x6C & 0x10)) ;  
  gpiod_line_set_value(lineD5,(0x6C & 0x20)) ;  
  gpiod_line_set_value(lineD6,(0x6c & 0x40)) ;  
  gpiod_line_set_value(lineD7,(0x6c & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,(0x6C & 0x1)) ;  
  gpiod_line_set_value(lineD5,(0x6C & 0x2)) ;  
  gpiod_line_set_value(lineD6,(0x6C & 0x4)) ;  
  gpiod_line_set_value(lineD7,(0x6C & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  
  
  // print E
  // lcd_byte('E');
  gpiod_line_set_value(lineD4,(0x45 & 0x10)) ;  
  gpiod_line_set_value(lineD5,(0x45 & 0x20)) ;  
  gpiod_line_set_value(lineD6,(0x45 & 0x40)) ;  
  gpiod_line_set_value(lineD7,(0x45 & 0x80)) ;  
   //pulseEnable();
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ; 

  gpiod_line_set_value(lineD4,(0x45 & 0x1)) ;  
  gpiod_line_set_value(lineD5,(0x45 & 0x2)) ;  
  gpiod_line_set_value(lineD6,(0x45 & 0x4)) ;  
  gpiod_line_set_value(lineD7,(0x45 & 0x8)) ;  
   //pulseEnable(); 
  gpiod_line_set_value(lineE, HIGH) ; 
  usleep(0.5*1000); // 0.5 useconds - enable pulse must be > 450ns
  gpiod_line_set_value(lineE, LOW) ;
  


  // Release lines and chip
  gpiod_line_release(lineE);
  gpiod_line_release(lineRS);
  gpiod_line_release(lineD4);
  gpiod_line_release(lineD5);
  gpiod_line_release(lineD6);
  gpiod_line_release(lineD7);
  gpiod_chip_close(chip);
  return 0;
}
