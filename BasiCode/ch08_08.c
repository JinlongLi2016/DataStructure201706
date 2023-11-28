#include<stdio.h>
int main(void)
{
	int a[3][4], *ptr;
	int i, j;
	ptr = a[0];


	printf("Please input data:\n");
	for(i=0; i<3; i++)
		for(j=0; j<4; j++)
			scanf("%d", ptr++);
	

	ptr = a[0];
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
			printf("%-3d", *ptr++);
		printf("\n");
	}

	return 0;
}