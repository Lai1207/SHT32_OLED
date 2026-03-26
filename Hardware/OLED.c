#include "stm32f10x.h"                  // Device header
#include "MyI2c.h"
#include "Delay.h"


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
	
}

void OLED_SetCursor(uint8_t x, uint8_t page){												//x 0-128 page 0-7
	OLED_WriteCommand(0x00 | (x & 0x0F));															//x lsb
	OLED_WriteCommand(0x10 | (x & 0xF0) >> 4); 												//x msb
	OLED_WriteCommand(0xB0 | page); 																	//page 

}

