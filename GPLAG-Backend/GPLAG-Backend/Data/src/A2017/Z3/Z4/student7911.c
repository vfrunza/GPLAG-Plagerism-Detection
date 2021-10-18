#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){
	int i, j, k, maxBrojac, minVrijednost;
	int novi[10000] = {0}, veln = 0, brojaci[10000] = {0}, velb = 0;
	
	for (i=0; i<visina; i++){
		for (j=0; j<sirina; j++){
			novi[veln] = matrica[i][j];
			veln++;
		}	
	}
	
	for (i=0; i<veln; i++) {
		for (j=i+1; j<veln; j++) {
			if (novi[i] == novi[j]) {
				brojaci[i]++;
				
				for (k=j; k<veln-1; k++) {
					novi[k] = novi[k+1];
				}	
				
				veln--;
				j--;
			}
		}
		velb++;
	}
	
	minVrijednost = novi[0];
	maxBrojac = brojaci[0];
	for (i=0; i<velb; i++) {
		if (brojaci[i] > maxBrojac) {
			maxBrojac = brojaci[i];
			minVrijednost = novi[i];
		}
		else if (maxBrojac == brojaci[i] && minVrijednost > novi[i]) {
			maxBrojac = brojaci[i];
			minVrijednost = novi[i];
		}
	}
	return minVrijednost;
}

int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N) {
	int i, j, k, l;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[i][j] == N) {
				for (l=0; l<visina; l++) {
					for (k=j; k<sirina-1; k++) {
						matrica[l][k] = matrica[l][k+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}


int main() {
	int i, j, k, l, matrica[100][100], sirina, visina, maks;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for(i=0; i<visina; i++){
		printf("Unesite elemente %d. reda: ", i+1);
			for(j=0; j<sirina; j++)
				scanf("%d",&matrica[i][j]);
		}
		printf ("\n");
		
		i=0;
		while (sirina = izbaci_kolone(matrica,visina,sirina, max(matrica,visina,sirina))) {
			printf("Nakon %d. prolaza matrica glasi:\n",i+1);
				for(k=0;k<visina; k++){
					for(l=0; l<sirina; l++){
						printf("%5d", matrica[k][l]);
					}
					printf("\n");
				}	
				printf("\n");
				i++;
		}
		
		printf("Nakon %d. prolaza matrica je prazna!",i+1);
		
	return 0;
}
