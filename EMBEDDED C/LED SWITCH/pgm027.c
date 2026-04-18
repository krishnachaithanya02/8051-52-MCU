# include <reg51.h>

sbit LED1 = P1^0;
sbit LED2 = P1^1;

sbit SW1 = P2^0;
sbit SW2 = P2^1;

void main() {
	LED1 = 1;
	LED2 = 1;
	
	while(1) {
		if (SW1==0)
			LED1 = 0;
		else
			LED1 = 1;
	if (SW2==0)
		LED2 = 0;
	else 
		LED2 =1;
}
		}