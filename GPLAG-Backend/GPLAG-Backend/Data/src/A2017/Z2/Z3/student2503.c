#include <stdio.h>

int main()
{
	int i=0,j=0,a=0,b=0,c=0,d=0,A[10][10]= {{0}},B[10][10]= {{0}},T=1;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&b,&a);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<a; i++)
		for(j=0; j<b; j++)
			scanf("%d",&A[i][j]);
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d",&d,&c);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<c; i++)
		for(j=0; j<d; j++)
			scanf("%d",&B[i][j]);
	if(a!=d || b!=c) {
		printf("NE\n");
		return 0;
	}
	for(i=0; i<a; i++)
		for(j=0; j<b; j++)
			if(A[i][j]!=B[j][a-i-1]) {
				T=0;
				break;
			}
	if(T==0) printf("NE\n");
	else printf("DA\n");
	return 0;
}