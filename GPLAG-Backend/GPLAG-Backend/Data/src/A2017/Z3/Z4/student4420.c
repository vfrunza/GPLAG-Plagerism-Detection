#include <stdio.h>

int broj_ponavljanja(int broj, int matrica[100][100], int visina, int sirina){
	int brojac=0, i, j; 
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++) {
			if(broj == matrica[i][j]) brojac++; 
		}
	}
	return brojac; 
}



int max(int matrica[100][100], int visina, int sirina){
	int i, j; 
	int max_ponavljanje=0; 
	int vrijednost= matrica[0][0]; 

	for(i=0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			int tmp = broj_ponavljanja(matrica[i][j], matrica, visina, sirina);
			if(max_ponavljanje == tmp && vrijednost > matrica[i][j]) vrijednost = matrica[i][j]; 
			if (max_ponavljanje < tmp){ max_ponavljanje=tmp; 
			vrijednost= matrica[i][j]; 
			}
		}
	}

	return vrijednost; 
}
void izbaci_kolonu(int matrica[100][100], int visina, int sirina, int broj_kolone){
	int i, j; 
	for(i = 0; i < visina; i++){
		for(j=broj_kolone-1; j < sirina; j++){
		matrica[i][j] = matrica[i][j+1]; 
		}
	}
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int i, j; 
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			if(matrica[i][j] == N) {
				izbaci_kolonu(matrica, visina, sirina, j+1); 
				sirina--; 
				i=0; j=0; 
			}
			
		}
	}
	return sirina; 
}

void ispisi(int matrica[100][100], int visina, int sirina){
	int i, j; 
	for(i=0; i < visina; i++){
		for(j=0; j < sirina; j++) printf("%5d", matrica[i][j]);
		printf("\n"); 
}
}


int main(){
int matrica[100][100]; 
int visina, sirina, i, j; 
printf("Unesite sirinu i visinu matrice: ");
scanf("%d %d", &sirina, &visina);

for(i=0; i < visina; i++){
	printf("Unesite elemente %d. reda: ", i+1); 
	for(j=0; j < sirina; j++){
		scanf("%d", &matrica[i][j]); 
	}
}
int brojac, maks; 
	brojac = 1; 
	printf("\n"); 
while(sirina > 0){
	if(sirina > 1){
	printf("Nakon %d. prolaza matrica glasi:\n", brojac); }
	 maks = max(matrica, visina, sirina); 
	
	sirina = izbaci_kolone(matrica, visina, sirina, maks); 
	 ispisi(matrica, visina, sirina); 
	 brojac++; 
}
brojac--; 
printf("Nakon %d. prolaza matrica je prazna!", brojac);
return 0;     
}