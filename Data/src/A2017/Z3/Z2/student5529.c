#include <stdio.h>
#include <math.h>

void zaokruzi(float *niz, int velicina){
	int i, broj;
	for (i=0; i<velicina; i++){
		broj = (int)(niz[i]*100);
		broj += 5;
		broj = broj/10;
		niz[i] = broj/10.;
	}
}

int suma_cifara(float x){
	int suma=0; 
	int broj = (int)(x*10);
	while (broj!=0){
		suma += broj%10;
		broj /= 10;
	}	
	return suma;
}

void preslozi(float *niz, int velicina, unsigned int k){
	float novi_niz[1000];
	int i, brojac = 0;
	zaokruzi(niz, velicina);
	
	for (i=0; i<velicina; i++){
		if (suma_cifara(niz[i])>k){
			novi_niz[brojac] = niz[i];
			brojac++;
		}
	}
	for (i=0; i<velicina; i++){
		if(suma_cifara(niz[i])<k){
			novi_niz[brojac] = niz[i];
			brojac++;
		}
	}
	for (i=0; i<velicina; i++)
		niz[i] = novi_niz[i];
	
	return;
}


int main() {
	float niz[1000];
	int n,i,k;
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	for (i=0; i<n; i++)
		scanf("%f", &niz[i]);
	printf("Unesite k: ");
	scanf("%d", &k);
	preslozi(niz, n, k);
	return 0;
}
