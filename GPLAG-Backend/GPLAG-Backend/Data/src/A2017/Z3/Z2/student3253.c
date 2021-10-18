#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int vel)
{
	int pom, pom_1, pom_2, i;
	int predznak;
	float broj;
	float pom_3;
	for(i=0; i<vel; i++){
		broj = niz[i];
		predznak = broj < 0 ? -1 : 1;
		/*
		if (broj < 0) {
			predznak = -1;
		} else {
			prednzak = 1;
		}
		*/
		broj = fabsf(broj);
		pom = broj * 100;
		pom_1 = pom + 5;
		pom_2 = pom_1 / 10;
		pom_3 = pom_2 / 10.;
		niz[i] = predznak * pom_3;
	}
}

int suma_cifara(float broj)
{
	int n;
	int suma;
	int cifra;
	suma = 0;
	n = (int) (fabsf(broj)*10);
	while(n!=0){
		cifra = n%10;
		suma += cifra;
		n = n/10;
	} 
	return suma;
}


void preslozi(float niz[], int vel, int k)
{
	int i, j;
	float temp;
	zaokruzi1(niz, vel);
	for (i=0; i<vel; i++) {
		if (suma_cifara(niz[i]) >= k) {
			for (j=i-1; j>=0; j--) {
				if (suma_cifara(niz[j]) >= k) {
					break;
				} else {
					temp = niz[j+1];
					niz[j+1] = niz[j];
					niz[j] = temp;
				}
			}
		}
	}
	
}

int main() {
	float niz[] = {13.1, 15.749999, 15.75, 9.222, 78.1};
 	int vel = 5;
	int i;
	int suma;
	preslozi(niz, vel, 14);
	for (i=0; i<vel; i++) {
		printf("%g ", niz[i]);
	}

	return 0;
}
