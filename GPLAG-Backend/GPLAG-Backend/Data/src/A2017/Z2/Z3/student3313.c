#include <stdio.h>

int main()
{
	int sirinaA, visinaA, sirinaB, visinaB,i,j;
	int jednake = 1;
	int A[100][100];
	int B[100][100];
	int C[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visinaA; i++) {
		for(j=0; j<sirinaA; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirinaB, &visinaB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visinaB; i++) {
		for(j=0; j<sirinaB; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	if(sirinaA != visinaB || visinaA != sirinaB) {
		jednake = 0;
		printf("NE");
		return 0;
	}

	for(i=0; i<sirinaA; i++){
		for(j=0; j<visinaA; j++){
			C[i][j] = A[visinaA-j-1][i];
		}
	}
	
	for(i=0; i<sirinaA; i++){
		for(j=0; j<visinaA; j++){
			if(C[i][j] != B[i][j]){
				jednake = 0;
				break;
			}
		}
		if(!jednake) break;
	}

	if(jednake) printf("DA");
	else printf("NE");

	return 0;
}
