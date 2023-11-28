#include <stdio.h>
#define N 3
int main(void)
{
	int matrix[N][N] = {0};
	int *p[N]; //定义整型指针数组
	int i, j;
	for(i=0; i<N; i++)
	{
		p[i] = matrix[i];
		for(j=0; j<N; j++)
		{
			if(i==j)	p[i][j] = 1;
			printf("%-3d", p[i][j]);
		}
		printf("\n");
	}

	return 0;
}