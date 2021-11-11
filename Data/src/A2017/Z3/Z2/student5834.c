#include <stdio.h>
void zaokruzi1(float niz[], int vel) {
	int i = 0, negativan = 0;
	for(i = 0; i < vel; i++) {
		niz[i] = niz [i] * 10;
		if(niz[i] < 0) {
			niz[i] = -niz[i];
			negativan = 1;
		}
		niz[i] = niz [i] + 0.5;
		niz[i] = (int) niz[i];
		niz[i] = niz[i] / 10;
		if(negativan == 1) {
			niz[i] = -niz[i];
			negativan = 0;
		}
	}
}
void preslozi(float niz[], int vel, unsigned int k) {
	int i = 0;
	int j = 0;
	int suma = 0;
	int pom[10000];
	int temp;
	int negativan = 0;
	zaokruzi1(niz, vel);
		for(i = 0; i < vel; i++) {
			niz[i] = niz[i] * 10;
		}
		for(i = 0; i < vel; i++) {
			pom[i] = niz[i];
		}
		for(i = 0; i < vel; i++) {
			if(pom[i] < 0) {
				negativan = 1;
				pom[i] = -pom[i];
			}
			temp = pom[i];
			suma = 0;
			while(temp != 0) {
				suma += temp % 10;
				temp /= 10;
			}
			if(negativan == 1) {
				negativan = 0;
				pom[i] = -pom[i];
			}
			if(suma >= k) {
				niz[j] = pom[i]/10.;
				j++;
			}
		}
		negativan = 0;
		for(i = 0; i< vel; i++) {
		if(pom[i] < 0) {
			negativan = 1;
			pom[i] = -pom[i];
		}
		temp = pom[i];
		suma = 0;
		while(temp != 0) {
			suma += temp % 10;
			temp /= 10;
			}
			if(negativan == 1)
			{
				negativan = 0;
				pom[i] = -pom[i];
			}
			if(suma < k) {
				niz[j] = pom[i]/10.;
				j++;
			}
		}
		
}

int main() {
	float niz[10000] = {13.1, 15.749999, 15.75, 9.222, 78.1};
	int k, i;
	int vel = 5;
	for(i = 0; i < vel; i++)
		printf("%g ", niz[i]);
	printf("\n");
	for(i = 0; i < vel; i++) {
		scanf("%g", &niz[i]);
	}
	printf("Unesite k: ");
	scanf("%d", &k); 
	preslozi(niz, 5, 14);
	for(i = 0; i < vel; i++) {
		printf("%g ", niz[i]);
	}
	return 0;
}
