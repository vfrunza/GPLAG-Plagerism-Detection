#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int velicina) {
	int i;
	for(i=0; i<velicina; i++) {
		*niz = round(*niz * 10) / 10;
		++niz;
	}
}

void preslozi(float niz[], int velicina, int k) {
	int i, j = 0, suma = 0, number = 0;
	float *first, niz1[100], niz2[100] = {0};
	zaokruzi1(niz, velicina);
	first = niz;
	for(i=velicina-1; i>=0; i--) {
		number = *niz++ * 10;
		if(number < 0) number *= -1;
		while(number>0) {
			niz1[j] = number%10;
			number/=10;
			j++;
		}
		niz1[j] = 999;
		j++;
	}
	number = 0;
	niz = first;
	for(i=0; i<j; i++) {
		if(niz1[i] == 999) {
			if(suma >= k) {
				niz2[number] = *niz;
				number++;
			}
			niz++;
			suma = 0;
		} else {
			suma+=niz1[i];
		}
	}
	niz = first;
	for(i=0; i<j; i++) {
		if(niz1[i] == 999) {
			if(suma<k) {
				niz2[number] = *niz;
				number++;
			}
			niz++;
			suma = 0;
		} else {
			suma+=niz1[i];
		}
	}
	niz = first;
	for(i=0; i<velicina; i++) {
		*niz = round(niz2[i] * 10) / 10;
		++niz;
	}
}



int main() {
	return 0;
}
