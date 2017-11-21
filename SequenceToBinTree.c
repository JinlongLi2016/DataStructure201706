// 将两个二叉树遍历序列 转换为 二叉树并返回



// 1 由先序序列和中序序列 构造二叉树
BinTree ConstructBinTree(char preS[], psi, inS[], isi, num)
{// preS[] inS[] contains the traversing sequence
// psi: preS[] preSequence starting index while isi means inS[] starting index
// num: the number of following elements 
	if(num == 0)	return NULL;
	else if(num == 1)
	{
		T = (BinTree)malloc(sizeof(TreeNode));
		T->data = preS[psi]; T->Left = T->Right = NULL;
		return T;
	}
	else if(num > 1)
	{
		for(int i = 0; i < num; i++){
			if(preS[psi] == inS[isi + i])
				break;
		}
		T = (BinTree)malloc(sizeof(TreeNode));
		T->Data = preS[psi];
		T->Left = ConstructBinTree(preS, psi+1, inS, isi, i);//这里有点问题i or i-1
		T->Right = ConstructBinTree(preS, psi+i+1， inS, isi+i+1, num - i);
		return T;
	}
}

// 2 由中序序列和层序序列 构造二叉树
BinTree ConstructBinTree(leverlS, lsi, inS, isi, num)
{
	if(num == 0)	return NULL;
	else if(num == 1)
	{
		T = (BinTree)malloc(sizeof(TreeNode));
		T->data = preS[psi]; T->Left = T->Right = NULL;
		return T;
	}
	else
		for(int i=0; i < num; i++)
			if(inS[isi + i] == leverlS[lsi])
				break
		T = (BinTree)malloc(sizeof(TreeNode));
		T->Data = leverlS[lsi];
		// re-organize the leverS 
		int j1, j2; j1=j2=0; j2++;
		while(j2 < num)
		{
			if(!InSequence(leverlS[j2], inS, isi, i))
				j2++;
			else
			{
				t_elem = leverlS[lsi + j2];
				for(t = j1+1; t < j2; t++)
					leverlS[t+1] = leverlS[t];
				leverlS[j1+1] = t_elem;
				j1++; j2++; //j1, j2 均向后移动一位?
			}
		}

		T->Left = ConstructBinTree(leverS, lsi+1, inS, isi, i);
		T->Right = ConstructBinTree(leverS, lsi+i+1, inS, isi+i+1, num-1-i);
}