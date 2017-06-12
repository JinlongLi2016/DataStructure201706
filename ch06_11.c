#include <stdio.h>
#define N 5
int main(int argc, char const *argv[])
{
	int arr[5], tmp, flag, i, j, obj = 2;
	printf("enter 5 number");
	for(i=0; i<N; i++)
	{
		scanf("%d", &arr[i]);
	}
	// sort the array
	flag = 1; // 代表本轮循环有元素发生交换
	for(i=0; i<N && flag==1; i++)
	{
		flag = 0;
		for(j=0; j<N-1; j++)
		{	
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j]; arr[j] = arr[j+1];arr[j+1] = tmp;
				flag = 1;
			}
		}
	}
	for(i=0; i<N; i++)
	{
		printf("%d ", arr[i]);
	}

	//binary search the obj
	i = 0;
	j = N-1;
	while(i<=j)
	{
		if(arr[(i+j-1)/2] < obj)	i = (i+j-1)/2+1;
		else if (arr[(i+j-1)/2] > obj)	j = (i+j-1)/2-1;
		else	
			printf("found obj:%d @index %d\n", obj, (i+j-1)/2);
			break;
	}
	if(i>j)	printf("not found %d\n", obj);


	return 0;
}