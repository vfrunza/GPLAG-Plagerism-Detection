#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int izbaci_cifre (int brojevi[], int vel1, int cifre[], int vel2) {
	int i, j, a, k, b, s, izbacuje;
	for (i=0; i<vel2; i++) {
		if (cifre[i]<0 || cifre[i]>9) return 0;
		for (j=i+1; j<vel2; j++) {
			if (cifre[i]==cifre[j]) return 0;
		}
	}
	for (i=0; i<vel1; i++) {
		/* Svaki clan niza postavljamo na promjenjivu kako ne bismo mijenjali njihovu vrijednost: */
		b=brojevi[i];
		s=0;
		k=0;
		do {
			izbacuje=0;
			/* Svaki clan niza brojevi razlazemo na cifre: */
			a=b%10;
			/* Ispitujemo da li cifre drugog niza odgovaraju ciframa niza brojevi: */
			for (j=0; j<vel2; j++) {
				if (abs(a)==cifre[j]) {
					izbacuje=1;
				}
			}
			/* Ukoliko ne odgovaraju, na promjenjivu s dodajemo vrijednost desetice cifre a u originalnom nizu brojevi: */
			if (izbacuje==0) {
				s+=a*pow(10, k);
				k++;
			}
			b/=10;
			/* Ukoliko neka od cifara odgovara trazenoj cifri, vrijednost i-tog clana se mijenja: */
			brojevi[i]=s;
		} while (b!=0);
	}
	return 1;
}

int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
