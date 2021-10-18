#include <stdio.h>
#define n 10
#define m 10

int main(){
	int i, j, k, t=1, sirinaA, visinaA, sirinaB, visinaB, A[n][m], B[n][m];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < visinaA; i++) {
		for(j = 0; j < sirinaA; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirinaB, &visinaB);
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < visinaB; i++) {
		for(j = 0; j < sirinaB; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	j=visinaA-1;
	for(i = 0; i < visinaA; i++) {
		for(k = 0; k < visinaB; k++) {
			if(A[i][k] != B[k][j]) {
				t = 0;
			}
		}
		j--;
	}
	if(t == 1) printf("DA\n");
	else if(t == 0) printf("NE\n");
	return 0;
}