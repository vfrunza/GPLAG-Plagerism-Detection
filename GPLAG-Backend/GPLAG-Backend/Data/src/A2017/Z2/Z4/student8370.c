#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int A[101][101]={},B[101][101]={},C[101][101]={};
	int brojac_Apoz[1000]={},brojac_Aneg[1000]={},brojac_Bpoz[1000]={},brojac_Bneg[1000]={},brojac_Cpoz[1000]={},brojac_Cneg[1000]={};
	int m=120,n=101;
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m>100 || n>100 || m<0 || n<0);
	int i=0,j=0;
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
			if(A[i][j]>=0)
				brojac_Apoz[A[i][j]]++;
			else
				brojac_Aneg[(A[i][j]*(-1))]++;
		}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&B[i][j]);
			if(B[i][j]>=0)
				brojac_Bpoz[B[i][j]]++;
			else
				brojac_Bneg[(B[i][j]*(-1))]++;
		}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			{
			scanf("%d",&C[i][j]);
			if(C[i][j]>=0)
				brojac_Cpoz[C[i][j]]++;
			else
				brojac_Cneg[(C[i][j]*(-1))]++;
			}
	// uporeðivanje
	int uslov=1;
	for(i=0;i<1000;i++)
	{
		if(brojac_Apoz[i]!=brojac_Bpoz[i] || brojac_Apoz[i]!=brojac_Cpoz[i] || brojac_Bpoz[i]!=brojac_Bpoz[i]) uslov=0;
		if(brojac_Aneg[i]!=brojac_Bneg[i] || brojac_Aneg[i]!=brojac_Cneg[i] || brojac_Bneg[i]!=brojac_Bneg[i]) uslov=0;
	}
	if(uslov) printf("DA");
	else printf("NE");
	return 0;
}