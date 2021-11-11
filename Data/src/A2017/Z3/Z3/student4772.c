#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int izbaci_cifre (int* niz1, int vel1, int* niz2, int vel2) {
	int i, j, k, l, brojcifara, cifra, pomocniNiz[500], zamjena;
	
	for (i=0; i<vel2; i++) {
		if (niz2[i]<0 || niz2[i]>9) return 0;
		for (j=i+1; j<vel2; j++) {
			if (niz2[i]==niz2[j]) return 0;
		}
	}
	
	for (i=0; i<vel1; i++) {
		zamjena=0;
		brojcifara=0;
		cifra=niz1[i];
		
		while (cifra!=0) {
			cifra=cifra/10;
			brojcifara++;
		} 

		cifra=niz1[i];
		for (j=0; j<brojcifara; j++) {
			pomocniNiz[j]=cifra%10;
			cifra=cifra/10;	
		}
	
		for (j=0; j<brojcifara; j++) {
			for (k=0; k<vel2; k++) {
				if (abs(pomocniNiz[j])==abs(niz2[k])) {
					for (l=j; l<brojcifara-1; l++) {
						pomocniNiz[l]=pomocniNiz[l+1];
					}
					zamjena=1;
					if (zamjena) {
						brojcifara--;
						j--;
						break;
					}
				}
			}
		}
		
		niz1[i]=0;
		
		if (brojcifara!=0) {
			for (j=0; j<brojcifara; j++) {
				niz1[i]+=pomocniNiz[j]*pow(10,j);
			}
		}
		
	}
	
	return 1;
}

int main() {
	int niz1 [100], niz2 [100], vel1=0, vel2=0, i;
	
	printf ("Unesite niz cijelih brojeva: ");
	for (i=0; i<100; i++) {
		scanf ("%d", &niz1[i]);
		if (niz1[i]==-1) break;
		vel1++;
	}
	
	printf ("Unesite niz cifara: ");
	for (i=0; i<100; i++) {
		scanf ("%d", &niz2[i]);
		if (niz2[i]==-1) break;
		vel2++;
	}
	
	if (izbaci_cifre(niz1, vel1, niz2, vel2)==1) {
		for (i=0; i<vel1; i++) {
			printf ("%d ", niz1[i]);
		}
	}
	
	return 0;
}
