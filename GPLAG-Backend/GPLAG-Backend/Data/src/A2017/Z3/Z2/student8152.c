#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zaokruzi1(float niz[], int vel) {
	
	int i = 0;
	
	for(i = 0; i < vel; i++) {
		
		niz[i] *= 10;
		if(niz[i] >= 0) niz[i] += 0.5;
		else niz[i] -= 0.5;
		niz[i] = (int)niz[i];
		niz[i] /= 10;
		
		
	}
	
}

int saberiCifre(float x) {
	
	int cifra;
	int rez = 0;
	
	x *= 10;
	int broj = (int)x;
	broj = abs(broj);
	
	while( broj > 0 ) {
 	
 		cifra = broj % 10;
 		broj /= 10;
 		rez += cifra;
 	
 	}	
 	
 	return rez;
 
}

void preslozi(float niz[], int vel, int k) {
	
	int i = 0, j = 0;

	float niz2[5];
	
	zaokruzi1(niz, vel);
	
	for(i = 0; i < vel; i++) {
		
		if(saberiCifre(niz[i]) >= k) {
			
			niz2[j] = niz[i];
			j++;
			
		} 
	}
	
	for(i = 0; i < vel; i++) {
		
		if(saberiCifre(niz[i]) < k) {
			
			niz2[j] = niz[i];
			j++;
			
		} 
	}
	
	for(i = 0; i < vel; i++) {
		
		niz[i] = niz2[i];
	}
	

	
}



int main() {
	
	int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	
	return 0;
}
