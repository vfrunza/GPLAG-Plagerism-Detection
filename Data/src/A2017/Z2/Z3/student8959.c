#include <stdio.h>
#include <math.h>
#define epsilon 0.001

int main() {
	int m1,m2,n1,n2,i,j,logicki=0;
	double matA[101][101];
	double matB[101][101];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m1,&n1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		scanf("%lf",&matA[i][j]);
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&m2,&n2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<n2;i++)
	{
		for(j=0;j<m2;j++)
		scanf("%lf",&matB[i][j]);
	}
	if(m1==n2 && n1==m2)
	{
		for(i=0;i<n1;i++)
		{
			for(j=0;j<m1;j++)
			if(fabs(matA[i][j]-matB[j][m2-1-i])>epsilon)
			{
			printf("NE\n");
			return 1;
			}
			else logicki=1;
	}	
	}
	else printf("NE\n");
	if(logicki==1) printf ("DA\n");
	return 0;
}
