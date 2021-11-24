#ifndef __LCD_H__
#define __LCD_H__


void pulseEnable();
void lcd_byte(char bits);
void SetCmdMode();
void SetChrMode();
void lcd_text(char *s);
void lcd_init();




#endif
