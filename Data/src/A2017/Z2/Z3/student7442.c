#include <stdio.h>
#include <math.h>
#define eps 0.0001

int main() {
	int a_n, a_m, b_n, b_m;
	int i, j, brojac=0;
	float A[100][100];
	float B[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	do
	{
		scanf("%d %d", &a_n, &a_m);
	}while( (a_n<=0 || a_n>100) && (a_m<=0 || a_m>100));
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<a_m;i++)
	{
		for(j=0;j<a_n;j++)
		{
			scanf("%f", &A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	do
	{
		scanf("%d %d", &b_n, &b_m);
	}while( (b_n<=0 || b_n>100) && (b_m<=0 || b_m>100));
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<b_m;i++)
	{
		for(j=0;j<b_n;j++)
		{
			scanf("%f", &B[i][j]);
		}
	}
	

	if(a_m!=b_n || a_n!=b_m) 
	{
		printf("NE\n");
		return 0;
	}
	
	int br=a_m;
	for(i=0;i<a_n; i++)
	{
		for(j=a_m-1; j>=0; j--)
		{
			brojac++;
			br=fabs(j-a_m+1);
			if(fabs(A[j][i] - B[i][br])>eps)
			{
				printf("NE\n");
				return 0;
			}
			br--;
		}
		brojac=0;
	}
	printf("DA\n");
	
	return 0;
}
