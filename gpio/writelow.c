/*********************************************************
 *
 *  Gpio_write.c - Test file to check working of lgpiod lib
 *  Modified: to take any gpio as a parmater while executing the program 
 *  
 ********************************************************/

#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>

//#define GPIO_PIN    17

struct gpiod_chip *chip;
struct gpiod_line *line;
int rv, value;
int GPIO_PIN;

int main(int argc, char* argv[])
{
	
    char *p;
    long num;
    if(argc > 2 || argc < 2)
    {
	printf("invalid arguments: Argument should be pin number\n");
	return 0;
    }
    num = strtol(argv[1], &p, 10);
    GPIO_PIN = num;
    printf("GPIO Pin selected is %d\n", GPIO_PIN);
    	
    chip= gpiod_chip_open("/dev/gpiochip0");

    if (!chip)
     return -1;

    line = gpiod_chip_get_line(chip, GPIO_PIN);

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

    value = gpiod_line_set_value(line, 0); // set low
    printf("GPIO%d value is cleared to 0\n", GPIO_PIN);
    sleep(1);
    gpiod_chip_close(chip);

    return 0;
}
