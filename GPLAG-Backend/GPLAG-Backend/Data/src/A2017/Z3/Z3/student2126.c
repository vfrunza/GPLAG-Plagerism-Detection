#include <stdio.h>

int izbaci_cifre (int *niz, int vel, int *niz1, int vel1) {
	int i, j, x=0, cifra=0, k=1, y=0;
	for (i=0; i<vel1; i++) {
		if (niz1[i]<0 || niz1[i]>9) return 0;
		for (j=i+1; j<vel1; j++) {
			if (niz[i]==niz[j]) return 0;
		}
	}
	
/*	for (i=0; i<vel; i++) {
		x=niz[i];
		for (j=0; j<vel1; j++) {
			while (x!=0) {
				cifra=x%10;
				y=cifra*k;
				k*=10;
				if (cifra==niz1[j]) {
					niz[i]=niz[i]-y;
				}
			}
		}
	}*/
	
	return 1;
}

int main() {
	int brojevi[] = {12345, -12345};
int cifre[] = {3,5};
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}
