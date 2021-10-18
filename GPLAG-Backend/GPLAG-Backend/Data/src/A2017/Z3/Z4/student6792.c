#include <stdio.h>

int main() {
	int i,j,mat[100][100], visina,sirina;
	printf("Unesite visinu i sirinu matrice: ");
	scanf("%d %d", &visina,&sirina);
	for(i=0;i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0;j<sirina;j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i=0;)
	return 0;
}
