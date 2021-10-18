#include <stdio.h>
#include <math.h>
#define e 0.0001
int main() 
{
	int s1,v1,s2,v2,i,j;
	double niz1[100][100],niz2[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&s1,&v1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<v1;i++)
	{
		for(j=0;j<s1;j++)
		{
			scanf("%lf",&niz1[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&s2,&v2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<v2;i++)
	{
		for(j=0;j<s2;j++)
		{
			scanf("%lf",&niz2[i][j]);
		}
	}
	if(v1!=s2 || s1!=v2)
	{
		printf("NE\n");
		return 1;
	}
	else
	{
		for(i=0;i<v2;i++)
		{
			for(j=0;j<s2;j++)
			{
				if(fabs(niz1[v1-j-1][i]-niz2[i][j])>e) 
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
