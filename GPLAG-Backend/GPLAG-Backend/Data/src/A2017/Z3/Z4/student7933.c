#include <stdio.h>

/*Radi, ne diraj, al' sad fkt*/
int max(int matrica[100][100], int visina, int sirina){
	int niz[10000];
	int i, j, k = 0;
	
	/*Matrica u niz*/
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			niz[k] = matrica[i][j];
			k++;
		}
	}
	
	/*Sort*/
	int idx;
	int temp;
	for(i = 0; i < k; i++){
		idx = i;
		for(j = i+1; j < k; j++){
			if(niz[j] > niz[idx])
				idx = j;
		}
		temp = niz[i];
		niz[i] = niz[idx];
		niz[idx] = temp;
	}
	
	/*Count*/
	int broj = niz[0];
	int ponavljanja = 1;
	int maxPonavljanja = 1;
	
	for(i = 1; i < k; i++){
		if(niz[i] == niz[i-1]){
			ponavljanja++;
		}else{
			if(ponavljanja >= maxPonavljanja){
				maxPonavljanja = ponavljanja;
				broj = niz[i-1];
			}
			ponavljanja = 1;
		}
	}
	if(ponavljanja >= maxPonavljanja){
		maxPonavljanja = ponavljanja;
		broj = niz[k-1];
	}
	
	return broj;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n){
	int i, j;
	int brKol = sirina; 
	int idx = -1;
	
	while(1){
		idx = -1;
		
		/*Find first column with n*/
		for(j = 0; j < brKol; j++){
			for(i = 0; i < visina; i++){
				if(matrica[i][j] == n){
					idx = j;
					break;
				}
			}
			if(idx != -1) break;
		}
		
		/*If no found, exit the main loop*/
		if(idx == -1)
			break;
		
		/*If found, overwrite the idx-th column and reduce the column count*/
		for(j = idx; j < brKol-1; j++){
			for(i = 0; i < visina; i++){
				matrica[i][j] = matrica[i][j+1];
			}
		}
		
		brKol--;
	}
	
	return brKol;
}

int main() {
	
	int matrica[100][100];
	int sirina, visina;
	int i, j;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	
	for(i = 0; i < visina; i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j = 0; j < sirina; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	
	int kol = sirina;
	int prolaz = 1;
	int broj;
	
	while(kol > 0){
		broj = max(matrica, visina, kol);
		kol = izbaci_kolone(matrica, visina, kol, broj);
		
		if(kol == 0){
			printf("\nNakon %d. prolaza matrica je prazna!", prolaz);
			break;
		}
		
		printf("\nNakon %d. prolaza matrica glasi:\n", prolaz);
		for(i = 0; i < visina; i++){
			for(j = 0; j < kol; j++){
				printf("%5d", matrica[i][j]);
			}
			printf("\n");
		}
		
		prolaz++;
	}
	
	return 0;
}
