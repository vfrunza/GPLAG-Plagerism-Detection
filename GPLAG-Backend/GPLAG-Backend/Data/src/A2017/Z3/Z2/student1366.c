#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int velicina) {
	float temp;
	int i;
	for (i=0; i<velicina; i++) { 
		niz[i]=niz[i]*10;
		temp=round(niz[i]);
		niz[i]=temp/10;
	}
}

void preslozi(float niz[], int velicina, int k) {
	zaokruzi1(niz, velicina);
	int i, j, cifra, sumaCifara, temp2, brojacPromjena;
	float temp, temp3;
	brojacPromjena=0; 
	for (i=0; i<velicina; i++) {
		temp=niz[i]*10; 
		temp2=(int)round(temp); // Dvije temporalne varijable koje preuzimaju vrijednost clana niza i pretvaraju ga u cijeli broj
		if (temp2<0) // Ako je clan negativan, da bi se moglo raditi sa ciframa, broj se pretvara u pozitivan, pa ce se pred kraj funkcije opet pretvoriti u negativan
			temp2*=-1;
		sumaCifara=0;
		while (temp2!=0) {
			// Algoritam za racunanje cifara sume u broju
			cifra=temp2%10;
			sumaCifara+=cifra;
			temp2=temp2/10;
		} 
		if (sumaCifara>=k) {
			// Algoritam za preslaganje niza uz očuvanje poretka
			temp3=niz[i];
			for (j=i; j>brojacPromjena; j--) {
				niz[j]=niz[j-1];
			}
			if (niz[brojacPromjena]!=temp3)
				i--; // Da bi se izbjegle beskonacne petlje u slucajevima kada broj nakon preslaganja ostane na istom mjestu
			niz[brojacPromjena]=temp3; 
			brojacPromjena++; // brojacPromjena je varijabla koja se koristi da se zna koliko elemenata na pocetku niza je "na svom mjestu", te da se ti elemente ne diraju vise
		} 
	}
}

int main() {
	float niz[100];
	int velicina, k, i;
	printf("Unesite broj k: ");
	scanf("%d", &k);
	printf("Unesite velicinu niza: ");
	scanf("%d", &velicina);
	printf("Unesite niz: ");
	for (i=0; i<velicina; i++)
		scanf("%lf", &niz[i]);
	zaokruzi1(niz, velicina);
	printf("Zaokruzeni niz: ");
	for (i=0; i<velicina; i++)
		printf("%f ", niz[i]);
	preslozi(niz, velicina, k);
	printf("\nPreslozeni niz: ");
	for (i=0; i<velicina; i++)
		printf("%f ", niz[i]);
	return 0;
}
