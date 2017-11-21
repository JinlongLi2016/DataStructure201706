#include <stdio.h>
#define N 10000
typedef int ElemType;
int main(int argc, char const *argv[])
{

	// ElemType A[N] = { 5, 3, 7, 4, 9 , 2, 10, 18, 28, -1, -3, 40, 36, 100, -9, 26, 33, 39, 34, 19}; // 20 elements
									  // printf("%d\n",A[19] );
	ElemType A[N];
	ElemType st[N][2]; int top = -1;
	int  range_start, range_end, i, j, pivot;
	st[++top][0] = 0; st[top][1] = N - 1;


	for(i=N-1; i>0; i--)	
	{
		A[i] = N-i;
	}
	while (top>-1) //开始快排
	{
		range_start = i = st[top][0]; range_end = j = st[top][1];
		top--;

		pivot = A[i];
		while (i<j)//开始排序[i,j]中的元素 先考虑小区间(当i j 接近的时候)
		{
			while (pivot < A[j] && i<j) 
				j--;
			if (i == j) break; //
			else{
				A[i] = A[j];
				i++;
			}

			while (pivot > A[i] && i<j) 
				i++;
			if (i >= j) break;
			else{
				A[j] = A[i]; j--;
			}
		}//while

		A[i] = pivot; // i 是指向中间节点的
		if (range_start < i - 1)
		{
			top++;
			st[top][0] = range_start; st[top][1] = i - 1;
		}
		if (i + 1 < range_end)
		{
			top++;
			st[top][0] = i + 1; st[top][1] = range_end;
		}

	}// while
	//输出结果
	for (i = 0; i < N; i++)
		printf("%d ", A[N-1]);
	return 0;
}
