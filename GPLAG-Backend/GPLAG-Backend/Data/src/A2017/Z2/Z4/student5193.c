#include <stdio.h>

int main() 
{
	int niz1[100][100],niz2[100][100],niz3[100][100];
	int m,n,k,l,i,j;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m<0 || m>100 || n<0 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&niz1[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&niz2[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&niz3[i][j]);
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			int clan=niz1[i][j];
			int broj1=0,broj2=0,broj3=0;
			for(k=0;k<m;k++)
			{
				for(l=0;l<n;l++)
				{
					if(niz1[k][l]==clan) broj1++;
					if(niz2[k][l]==clan) broj2++;
					if(niz3[k][l]==clan) broj3++;
				}
			}
			if(broj1!=broj2 || broj2!=broj3) 
			{
				printf("NE\n");
				return 1;
			}
		}
	}
	printf("DA\n");
	return 0;
}
