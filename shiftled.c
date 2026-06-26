//write an ecp to control eight al_led @500ms interfacing with lpc2129
#include<lpc21xx.h>
#define led 0xFF
void delay_ms(int);
void delay_ms(int dly)
{
	int i;
	for(;dly>0;dly--)
	for(i=12000;i>0;i--);
}
int main()
{
	int i;
	PINSEL0=0x00000000;
	IODIR0=led;
	while(1)
	{
		for(i=0;i<8;i++)
		{
		IOCLR0=1<<i;
		delay_ms(100);
		IOSET0=1<<i;
		delay_ms(100);
	}
 }
}