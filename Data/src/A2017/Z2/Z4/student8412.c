#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[101][101],b[101][101],c[101][101],bra[1000]={0},brb[1000]={0},brc[1000]={0};
	int i,j,m,n,k=1;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	} while(m>100 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]=abs(a[i][j]);
			bra[a[i][j]]++;
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
			brb[abs(b[i][j])]++;
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&c[i][j]);
			brc[abs(c[i][j])]++;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(bra[a[i][j]]!=brb[a[i][j]] || brb[a[i][j]]!=brc[a[i][j]] || brc[a[i][j]]!=bra[a[i][j]]) k=0;
			
		}
	}
		
	if(k==0) printf("NE"); else printf("DA");
	
	return 0;
}
