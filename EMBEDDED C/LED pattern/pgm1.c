#include <reg51.h>

void delay(unsigned int count) {   //delay called
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
    
    while(1) { //infinite loop
        pattern = 0x01; // Start with 0000 0001
        
        while(pattern != 0x00) {
            P1 = pattern;      // Output to Port 1
            delay(100);        // Wait
            pattern = pattern << 1; // Left shift
        }
    }
}
