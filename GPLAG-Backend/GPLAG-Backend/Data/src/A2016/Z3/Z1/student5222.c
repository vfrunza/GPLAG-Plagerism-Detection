#include <stdio.h>

int daj_prost () {
	static int broj=1;
	int i, j, prost;
	for (i=broj+1; ; i++) {
		prost=1;
		for (j=2; j<i; j++) {
			if (i%j==0) {
				prost=0;
				break;
			}
		}
		if (prost==1) {
			broj=i;
			break;
		}
	}
	return i;
}


int main () 
{
	int A, B, suma=0, i;
	for (; ;) {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d%d", &A, &B);
		if (A<B) {
			if (A<1) {
				printf ("A nije prirodan broj.\n");
			}
			else {
				break;
			}
		}
		else {
			printf ("A nije manje od B.\n");
		}
	}
	for (i=daj_prost(); ; i=daj_prost()) {
		if (i>=B) {
			break;
		}
		else if (i>A && i<B) {
			suma+=i;
		}
		
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}