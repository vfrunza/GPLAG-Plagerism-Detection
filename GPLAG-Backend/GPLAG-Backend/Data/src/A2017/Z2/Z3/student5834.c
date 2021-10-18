#include <stdio.h>

int main() {
	float AMATRIX[78][78],BMATRIX[78][78];
	int sirinamatrixA,visinamatrixA,sirinamatrixB,visinamatrixB,brojac=0,i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirinamatrixA,&visinamatrixA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visinamatrixA; i++) {
		for(j=0; j<sirinamatrixA; j++) {
			scanf("%f",&AMATRIX[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirinamatrixB,&visinamatrixB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visinamatrixB; i++) {
		for(j=0; j<sirinamatrixB; j++) {
			scanf("%f",&BMATRIX[i][j]);
		}
	}
	if(sirinamatrixA==visinamatrixB && visinamatrixA==sirinamatrixB) {
		for(i=0; i<visinamatrixA; i++) {
			for(j=0; j<sirinamatrixA; j++) {
				if(BMATRIX[j][visinamatrixA-i-1]==AMATRIX[i][j]) 
				brojac++;
			}
		}
	if(brojac==sirinamatrixA*visinamatrixA) {
		printf("DA");
	}
	else {
		printf("NE");
	}
	}
	else {
		printf("NE");
	}

	return 0;
}
