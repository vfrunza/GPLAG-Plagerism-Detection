#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zaokruzi1(float niz[], int vel) {
	while (vel > 0){
		*niz = roundf(*niz*10)/10.;
		niz++;
		vel--;
	}
}

int suma_cifara(int x) {
	int suma = 0;
	while (x != 0) {
		suma += x % 10;
		x /= 10;
	}
	return abs(suma);
}

void preslozi(float niz[], int vel, int k) {
	int i, j, n = 0;
	float temp;
	zaokruzi1(niz, vel);
	for (i=0; i<vel-n; i++) {
		if (suma_cifara((int)(niz[i]*10)) < k) {
			temp = niz[i];
			for (j=i+1; j<vel; j++)
				niz[j-1] = niz[j];
			niz[j-1] = temp;
			i--; n++;
		}
	}
}

int main() {
	int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 0.5);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}
