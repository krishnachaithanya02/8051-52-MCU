#include <reg51.h>


sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;


void delay(unsigned int time);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_init();
void lcd_string(char *str);

void main() {
    lcd_init();         
    
    lcd_cmd(0x80);      
    lcd_string("8051"); 
    
    lcd_cmd(0xC0);      
    lcd_string("EMBEDDED");

    while(1);       
}


void lcd_init() {
    lcd_cmd(0x38); // 8-bit mode, 2 lines
    lcd_cmd(0x0C); // Display ON, Cursor OFF
    lcd_cmd(0x01); // Clear Screen
    delay(2);
}

void lcd_string(char *str) {
    while(*str != '\0') {
        lcd_data(*str);
        str++;
    }
}

void lcd_cmd(unsigned char cmd) {
    P2 = cmd;
    RS = 0; 
	RW = 0; 
	EN = 1;
	delay(1);
	EN = 0;
}

void lcd_data(unsigned char dat) {
    P2 = dat;
    RS = 1; 
	RW = 0; 
	EN = 1; 
	delay(1); 
	EN = 0;
}

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 120; j++);
}
