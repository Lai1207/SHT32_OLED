#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MyI2c.h"
#include "LED.h"
#include "OLED.h"
int main(void){
	
	OLED_Init();
	for(uint8_t j = 0; j < 8; j ++){
		OLED_SetCursor(0, j);
		for(uint8_t i = 0; i < 128; i++){
			OLED_WriteData(0x00);
		}
	}
	OLED_SetCursor(10,2);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);
	OLED_WriteData(0x55);

	while(1){
		
	}
}
 
