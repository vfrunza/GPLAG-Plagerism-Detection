#include <stdio.h>

	/* Funkcija koje testira da li joj je ulazna vrijednost prost broj */
	int if_prost (int broj) {
		int i;
		i=0;
		for (i=2; i<broj; i++) {
			if (broj%i==0) {
				return 0;
			}
		}
		return 1;
	} 
	
	/* Funkcija koja vraca sljedeci prost broj */
	/* Staticku varijablu koristimo jer ne zelimo da nam funkcija vraca uvijek prvi prost broj, dakle 2 */
	/* Zelimo da nam funkcija vraca sljedeci prost broj, te iz tog razloga mora da "zapamti" vrijednost varijable n */
	int daj_prost() {
		static int n=1;
		n++;
		while (if_prost(n)==0) {
			n++;
		}
		return n;
	}
	
	/* Funkcija koja racuna sumu prostih brojeva koji se nalaze izmedju A i B */
	int suma_prostih (int A, int B) {
		int broj2=daj_prost();
		int suma;
		suma=0;
		
		while (broj2<=A) {
			broj2=daj_prost();
		}
		
		while (broj2<B) {
			suma+=broj2;
			broj2=daj_prost();
		}
		return suma;
	}
	
	int main() {
		int A, B;
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);
		
		/* Slucajevi koji nastupaju ukoliko A nije strogo manje od B */
		do {
			
			if (A<0 || A==0) {
				printf ("A nije prirodan broj.\n");
			}
			
			else if (A>B || A==B) {
				printf ("A nije manje od B.\n");
			}
			
			if (A<0 || A==0 || A>B || A==B) {
				printf ("Unesite brojeve A i B: ");
				scanf ("%d %d", &A, &B);
			}
			
		} while (A<0 || A==0 || A>B || A==B);
		
		printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma_prostih(A, B));
		return 0;
		}
	