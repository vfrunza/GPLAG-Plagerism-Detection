#include <stdio.h>
#include <math.h>

void zaokruzi1 (float niz[], int vel) {
	int i;
	for (i=0; i<vel; i++) {
		niz[i] = round(niz[i]*10)/10;
	}
}
int suma_proslijedjenog_broja (float broj) {
	int rezultat, cifra, novi_broj;
	rezultat = 0;
	broj*=10;
	novi_broj = (int) broj;
	if (novi_broj < 0) novi_broj= novi_broj * (-1);
	while (novi_broj > 0) {
		cifra = novi_broj % 10;
		rezultat+=cifra;
		novi_broj = novi_broj / 10;
	}
	return rezultat;
}
void preslozi (float niz[], int vel, int k) {
	zaokruzi1(niz, vel);
	int i, j; 
	float temp;
	for (i = 1; i< vel; i++) {
		j=i;
		while (j>0 && suma_proslijedjenog_broja(niz[j]) >= k && suma_proslijedjenog_broja(niz[j-1]) < k) {
			temp = niz[j];
			niz[j] = niz [j-1];
			niz[j-1] = temp;
			j--;
		}
	}
}
int main() {
	printf("Zadaća 3, Zadatak 2");
	return 0;
}
