#include <reg52.h>

void delay() {
    unsigned int i, j;
    for(i = 0; i < 200; i++)
        for(j = 0; j < 100; j++);
}

void main() {
    while(1) {
        
        P1 = 0x55;   // 01010101 ? Even LEDs ON
        delay();
        
        P1 = 0xAA;   // 10101010 ? Odd LEDs ON
        delay();
    }
}