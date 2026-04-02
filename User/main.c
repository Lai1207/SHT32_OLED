#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MyI2c.h"
#include "LED.h"
#include "OLED.h"

int main(void){
	
	OLED_Init();
	OLED_Clear();
	
	//OLED_ShowChar(0,0, '#',6);
	//OLED_ShowChar(0,1,'#',8);
	
	//OLED_ShowString(0,2,"Hello World",6);
	//OLED_ShowImage(0, 0, 64, 8, font_data);
	//OLED_ShowChinese(0, 0,"大船入港");
	//OLED_ShowNum(32,0,123,3,8);
	OLED_ShowChinese(0, 0, "%");
	while(1){
		
	}
}


