#include <stdio.h>
#include <math.h>
#define e 0.0001

int main() {
	
	int sA, vA, sB, vB,i,j;
	double nizA[100][100],nizB[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sA,&vA);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<vA;i++)
	{
		for(j=0;j<sA;j++)
		{
			scanf("%lf", &nizA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sB,&vB);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<vB;i++)
	{
		for(j=0;j<sB;j++)
		{
			scanf("%lf", &nizB[i][j]);
		}
	}
	
	if(vA!=sB || sA!=vB)
	{
		printf("NE\n");
		return 1;
	}
	
	else
	{
		for(i=0;i<vB;i++)
		{
			for(j=0;j<sB;j++)
			{
				if(fabs(nizA[vA-j-1][i]-nizB[i][j])>e)
				{
					printf("NE\n");
					return 1;
				}
			}
		}
		
		
	}
	
	printf("DA\n");
	return 0;
}
