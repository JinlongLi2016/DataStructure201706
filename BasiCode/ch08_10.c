#include <stdio.h>
void sort(int [], int);
int main(void)
{
	int *p, i, a[10];
	printf("Please input data\n");
	for(i=0; i<10; i++)
		scanf("%d", a+i);
	sort(a, 10);
	for(p=a; p<a+10; p++)
		printf("%-3d", *p);
	printf("\n");

	return 0;
}
void sort(int x[], int n)
{
	int *x_end, *y, *p, temp;
	x_end = x + n;
	for(; x<x_end-1; x++)
	{
		p = x;
		for(y=x+1; y<x_end; y++)
			if(*y > *p) 	p=y;
		if(p!= x)	//选择排序？
			{	temp = *x; *x = *p; *p = temp;	}
	}
}