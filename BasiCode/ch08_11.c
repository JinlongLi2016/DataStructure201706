#include <stdio.h>
void SalesAnalysis(int n, double( *pr)[6], int( *vo)[6], double *am);
int main(void)
{
	// define a 2d array to store the prices of three goods over the 
	// last 6 months.
	double salesPrice[3][6] = {
		,,,
	};
	double salesVolume[3][6] = {
		,,,
	};
	double salesAmount[3] = {0.0};
	int i;
	SalesAnalysis(3, salesPrice, salesVolume, salesAmount);
}

void SalesAnalysis(int n, double( *pr)[6], int( *vo)[6], double *am)
{
	int t, m;
	for(t=0; t<n; t++)
	{
		double a = 0;
		for(m=0; m<6; m++)
			a += *( *(pr + t) + m) * *( *( vo + t) + m);
		*(am + t) = a;
	}
}