#include <stdio.h>

void sortiraj(int *niz, int n){
	int i, j,temp;
	for(i = 0; i < (n-1); i++){
		for(j = 0; j < (n-1); j++){
			if(*(niz + j) > *(niz + j + 1)){
				temp = *(niz + j + 1);
				*(niz + j + 1) = *(niz + j);
				*(niz + j) = temp;
			}
		}
	}
}

int izbaci_kolone(int niz[100][100], int visina, int sirina, int x){
	int i, j, k, l;
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			/*BRISANJE KOLONE*/
			/*U SUŠTINI NIJE BRISANJE NEGO PREPISIVANJE DRUGIH ČLANOVA PREKO NJE I SMANJIVANJE VELIČINE*/
			if(niz[i][j] == x){
				
				for(k = j; k < sirina - 1; k++){
					for(l = 0; l < visina; l++){
						niz[l][k] = niz[l][k + 1];
					}
				}
				sirina--;
				//i--;
				j--;
			}
		}
	}
	return sirina;
}

int max(int niz[100][100], int visina, int sirina){
	int i,j, brojPonavljanja, indexNajbrojnijeg = 0,maximalno;
	int n = 0;
	int temp[10000];
	
	/*MATRICU PREBACUJEMO U JEDNODIMENZIJALNI NIZ RADI LAKŠEG MANIPULIRANJA*/
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			temp[n++] = *(*(niz+i)+j);
		}
	}
	/*NIZ SORTIRAMO RADI LAKŠEG TRAŽENJA ČLANOVA KOJI SE PONAVLJAJU*/
	
	sortiraj(temp,n);

	/*POSLIJE SORTIRANJA NIZA POTREBNO JE PRONACI ELEMENAT KOJI SE NAJVISE PUTA PONAVLJA
	U SLUCAJU DA SE NEKI ELEMENTI PONAVLJAJU JEDNAK BROJ PUTA, TREBA VRATITI ELEMENAT SA MANJOM VRIJEDNOSTI
	TO NAMA ODGOVARA JER SE TAJ ELEMENAT KOD NAS PRVI POJAVLJUJE*/
	
	//indexNajbrojnijeg;
	maximalno = temp[0];
	for(i = 0; i < n - 1; i++){
		brojPonavljanja = 1;
		if(temp[i] == temp[i + 1]){
			while(temp[i] == temp[i + 1]){
				i++;
				brojPonavljanja++;
			}
		}
		if(maximalno < brojPonavljanja){
			maximalno = brojPonavljanja;
			indexNajbrojnijeg = i;
		}
		if(temp[i] != temp[i + 1] && i != 0){
			brojPonavljanja = 1;
		}
	}
	/*printf("%d",temp[indexNajbrojnijeg]);*/
	return temp[indexNajbrojnijeg];
	
}

int main() {
	int i,j;
	int matrica[100][100];
	int visina, sirina;
	int vrijednostMax, prolaz=1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina, &visina);
	
	for(i = 0; i < visina; i++){
		printf("Unesite elemente %d. reda: ", (i+1));
		for(j = 0; j < sirina; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	printf("\n");
	while(sirina > 0){
		vrijednostMax = max(matrica, visina,sirina);
		sirina = izbaci_kolone(matrica, visina,sirina,vrijednostMax);
		if(sirina != 0){
			printf("Nakon %d. prolaza matrica glasi:\n", prolaz);
			for(i = 0; i < visina; i++){
				for(j = 0; j < sirina; j++){
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}
			prolaz++;
		}else{
			break;
		}
	}
	/*vrijednostMax = max(matrica,visina,sirina);*/
	printf("Nakon %d. prolaza matrica je prazna!", prolaz);
	return 0;
}
