#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
	int i=0, j=0, k=0, l=0, red=0, kolona=0, element=0, brojacprethodni=0, brojactrenutni=0;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) { brojactrenutni=0;
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) if(matrica[i][j]==matrica[k][l]) brojactrenutni++;
			}
		if(brojactrenutni>brojacprethodni || (brojacprethodni==brojactrenutni && matrica[i][j]<element)) {
			red=i; kolona=j;
			element=matrica[i][j]; brojacprethodni=brojactrenutni;
		}
		}
	} return matrica[red][kolona];
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n) {
	int i=0, j=0,k=0, l=0, brojac=0;
	if(sirina==1) return 0;
	for(i=0; i<visina; i++) {
		brojac=0;
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==n) {brojac++; break;}
		} 
		if(brojac>0) {
			for(k=0; k<visina; k++) {
				for(l=j; l<sirina-1; l++) {
					matrica[k][l]=matrica[k][l+1];
	
				}
			}i--; sirina--;
		} 
	} 
	return sirina;
}

int main() {
int matrica[100][100], sirina=0, visina=0, i=0, j=0, rezultat=0, koji_put=0;
printf("Unesite sirinu i visinu matrice: ");
scanf("%d %d", &sirina, &visina);
for(i=0; i<visina; i++) { 	printf("Unesite elemente %d. reda: ", i+1);
	for(j=0; j<sirina; j++) {
		scanf("%d", &matrica[i][j]);
	}
} 
rezultat=izbaci_kolone(matrica, visina, sirina, max(matrica,visina,sirina));
while (rezultat!=0) {
	koji_put++;
	printf("\nNakon %d. prolaza matrica glasi: \n", koji_put);
	for(i=0; i<visina; i++) {
		for(j=0; j<rezultat; j++) {
			printf("%5d", matrica[i][j]);
		} printf("\n");
		
	}
	
	rezultat=izbaci_kolone(matrica,visina, rezultat,max(matrica,visina,rezultat) );

} 
koji_put++;
printf("\nNakon %d. prolaza matrica je prazna!", koji_put);

	return 0;
}
