// 408 2016  题 43
#include <stdio.h>
void func(int A[], int n, int A1[], int A2[]);

int main(void)
{
	int A[10] = {1, 2, 3, 7, 8, 4, 5, 6, 9, 10 }, A1[5], A2[5]
	func(A, 10, A1, A2);

	return 0;
}

void func(int A[], int n, int A1[], int A2[])
{
	int i, r = 0; int R[65536] = {0};
	
	for(i = 0; i< n; i++)
		R[A[i]]++;

	for(i = 0; i < 65536; i++ )
	{
		while(R[i] != 0)
		{
			if( r <= n / 2 -1)
			{
				A1[r] = i; r++; R[i]--;
			}
			else if( r > n / 2 -1)
			{
				A2[r - n/2 ] = i; r++; R[i]--;
			}
		}
	}
}

// 时空复杂度 O(n) & O(1)