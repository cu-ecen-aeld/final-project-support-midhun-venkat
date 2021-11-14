/*********************************************************
 *
 *  toggle.c - Test file to check toggling of a gpio pin given as parameter
 *  
 ********************************************************/

#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>
#include <stdlib.h>

//#define GPIO_PIN    17

struct gpiod_chip *chip;
struct gpiod_line *line;
int rv, value;
int count = 0;
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
	
	while(1)
 	{
 		value = gpiod_line_set_value(line, 1);
 		printf("GPIO%d value is set to 1\n", GPIO_PIN);
 		usleep(500 * 1000);
		
 		value = gpiod_line_set_value(line, 0);
 		printf("GPIO%d value is set to 0\n", GPIO_PIN);
 		usleep(500 * 1000);
		
 		count++;
 		if(count == 50) // for testing kept the count at 50
 		break;
 	}

        gpiod_chip_close(chip);

        return 0;
}
