#ifndef __LCD_H__
#define __LCD_H__

#include "wiringPi.h"

void pulseEnable();
void lcd_byte(char bits);
void SetCmdMode();
void SetChrMode();
void lcd_text(char *s);
void lcd_init();
void lcd_clear();
void lcd_print(char *msg);





#endif
