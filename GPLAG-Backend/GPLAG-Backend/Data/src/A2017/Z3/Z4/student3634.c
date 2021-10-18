#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){
	int maxelement=matrica[0][0], maxpon = 0, niz[10000], d_niza = 0, i, j, k, br=0;
	
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			niz[d_niza]=matrica[i][j];
			d_niza++;
		}
	}
	
 	for(k = 0; k < d_niza; k++){
 		br=0;
		for(i = 0; i < visina; i++){
			for(j = 0; j < sirina; j++){
				if(matrica[i][j] == niz[k]){ 
					br++;
			}
		}
 	}
		if(br > maxpon){
			maxpon = br;
			maxelement=niz[k];
		}
		else if(br == maxpon){
			if(maxelement>niz[k]) maxelement=niz[k];
		}

	}

return maxelement;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int i, j, k, izb[100], mat[100][100], l=0, temp, z, rjesenje;
	
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			if(matrica[i][j] == N){
				izb[l]=j;
				l++;
			}
		}
	}
	
	for(i = 0; i < l; i++){
		for(j = i + 1; j < l; j++){
			if(izb[i] == izb[j]){
				for(k = j; k < l; k++){
				izb[k]=izb[k+1];
				}
				l--;
			}
		}
	}
	
	for(i = 0; i < visina; i++){
		z= 0;
		temp=1;
		for(j = 0; j < sirina; j++){
			for(k = 0; k < l; k++){
				if(izb[k]==j) temp = 0;
			}
			if(temp){
				mat[i][z]=matrica[i][j];
				z++;
			}
			temp = 1;
		}
	}
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina - l; j++){
			matrica[i][j]=mat[i][j];
		}
	}
	rjesenje = sirina - l;
	return rjesenje;
}

int main() {
	
	int i, j, sirina, visina, matrica[100][100], brojac=1, br=1;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	br = sirina;
	
	for(i = 0; i < visina; i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j = 0; j < sirina; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	sirina = izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
	while(sirina != 0){
		printf("\nNakon %d. prolaza matrica glasi: \n", brojac);
		for(i = 0; i < visina; i++){
			for(j = 0; j < sirina; j++){
				printf("%5d", matrica[i][j]);
			}
			printf("\n");
		}
		brojac++;
		sirina = izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
	}
	
	printf("\nNakon %d. prolaza matrica je prazna!", brojac);
	return 0;
}