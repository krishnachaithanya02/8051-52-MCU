#include <reg52.h>

sbit LED = P1^0;
sbit SW = P2^0;

void main() 
{
	while(1) {
	if (SW==0) {
		LED = 0;
	}
	else {
		LED = 1;
	}
}
}