// 1 建堆(make heap)
// 2 选择最大(小) 元素
// 3 再调整堆(sift_down)

#include <stdio.h>
#define N 10
typedef int ElemType;

void make_heap(ElemType *, int );
void sift_down(ElemType *A, int p, int n);
int main(void)
{
	ElemType A[N+1] = { -1, 3, 5, 2, 1, 7, 4, 8, 9,0, 11 };
	int i = N / 2, sorted_i = N;
	make_heap(A, 10); // construct a heap

	while(sorted_i) // iterate the array, find the smallest elems
	{
		A[0] = A[1]; A[1] = A[sorted_i]; A[sorted_i] = A[0];
		sorted_i--;
		sift_down(A, 1, sorted_i);
	}
	
	//output the elements
	for (i = 0; i<N; i++)
		printf("%d\n", A[i]);

	return 0;
}

void make_heap(ElemType *A, int n)
{
	int i = n / 2, son, t, p;
	while (i > 0)
	{
		// p = i;
		// son = 2 * p;

		// while (son <= n)
		// {
		// 	if (son < n && A[son + 1] < A[son])
		// 		son = son + 1;
		// 	if (A[p] > A[son])
		// 	{
		// 		t = A[p]; A[p] = A[son]; A[son] = t;
		// 	}
		// 	p = son; son = 2 * p;
		// }

		// i--;
		//*** the above sentences equal to the following:
		sift_down(A, i--, n);
	}
}

void sift_down_small(ElemType *A, int p, int n)
{//小跟堆
	int  t, son; 
	while(p * 2 <= n)
	{
		son = 2*p;
		if(son<n && A[son+1] < A[son])
			son++;
		
		if(A[p] > A[son])
		{
			t = A[p]; A[p] = A[son]; A[son] = t;
		}
		p = son;
	}
}
void sift_down(ElemType *A, int p, int n)
{//大根堆
	int son, t;
	while(2*p <= n)
	{
		son = 2*p;
		if(son < n && A[son+1] > A[son])
			son++;
		if(A[p] < A[son])
		{
			t = A[p]; A[p] = A[son]; A[son] = t;
		}
		p = son;

	}
}