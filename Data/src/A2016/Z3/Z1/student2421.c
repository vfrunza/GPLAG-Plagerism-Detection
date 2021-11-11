#include <stdio.h>
int daj_prost() {
	static int n=3, prvi=1;
	if (prvi) {
		prvi=0;
		return 2;
	}
	while (1) {
		int i, prost=1;
		for (i=2; i<n; i++) {
			if (n%i==0) {
				prost=0;
			}
			if (prost==0) {
				n++;
				break;
			}
		}
		if (prost) {
			prost=n;
			n++;
			return prost;
		}
	}
	
}	

int main() {
	int A, B, y, i, suma=0;
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);
		if (A<=0) {
		printf ("A nije prirodan broj.\n");
	  }
    	if (A>=B) {
		printf ("A nije manje od B.\n");
	   }
	}while (A>=B || A<=0);
	for (i=1; i<=B; i++) {
		y=daj_prost();
		if (y>A && y<B) {
			suma+=y;
		}
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}
