#include <stdio.h>
#include <math.h>

int izbaci_cifre(int niz[], int vel, int cifre[], int velCif){
	int i, j, k;

	/*Provjeri ispravnost niza cifara*/
	int cifHist[10] = {0};
	for(i = 0; i < velCif; i++){
		if(cifre[i] < 0 || cifre[i] > 9) return 0;
	}
	for(i = 0; i < velCif; i++){
		cifHist[cifre[i]]++;
	}
	for(i = 0; i < 10; i++){
		if(cifHist[i] > 1) return 0;
	}
	
	/*Izbacivanje cifara*/
	int temp;
	int brCif = 0;
	int broj[16];
	
	/*Za svaki broj niza*/
	for(i = 0; i < vel; i++){
		/*Nadji broj cifara i rastavi na cifre*/
		for(j = 0; j < 12; j++){
			broj[i] = -1;
		}
		

		temp = fabs(niz[i]);
		
		j = 0;
		brCif = 0;
		
		while(temp > 0){
			broj[j] = temp%10;
			temp /= 10;
			brCif++;
			j++;
		}
		
		/*Oznaci sa -1 one koje su u cifre nizu*/
		for(j = 0; j < brCif; j++){
			for(k = 0; k < velCif; k++){
				if(broj[j] == cifre[k]){
					broj[j] = -1;
					break;
				}
			}
		}
		
		/*Preracunaj niz[i] koristeci cifre u broj[]*/
		/*Znak broja*/
		if(niz[i] < 0) temp = -1;
		else temp = 1;
		
		niz[i] = 0;
		k = 0; /*Stepen broja*/
		
		for(j = 0; j < brCif; j++){
			if(broj[j] != -1){
				niz[i] += broj[j] * pow(10, k);
				k++;
			}
		}
		niz[i] *= temp;
	}
	
	return 1;
}

int main() {
	
	int niz[4] = {12345, 12456, 6646, 234101};
	int cifre[2] = {6, 1};
	
	izbaci_cifre(niz, 4, cifre, 2);
	
	int i;
	
	for(i = 0; i < 4; i++)
		printf("%d ", niz[i]);
	
	return 0;
}
