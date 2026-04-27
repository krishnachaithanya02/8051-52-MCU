#include <reg51.h>

void delay_ms(unsigned int ms) {
	unsigned int i;
	for (i=0; i<ms; i++) {
		TMOD = 0xF0;
		TMOD = 0x01;
		
		TH0 = 0xFC;
		TL0 = 0x66;
		 TR0 = 1;
		while(TF0==0);
		TR0 = 0;
		TF0 = 0;
	}
}
void main() {
	unsigned char pattern;
	while(1){
		pattern = 0x01;
		
		while(pattern!=0x00) {
			P1 = pattern;
			
			delay_ms(100);
			pattern = pattern<<1;
		}
	}
}
