#include <stdio.h>
#define MAX 1000

int main() {
	int A[MAX][MAX],B[MAX][MAX],tempp,m,n,i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
	printf("UNesite clanove matrice A: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++){
			scanf("%d",&A[i][j]);
		}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&m,&n);
	printf("UNesite clanove matrice B: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++){
			scanf("%d",&B[i][j]);
		}
		for(i=0; i<m; i++)
		for(j=i+1; j<n; j++){
			tempp=A[i][j];
			A[i][j]=A[i][n-j-1];
			A[i][n-j-1]=tempp;
		}
	return 0;
}
