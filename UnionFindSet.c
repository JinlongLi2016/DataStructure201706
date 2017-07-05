#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	int rank
	int parent;
}UFSTree;

//并查集的初始化
void MAKE_SET(UFSTree t[])
{
	int i;
	for(i=0; i<= N; i++)
	{
		t[i].data = i;	//该人的编号
		t[i].rank = 0;	//秩初始化为0
		t[i].parent = i;//双亲初始化为自己
	}
}

//查找一个元素所属的集合
int FIND_SET(UFSTree t[], int x)
{
	if(x != t[x].parent)
		return(FIND_SET(t, t[x].parent))
	else
		return(x);
}

// 合并两个元素所属集合
void UNION(UFSTree t[], int x, int y)
{
	x = FIND_SET(t, x);
	y = FIND_SET(t, y);		//查找 x y 所在分离树的编号
	if(t[x].rank > t[y].rank)
		t[y].parent = x;
	else
	{
		t[x].parent = y;
		if(t[x].rank == t[y].rank)
			t[y].rank ++;
	}
}