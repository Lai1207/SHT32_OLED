#ifndef __OLED_H
#define __OLED_H
void OLED_WriteCommand(uint8_t Command);
void OLED_WriteData(uint8_t Data);
void OLED_Init(void);
void OLED_SetCursor(uint8_t x, uint8_t page);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x, uint8_t page, char Char, uint8_t FontSize);
void OLED_ShowString(uint8_t x, uint8_t page, char *string, uint8_t fontsize);
void OLED_ShowImage(uint8_t x, uint8_t page, uint8_t width, uint8_t high, const uint8_t *image);
void OLED_ShowChinese(uint8_t x, uint8_t page, char *Chinese);
	
#endif
