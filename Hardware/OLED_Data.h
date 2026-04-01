#ifndef __OLED_DATA_H
#define	__OLED_DATA_H

typedef struct{
	char Index[4];
	uint8_t Data[32];
}ChineseCell_t;

extern const ChineseCell_t OLED_CF16x16[];
extern const uint8_t OLED_F8x16[][16];
extern const uint8_t OLED_F6x8[][6];
#endif
