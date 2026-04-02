#include "stm32f10x.h"                  // Device header
#include "MyI2c.h"
#include "Delay.h"
#include "OLED_Data.h"
#include <String.h>

void OLED_SetCursor(uint8_t x, uint8_t page);

uint32_t Pow(uint32_t x, uint32_t y){
	uint32_t result = 1;
	while(y--){
		result *= x;
	}
	return result;
}
void OLED_WriteCommand(uint8_t Command){
	
	MyI2C_Start();
	MyI2C_SendByte(0x78);
	MyI2C_ReceiveAck();
	
	MyI2C_SendByte(0x00);											//control Byte				| CO | D\C# | 0 | 0 | 0 | 0 | 0 | 0 |											
	MyI2C_ReceiveAck();
	
	MyI2C_SendByte(Command);									//Data Byte
	MyI2C_ReceiveAck();
	MyI2C_Stop();
	
}

void OLED_WriteData(uint8_t Data){
	
	MyI2C_Start();
	MyI2C_SendByte(0x78);
	MyI2C_ReceiveAck();
	
	MyI2C_SendByte(0x40);											//control Byte				| CO | D\C# | 0 | 0 | 0 | 0 | 0 | 0 |
	MyI2C_ReceiveAck();
	
	MyI2C_SendByte(Data);											//Data Byte
	MyI2C_ReceiveAck();
	MyI2C_Stop();
	
}
void OLED_Clear(void){
	for(uint8_t j = 0; j < 8; j ++){
		OLED_SetCursor(0, j);
		for(uint8_t i = 0; i < 128; i++){
			OLED_WriteData(0x00);
		}
	}
}

void OLED_Init(void){
	Myi2c_Init();
	Delay_ms(100);
  OLED_WriteCommand(0xAE);	
	
	OLED_WriteCommand(0xD5);	
	OLED_WriteCommand(0x80);	
	
	OLED_WriteCommand(0xA8);	
	OLED_WriteCommand(0x3F);	
	
	OLED_WriteCommand(0xD3);	
	OLED_WriteCommand(0x00);	
	
	OLED_WriteCommand(0x40);	
	
	OLED_WriteCommand(0xA1);	
	
	OLED_WriteCommand(0xC8);	

	OLED_WriteCommand(0xDA);	
	OLED_WriteCommand(0x12);
	
	OLED_WriteCommand(0x81);	
	OLED_WriteCommand(0xCF);	

	OLED_WriteCommand(0xD9);	
	OLED_WriteCommand(0xF1);

	OLED_WriteCommand(0xDB);	
	OLED_WriteCommand(0x30);

	OLED_WriteCommand(0xA4);	

	OLED_WriteCommand(0xA6);	

	OLED_WriteCommand(0x8D);	
	OLED_WriteCommand(0x14);

	OLED_WriteCommand(0xAF);
	
	Delay_ms(100);
	
	OLED_Clear();
	
}

void OLED_SetCursor(uint8_t x, uint8_t page){												//x 0-128 page 0-7
	OLED_WriteCommand(0x00 | (x & 0x0F));															//x lsb
	OLED_WriteCommand(0x10 | (x & 0xF0) >> 4); 												//x msb
	OLED_WriteCommand(0xB0 | page); 																	//page 

}



/*
OLED_F6X8[8][6]

PAGE[0]	0 1 2 3 4 5
				1
				2
				3
				4
				5
				6
				7


OLED_F8X16[16][8]

PAGE[0] 0 1 2 3 4 5 6 7 8
				1
				2
				3
				4
				5
				6
				7
PAGE[1] 8
				9
				10
				11
				12
				13
				14
				15

*/
void OLED_ShowChar(uint8_t x, uint8_t page, char Char, uint8_t fontSize){
	if(fontSize == 6){																											
		OLED_SetCursor(x, page);
		for(uint8_t i  = 0; i < 6; i ++){
			OLED_WriteData(OLED_F6x8[Char - ' '][i]);
		}
	}else if(fontSize == 8){
		OLED_SetCursor(x, page);
		for(uint8_t i  = 0; i < 8; i ++){
			OLED_WriteData(OLED_F8x16[Char - ' '][i]);
		}
		OLED_SetCursor(x, page + 1);
		for(uint8_t i = 0; i < 8; i++){
			OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);
		}
	}
}

void OLED_ShowString(uint8_t x, uint8_t page, char *string, uint8_t fontsize){
	 
	for(uint8_t i = 0;string[i] != '\0'; i++){
		OLED_ShowChar(x + i * fontsize, page, string[i], fontsize);
	}
}

void OLED_ShowImage(uint8_t x, uint8_t page, uint8_t width, uint8_t high, const uint8_t *image){
	for(uint8_t j = 0; j < high; j++){
		OLED_SetCursor(x, page + j);
		for(uint8_t i  = 0; i < width; i ++){
			OLED_WriteData(image[width * j + i]);		
		}
	}
}
void OLED_ShowChinese(uint8_t x, uint8_t page, char *Chinese){
	
	char SigleChinese[4] = {0};
	uint8_t pChinese = 0;
	uint8_t pIndex;
	
	for(uint8_t i = 0; Chinese[i] != '\0'; i++){
		
		SigleChinese[pChinese] = Chinese[i];
		pChinese ++;
		
		if(pChinese >= 3){
			 pChinese = 0;
			
			for(pIndex = 0; strcmp(OLED_CF16x16[pIndex].Index, "") != 0 ;pIndex++){
				
				if(strcmp(OLED_CF16x16[pIndex].Index, SigleChinese) == 0){
					break;
				}
			}
			OLED_ShowImage(x + ((i + 1) / 3 - 1) * 16, page, 16, 2, OLED_CF16x16[pIndex].Data);
			
		}
	
	}
}
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t length, uint8_t fontsize){
	for(uint8_t i = 0; i < length; i++){
		OLED_ShowChar((x+i)*fontsize, y,  num / Pow(10, length - i - 1) % 10 + '0', fontsize);
	}
}
