#include <stdio.h>


int daj_prost (){
	static int a=2;
	int i, b;
	while (a<10000){
		for (i=2; i<a; i++){
			if (a%i==0) {
				a++;
				i=2;
			}
		}
		b=a;
		a++;
		return b;
	}
}


int main() {
	
	int i, A, B, suma=0, C, niz[2];
	
	printf ("Unesite brojeve A i B: ");
	scanf ("%d %d", &niz[0], &niz[1]);
	
	for (i=0; i<100; i++){

		if (niz[0]<=0){
			printf ("A nije prirodan broj.");
			printf ("\nUnesite brojeve A i B: ");
			scanf ("%d %d", &niz[0], &niz[1]);
		} else if (niz[1]==0){
			printf ("B nije prirodan broj.");
			printf ("\nUnesite brojeve A i B: ");
			scanf ("%d %d", &niz[0], &niz[1]);
		} else if (niz[0]>=niz[1]){
			printf ("A nije manje od B.");
			printf ("\nUnesite brojeve A i B: ");
			scanf ("%d %d", &niz[0], &niz[1]);
		} else {
			break;
		}
	
	}
	
	A = niz[0];
	B = niz[1];
	
	for (i=0; i<=B; i++){
		C=daj_prost();
		if (C>B){
			break;
		}
		if (C>A && C<B){
			suma+=C;
		}
	}
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	
	return 0;
}