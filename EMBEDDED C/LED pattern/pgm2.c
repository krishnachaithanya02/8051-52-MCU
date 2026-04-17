#include <reg51.h>

void delay(unsigned int count) {
    unsigned int i, j;
    i = 0;
    while(i < count) {
        j = 0;
        while(j < 500) {
            j++;
        }
        i++;
    }
}

void main() {
    unsigned char pattern;
    
    while(1) { // Super loop
        pattern = 0x80; // Start with 1000 0000 (MSB)
        
        while(pattern != 0x00) {
            P1 = pattern;      // Output to Port 1
            delay(100);        // Wait
            pattern = pattern >> 1; // Right shift
        }
    }
}