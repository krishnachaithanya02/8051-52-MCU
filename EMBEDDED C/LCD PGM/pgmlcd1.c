#include <reg51.h>
#define port2 P2

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;


void delay(unsigned int time);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char d);
void lcd_init();
void lcd_string(char *str);

void main() {
    // Initializing hardware
    lcd_init();         
    
    // Command to set cursor to first line
         
    
    // Function call to display string
    lcd_string("HELLO"); 

    // Industry Standard Infinite Loop
    while(1) {
        // Controller stays here after execution
    }
}


void lcd_init() {
    lcd_cmd(0x38); // 8-bit mode, 2 lines
    lcd_cmd(0x0C); // Display ON, Cursor OFF
    lcd_cmd(0x01); // Clear Display RAM
    delay(2);
}

void lcd_string(char *str) {
    
    while(*str != '\0') {
        lcd_data(*str);
        str++;
    }
}

void lcd_cmd(unsigned char cmd) {
    port2 = cmd;
    RS = 0; // Command Register
    RW = 0; // Write Mode
    EN = 1;
    delay(1);
    EN = 0;
}

void lcd_data(unsigned char d) {
    port2 = d;
    RS = 1; // Data Register
    RW = 0; // Write Mode
    EN = 1;
    delay(1);
    EN = 0;
}

void delay(unsigned int time) {
    unsigned int i, j;
    // Standard nested for loops for delay
    for(i = 0; i < time; i++) {
        for(j = 0; j < 120; j++);
    }
}