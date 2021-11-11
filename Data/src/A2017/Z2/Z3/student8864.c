#include <stdio.h>

int main() {
	int i,j,na=0,ma=0,nb,mb,matA[100][100],matB[100][100],temp=0,flag=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&na,&ma);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<na;i++)
	{
		for(j=0;j<ma;j++)
		{
			scanf("%d",&matA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&nb,&mb);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<nb;i++)
	{
		for(j=0;j<mb;j++)
		{
			scanf("%d",&matB[i][j]);
		}
	}
	/* Rotacija matrice*/
	for(i=0;i<na;i++)
	{
		for(j=i+1;j<ma;j++)
		{
			temp=matA[i][j];
			matA[i][j]=matA[j][i];
			matA[j][i]=temp;
		}
	}
	for(i=0;i<na;i++)
	{
		for(j=0;j<ma/2;j++)
		{
			temp=matA[i][j];
			matA[i][j]=matA[i][ma-1-j];
			matA[i][ma-1-j]=temp;
		}
	}
	for(i=0;i<na;i++)
	{
		for(j=0;j<ma;j++)
		{
			if(matA[i][j]!=matB[i][j])
			{
				flag=1;
			}
		}
	}
	for(i=0;i<nb;i++)
	{
		for(j=0;j<mb;j++)
		{
			if(matA[i][j]!=matB[i][j])
			{
				flag=2;
			}
		}
	}
	if(flag==1 || flag==2)
	{
		printf("NE\n");
	}
	else printf("DA\n");
	return 0;
}
