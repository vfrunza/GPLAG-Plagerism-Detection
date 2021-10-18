#include <stdio.h>
#include <stdlib.h>

	/* Funkcija koja testira da li joj je ulazna vrijednost fibonaccijev broj */
	int if_fibonacci (int n) {
		int x=1, y=1;
		while (x<n && y<n) {
			x=x+y;
			y=y+x;
		}
		if (x==n || y==n) {
			return 1;
		}
		return 0;
	}
	
	/* Funkcija koja izbacuje fibonaccijeve brojeve iz niza */
	int izbaci (int* niz, int vel) {
		int i, j;
		for (i=0; i<vel; i++) {
			if (if_fibonacci(*(niz+i))==1) {
				for (j=i; j<vel-1; j++) {
					niz[j]=niz[j+1];
				}
				vel--;
				i--;
			}
		}
		return vel;
	}
	
	/* Funkcija koja vraca sumu cifara prethodnog clana */
	int suma_cifara (int* niz, int i) {
		int cifra, suma=0, br;
		br=*(niz+i-1);
		while (br!=0) {
			cifra=br%10;
			suma+=cifra;
			br=br/10;
		}
		suma=abs(suma);
		niz[i]=suma;
		return suma;
	}
	
	/* Funkcija koja oslobadja mjesto nakon svakog clana niza, te na to mjesto stavlja sumu cifara prethodnog clana */
	void ubaci (int* niz, int vel) {
		int i;
		for (i=vel-1; i>=0; i--) {
			*(niz+2*i)=*(niz+i);
		}
		for (i=0; i<2*vel; i++) {
			if (i%2==1) {
				suma_cifara(niz, i);
			}
			
		}
	}
	
	int main() {
		int i, nastali_niz=0, niz[20], vel=10;
		printf ("Unesite niz od 10 brojeva: ");
		for (i=0; i<vel; i++) {
			scanf ("%d", &niz[i]);
		}
		
		ubaci(niz, vel);
		nastali_niz=izbaci(niz, 2*vel);
		
		printf ("Modificirani niz glasi: ");
		for (i=0; i<nastali_niz; i++) {
			if (i==nastali_niz-1) {
				printf ("%d.", niz[i]);
			}
			else {
				printf ("%d, ", niz[i]);
			}
		}
		return 0;
	}