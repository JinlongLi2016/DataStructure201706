#include <stdio.h>
#define N 10
struct tiger
{
	char name[20];
	char gender;
	int age;
	float weight;
	char father[20];
	char mother[20];
};
int main(void)
{
	struct tiger t[N]; // 定义结构体数组
	int i, flag = -1;
	printf("%s\n", );
	//......
	for(i=0; i<N; i++)
	{
		scanf("%s%c%c%c%d%f%s%s", &t[i].name, &t[i].gender, &t[i].age, &t[i].weight, &t[i].father, &t[i].mother);
	}
	/* codes */

}