#include <stdio.h>
int main() {
	int n,m,a[100][100],b[100][100],c[100][100],i,j,brojacb[1000]={0},brojacbn[1000]={0},brojaccn[1000]={0},brojacc[1000]={0},k,s,h,hh;
	do
	{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	}
	while (n<0 || m<0 || n>100 || m>100);
	printf("Unesite clanove matrice A: ");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			for (k=0;k<m;k++)
			{for (s=0; s<n; s++)
			{
				h=0;
				hh=0;
				if (b[i][j]==a[k][s]) {
					
						if (b[i][j]>=0) {
						brojacb[b[i][j]]++;}
					
					else {
						h=-1*b[i][j];
						brojacbn[h]++;
					}
				}
				if (c[i][j]==a[k][s]) {
					if (c[i][j]>=0) {
						brojacc[c[i][j]]++;
					} else {
						hh=-1*c[i][j];
						brojaccn[hh]++;
			
					}
				}
			}
			}
			}
			}
			for (i=0; i<1000; i++)
			{
				if (brojacb[i]!=brojacc[i] || brojacbn[i]!=brojaccn[i]) {
					printf("NE\n");
					goto n;
				}
			
			}
			if (i==1000) printf("DA\n");
			n:
		
	return 0;
}
