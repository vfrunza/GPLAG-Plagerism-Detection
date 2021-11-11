#include <stdio.h>

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{
	int i,j;
	for(i=0; i<vel2; i++) {
		if(niz2[i]<0 || niz2[i]>9) return 0;
		for(j=0; j<i; j++) {
			if(niz2[i]==niz2[j])
				return 0;
		}
	}
	for(i=0; i<vel1; i++) {
		int broj=niz1[i];
		int izbaceni=0,negativan=0,okrenut=0;
		if(broj<0) {
			broj=-broj;
			negativan=1;
		}
		do {
			int cifra=broj%10;
			int jednaki=0;
			broj=broj/10;
			for(j=0; j<vel2; j++) {
				if(cifra==niz2[j]) {
					jednaki=1;
				}
			}
			if(jednaki==0)
				izbaceni=izbaceni*10+cifra;
		} while(broj>0);

		broj=izbaceni;
		do {
			int cifra=broj%10;
			broj=broj/10;
			okrenut=okrenut*10+cifra;
		} while(broj>0);

		if(negativan==1) okrenut=-okrenut;
		niz1[i]=okrenut;
	}

	return 1;
}

int main()
{
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
