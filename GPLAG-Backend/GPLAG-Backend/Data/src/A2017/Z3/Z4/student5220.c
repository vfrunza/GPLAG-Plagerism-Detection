#include <stdio.h>


int max(int matrica[100][100], int visina, int sirina){
	int ponavljanje[100][100];
	int i, j, m, n;
	int brojac;
	
	for (i=0; i<visina; i++){
		for (j=0; j<sirina; j++){
			brojac=0; 
			for (m=0; m<visina; m++){
				for (n=0; n<sirina; n++){
					if (matrica[i][j] == matrica[m][n]){
						brojac++;
					}
				}
			}
			ponavljanje[i][j] = brojac;
		}
	}
	
	
	int max, min;
	max = ponavljanje[0][0];
	min = matrica[0][0];
	
	
	for (i=0; i<visina; i++){
		for (j=0; j<sirina; j++){
			if (ponavljanje[i][j] > max){
				max = ponavljanje[i][j];
				min = matrica[i][j];
			}
			if(ponavljanje[i][j] == max  &&  matrica[i][j] < min){
				min = matrica[i][j];
			}
		}
	}
	
	
	return min;
}



int main() {
	int sirina, visina, matrica[100][100], i, j, prolaz=1;

	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &sirina, &visina);
	
	for (i=0; i<visina; i++){
		printf ("Unesite elemente %d. reda: ", i+1);
		//max(matrica[100][100], visina, sirina);
		for (j=0; j<sirina; j++){
			scanf ("%d", &matrica[i][j]);
		}
	}
	
	
	do {
		if (sirina == 0){
			break;
		}
		printf ("\nNakon %d. prolaza matrica glasi:\n", prolaz);
		for (i=0; i<visina; i++){
			for (j=0; j<sirina; j++){
				printf ("%5d", matrica[i][j]);
			}
			printf ("\n");
		}
		prolaz++;
	} while (sirina > 0);


	printf ("\nNakon %d. prolaza matrica je prazna!", prolaz);
	
	return 0;
}
