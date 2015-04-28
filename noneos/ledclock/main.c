/*****************************************************
 * 顺序流水灯裸机测试程序 by bblu @ 2015-04-28           *
 * 由于Tiny6410_LED灯引脚排序问题有些小变化                *
 *****************************************************/

#define GPKCON0 (*(volatile unsigned long *)0x7F008800)
#define GPKDAT  (*(volatile unsigned long *)0x7F008808)

void delay(int count);

int main()
{
	GPKCON0 = 0x11110000;
	GPKDAT = 0x0E;

	int i = 0;
	while(1)
	{
		int j=i;

		if(i==3)j=4;
		if(i==4)j=3;//LED灯引脚排序颠倒
		GPKDAT|=1<<j+3;
		
		delay(0x500000);

		if(i==4)
		{
			GPKDAT = 0x0E;
			i=0;
		}
		else
			i++;
	}
	return 0;
}


