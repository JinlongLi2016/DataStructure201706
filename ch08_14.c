#include <stdio.h>
#define N 9

int main(int argc, char const *argv[])
{
	int f(int, int);
	int i, a, b;
	int( *p)(int x, int y); // 定义指向函数指针的指针变量
	printf("Please input data:\n");
	scanf("%d", &a);
	p = f; // assign a function(address) to the function pointer

	for(i=1; i<N; i++)
	{
		scanf("%d", &b);
		a = (*p)(a, b);
	}
	printf("The Max Number is:%d\n", a);
	return 0;
}

int f(int x, int y)
{
	int z;
	z = (x>y)? x: y;
	return z;
}

// for i in range(10):
// 