#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sumaCifara(int x){
	int zrtva = abs(x), duzina = 0,i, djel;
	int suma  = 0;
	while (zrtva > 0) {
		zrtva /= 10;
		duzina++;
	}
	zrtva = abs(x);
	djel = 10;
	for(i = 0; i < duzina; i++){
		suma += (zrtva % djel) / (djel/10);
		djel *= 10;
	}
	return suma;
}

void kopiraj(float *niz1, float *niz2, int n){
	int i;
	for(i = 0; i < n; i++){
		*(niz2 + i) = *(niz1 + i);
	}
}

void zaokruzi1(float *niz, int n){
	int i;
	/*Množimo svaki član sa 10*/
	for(i = 0; i < n; i++){
		*(niz + i) = *(niz + i)*10;
	}
	/*Zaokružujemo svaki član na jednu decimalu*/
	for(i = 0; i < n; i++){
		*(niz + i) = round(*(niz + i));
	}
	/* Dijelimo svaki član sa 10*/
	for(i = 0; i < n; i++){
		*(niz+ i) = *(niz + i)/10;
	}
}

void preslozi(float *niz, int n, int k){
	int i,j,c = 0;
	int temp[100];
	int indexi[100];
	float lazni[100];
	int bol = 1;
	zaokruzi1(niz, n);
	/*UBACIVANJE FLOAT VRIJEDNOSTI U INT VRIJEDNOSTI RADI IZRACUNAVANJA SUME CIFARA*/
	for(i = 0;i < n; i++){
		temp[i] = round(*(niz + i)*10);
		if(sumaCifara(temp[i]) >= k){
			indexi[c++] = i;
			//printf("%d", i);
		}
	}
	/*MIJENJANJE CIFARA*/
	for(i = 0; i < n; i++){
		if(i < c){
			lazni[i] = (temp[indexi[i]])/10.0;
		}else{
			/*NIJEDAN TRENUTNI INDEX i - c, ne smije da se poklapa sa elementima iz indexa*/
			for(j = 0; j < c; j++){
				if((i-c) == indexi[j]){
					bol = 0;
					if((i-c + 1) < n){
						lazni[i] = (temp[i-c+1])/10.0;
					}
					break;
				}
			}
			if(bol){
				lazni[i] = (temp[i-c])/10.0;
			}
		}
	}
	kopiraj(lazni, niz, n);
}


int main() {
	/*...*/	
    return 0;
}
