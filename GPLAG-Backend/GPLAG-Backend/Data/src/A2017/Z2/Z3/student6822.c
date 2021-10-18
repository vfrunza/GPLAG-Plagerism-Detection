#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float A[100][100]={},B[100][100]={},pomocna[100][100]={};
	int m,n,mb,nb;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&n,&m);
	int i,j;
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%f",&A[i][j]);
	int tempa=0,tempb=0;
	for(i=0;i<n;i++)
	{
		for(j=m-1;j>=0;j--)
		{
			pomocna[tempa][tempb]=A[j][i];
			tempb++;
		}
	tempa++;
	tempb=0;
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&nb,&mb);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<mb;i++)
		for(j=0;j<nb;j++)
			scanf("%f",&B[i][j]);
	int uslov=1;
	
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(pomocna[i][j]!=B[i][j]) uslov=0;	
			}
	if(uslov) printf("DA");
	else printf("NE");
	return 0;
}