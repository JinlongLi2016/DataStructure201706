#include <stdio.h>
void SalesAnalysis(int n, double price[][6], int volume[][6], double amount[]);


int main(int argc, char const *argv[])
{
	double salesPrice[3][6] = {
		{},
		{},
		{}
	};
	double salesVolume[3][6] = {{}};

	double salesAmount[3] = {0}；
	int i;

	SalesAnalysis(3, salesPrice, salesVolume, salesAmount);
	printf("种类上半年销售总额（万元）\n");
	for(i=0; i<3; i++)
	{
		printf("%-5d%-.4f\n", i+1, salesAmount[i]/10000);
	}

	return 0;
}

void SalesAnalysis(int n, double price[][6], int volume[][6], double amount[])
{
	int t, m;
	for(t=0; t<n; t++)
	{
		double a = 0.0;
		for(m=0; m<6; m++)
			a += price[t][m] * volume[t][m];
		amount[t] = a;
	}
}