#include <reg52.h>

sbit LED = P3^1;

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 123; j++);
}

void main() {
    while (1) {
        LED = 0;     // Turn ON LED
        delay_ms(500);
        LED = 1;     // Turn OFF LED
        delay_ms(500);
    }
}
