#include <stdio.h>

void max(int matrica[100][100], int visina, int sirina)
{

	int i,j;

	for(i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			if(matrica[i][j]==matrica[j][i])
				matrica[i][j]=matrica[i-1][j-1];
			j--;
			visina --;
		}
		i--;
		sirina --;
	}
}
void izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{

	int i,j;

	for(i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			if(matrica[i][j]==matrica[i][n]) {
				matrica[i][n]==matrica[i][sirina-1];
			}
		}

	}




}


int main()
{

	int i,j,sirina,visina, matrica[100][100],N;

	do {
		printf("Unesite sirinu i visinu matrice: ");
		scanf("%d %d", &sirina, &visina);
	} while((sirina<1 || sirina>100) && (visina<1 || visina>100));


	for(i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			printf("Unesite elemente %d. reda: ", i+1);
			scanf("%d", &matrica[i][j]);

		}
	}
	scanf("%d", &N);
	max(matrica[i][j], visina, sirina);
    izbaci_kolone(matrica[i][j], visina, sirina, N);
	for(i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			printf("Nakon %d. prolaza matrica glasi : %d %d",i, matrica[i][j]);

		}
	}





	return 0;
}
