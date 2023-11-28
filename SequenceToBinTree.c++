// 将两个二叉树遍历序列 转换为 二叉树并返回

#include <stdio.h>
typedef char ElemType;
typedef struct TreeNode *BinTree;

struct TreeNode{
	ElemType Data;
	struct TreeNode * Left;
	struct TreeNode * Right;
};

bool InSequence(char obj,char S[],int si,int num);
// 1 由先序序列和中序序列 构造二叉树
BinTree ConstructBinTreePI(char preS[],int psi,char inS[],int isi,int num)
{// preS[] inS[] contains the traversing sequence
// psi: preS[] preSequence starting index while isi means inS[] starting index
// num: the number of following elements, including(preS[psi] and inS[isi])
	BinTree T;
	if(num == 0)	return NULL;
	else if(num == 1)
	{
		T = (BinTree)malloc(sizeof(struct TreeNode));
		T->Data = preS[psi]; T->Left = T->Right = NULL;
		return T;
	}
	else if(num > 1)
	{
		int i;
		for(i = 0; i < num; i++){
			if(preS[psi] == inS[isi + i])
				break;
		}
		//构造根节点
		T = (BinTree)malloc(sizeof(struct TreeNode));
		T->Data = preS[psi];

		//先序遍历中,[psi+1, psi+i](.py format)为左子树部分; 中序遍历中,[ini, isi+i]为左子树部分
		T->Left = ConstructBinTreePI(preS, psi+1, inS, isi, i);
		//[psi+i+1]为左子树部分;[ini, isi+i+1]为左子树部分
		T->Right = ConstructBinTreePI(preS, psi+i+1, inS, isi+i+1, num - i - 1);
		return T;
	}
}

// 2 由中序序列和层序序列 构造二叉树
BinTree ConstructBinTreeLI(char levelS[],int lsi,char inS[],int isi,int num)
{
	BinTree T;
	if(num == 0)	return NULL;

	else if(num == 1)
	{
		T = (BinTree)malloc(sizeof(struct TreeNode));
		T->Data = levelS[lsi]; T->Left = T->Right = NULL;
		return T;
	}
	else
	{
		int i;
		for(i=0; i < num; i++)
				if(inS[isi + i] == levelS[lsi])
					break;
		T = (BinTree)malloc(sizeof(struct TreeNode));
		T->Data = levelS[lsi];
		// rearrange the leverS order 
		int j1, j2; j1=j2=0; j2++;
		while(j2 < num)
		{
			if(!InSequence(levelS[j2], inS, isi, i))
				j2++;
			else
			{
				char t_elem;
				t_elem = levelS[lsi + j2];
				for(int t = j1+1; t < j2; t++)
					levelS[t+1] = levelS[t];
				levelS[j1+1] = t_elem;
				j1++; j2++; //j1, j2 均向后移动一位?
			}
		}

		T->Left = ConstructBinTreeLI(levelS, lsi+1, inS, isi, i);
		T->Right = ConstructBinTreeLI(levelS, lsi+i+1, inS, isi+i+1, num-1-i);
	}
}

bool InSequence(char obj,char S[],int si,int num)
{// obj: 待查找的字符
// S: 字符串   si: starting index 
// num: the number of elements counting from si [si, si+num](.py list format)
	for(int i=0; i < num; i++)
		if(S[si + i] == obj)
			return true;
	return false;
}