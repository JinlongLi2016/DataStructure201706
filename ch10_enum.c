#include <stdio.h>
enum colors {RED, BLUE, GREEN};
void show(enum colors c);
int main(void)
{
	enum colors c1, c2, c3;
	for(c1=RED; c1<=GREEN; c1=(enum colors)((int)c1 + 1))
		for(c2=RED; c2<=GREEN; c2=(enum colors)((int)c2 + 1))
			for(c3=RED; c3<=GREEN; c3=(enum colors)((int)c3 + 1))
			{
				show(c1);
				show(c2);
				show(c3);
				printf("\n");
			}
	return 0;
}
void show(enum colors c)
{
	switch(c)
	{
		case RED: printf("RED"); break;
		case BLUE:	printf("Blue");	break;
		case GREEN:	printf("GREEN"); break;
	}
	//printf("\n");
}