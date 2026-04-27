#include <reg52.h>

sbit LED = P1^0;  

// Timer0 based delay
void delay_ms(unsigned int ms)
{
    unsigned int i;

    for(i = 0; i < ms; i++)
    {
        TMOD = 0xF0;   // Clear Timer0 
        TMOD = 0x01;   // Set Timer0 Mode1 (16-bit)

        TH0 = 0xFC;     // Load high byte
        TL0 = 0x66;     // Load low byte 

        TR0 = 1;        // Start Timer0

        while(TF0 == 0);  // Wait for overflow

        TR0 = 0;        // Stop Timer0
        TF0 = 0;        // Clear overflow flag
    }
}

void main(void)
{
    LED = 1;   // Ensure LED OFF initially

    while(1)
    {
        LED = 0;          // LED ON (Active LOW)
        delay_ms(500);    // 500 ms delay

        LED = 1;          // LED OFF
        delay_ms(500);    // 500 ms delay
    }
}
