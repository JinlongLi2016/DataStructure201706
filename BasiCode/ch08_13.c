#include <stdio.h>
int main(void)
{
	int a[3][4];
	int **p, *q;
	int i, j;
	printf("Please input data:\n");
	for(i=0; i<3; i++)
		for(j=0; j<4; j++)
			scanf("%d", &a[i][j]);

	for(i=0; i<3; i++)
	{
		q = a[i];
		p = &q;
		for(j=0; j<4; j++)
			printf("%-4d\n", *(*p+j));
	}
}