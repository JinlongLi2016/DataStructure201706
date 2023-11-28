#include <stdio.h>
int main(void)
{
	int a[5][3], i, j;
	int (*b)[3]; //定义指向具有3个元素的一维数组的指针变量

	float sum, average;
	printf("Please input the data:\n");
	for(i=0; i<5; i++)
		for(j=0; j<3; j++)
			scanf("%d", &a[i][j]);

	for(b=a; b<a+5; b++)
	{
		sum = 0;
		for(i=0; i<3; i++)
			sum += * ( *b + i);
		average = sum / 3;
		printf("average = %.2f\n", average);
	}

	return 0;
}