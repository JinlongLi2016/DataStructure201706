#include<stdio.h>
int main(void)
{
	int i, sum = 0;
	i = 1;
	while(i<=100)
	{
		sum += i++;
	}
	printf("1+2+..+100=%d\n", sum );

	return 0;
}