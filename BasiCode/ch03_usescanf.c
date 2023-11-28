#include<stdio.h>
int main(void)
{
	int a, b, c;
	printf("请输入a, b, c的值：\n");
	scanf("%d%d%d", &a, &b, &c);
	printf("a = %d, b = %d, c = %d", a, b, c);


	char c1, c2, c3;
	printf("Please input three chars:\n");
	scanf("%c %c %c", &c1, &c2, &c3);
	printf("c1 = %c, c2 = %c, c3 = %c", c1, c2, c3);


	return 0;
}