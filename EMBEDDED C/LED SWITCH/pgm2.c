#include <reg52.h>

sbit LED = P1^0;    // LED connected to P1.0
sbit SW  = P2^0;    // Switch connected to P2.0

void main() {
    while(1) {
        if(SW == 0) { // If switch is pressed (GND)
            LED = 0;  // Turn LED ON (assuming Active Low)
        } else {
            LED = 1;  // Turn LED OFF
        }
    }
}