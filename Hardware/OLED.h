#ifndef __OLED_H
#define __OLED_H
void OLED_WriteCommand(uint8_t Command);
void OLED_WriteData(uint8_t Data);
void OLED_Init(void);
void OLED_SetCursor(uint8_t x, uint8_t page);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x, uint8_t page, char Char, uint8_t FontSize);
	
#endif