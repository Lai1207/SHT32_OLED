#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MyI2c.h"
#include "LED.h"
#include "OLED.h"
int main(void){
	
	OLED_Init();
	OLED_Clear();
	
	OLED_ShowChar(0,0, '#',6);
	OLED_ShowChar(0,1,'#',8);
	


	while(1){
		
	}
}
 
