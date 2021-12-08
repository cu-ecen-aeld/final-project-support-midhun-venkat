/*********************************************************
 *
 *  led.c - Blink an LED connected to GPIO5
 *  Test code to verify the use of libgpiod 
 *  
 ********************************************************/
 
#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>


#define HIGH 1
#define LOW 0
#define GPIO_LED 5

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

  while(counter < 5)
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
