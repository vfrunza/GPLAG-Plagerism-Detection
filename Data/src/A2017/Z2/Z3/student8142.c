#include <stdio.h>
#include <math.h>
#define E 0.0001

int main() {
	
	int l1,l2,h1,h2;
	double niz1[100][100],niz2[100][100];
	int i,j;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &l1,&h1);
	printf("Unesite clanove matrice A: ");
	
	for (i = 0; i < h1; i++) {
		for(j = 0; j < l1; j++)
		{
			scanf("%lf", &niz1[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &l2,&h2);	
	printf("Unesite clanove matrice B: ");
	
	for (i = 0; i < h2; i++) {
		for(j = 0; j < l2; j++)
		{
			scanf("%lf", &niz2[i][j]);
		}
	}

	if(h1!=l2 || l1!=h2)
	{
		printf("NE\n");
		return 1;
	}
	else
	{
		for(i = 0; i < h2; i++)
		{
			for(j = 0; j < l2; j++)
			{
				if(fabs(niz1[h1-j-1][i]-niz2[i][j]) > E) 
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
