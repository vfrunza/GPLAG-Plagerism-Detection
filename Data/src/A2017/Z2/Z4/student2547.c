#include <stdio.h>

int main() {
	int n,m,i,j,matA[100][100],matB[100][100],matC[100][100],countA=0,countB=0,countC=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&n,&m);
	}while(n>100 || m>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&matA[i][j]);
		}
	}
	/*printf("Unesite clanove matrice B: ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&matB[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&matC[i][j]);
		}
	}*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matA[i][j]==matA[j][i])
			{
				countA++;
			}
		}
	}
	printf("count=%d",count);
	return 0;
}
