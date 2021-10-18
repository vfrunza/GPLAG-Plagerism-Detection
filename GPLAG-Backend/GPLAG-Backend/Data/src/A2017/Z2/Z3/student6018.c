#include <stdio.h>

int main() {
	double A[100][100],B[100][100];
	int i=0,j=0,sira,visa,sirb,visb;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sira,&visa);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visa;i++)
	{
		for(j=0;j<sira;j++)
		{
			scanf("%lf",&A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirb,&visb);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visb;i++)
	{
		for(j=0;j<sirb;j++)
		{
			scanf("%lf",&B[i][j]);
		}
	}
	for(i=0;i<sira;i++)
	{
		for(j=0;j<visa;j++)
		{	
			if((visa!=sirb)||(visb!=sira))
			{
				printf("NE\n");
				return 0;
			}
			else if(B[i][j]!=A[visa-j-1][i])
			{
				printf("NE\n");
				return 0;
			}
		}
	}
	printf("DA\n");
	return 0;
}