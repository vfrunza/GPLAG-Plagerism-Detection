#include <stdio.h>
int main(){
	int n, m;
	int i, j;
	printf("Unesite sirinu i visinu matrice:");
	scanf(" %d %d", &m, &n);
	printf("Unesite clanove matrice :");
	int A[100][100];
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
		scanf("%d", &(A[i][j]));
		}
	}
		int n2, m2;
	printf("Unesite sirinu i visinu matrice:");
	scanf(" %d %d", &m2, &n2);
	printf("Unesite clanov matrice :");
	int B[100][100];
	for(i=0; i<n2; i++){
		for(j=0; j<m2; j++){
		scanf("%d", &(B[i][j]));
		}
	}
	if(dim razl matrice su razl)
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(A[i][j] != B[i][j]) nmatrica razlicite
			
		}
	}
	
	return 0;
}