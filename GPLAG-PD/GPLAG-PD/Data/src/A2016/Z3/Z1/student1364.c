#include <stdio.h>

int daj_prost () {
	static int j=2;
	int i, prost=1;
	do {
		for (i=2; i<j; i++) {
		if (j%i==0)
		break;
		}
	if (j==i) {
		prost = 0;
		}
	j++;
	}
	while (prost==1);
	return i;
}

int main() {
	int A=0, B=0, unos=1, i, prost=0;
	long suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);
		if (A<=0) {
			printf ("A nije prirodan broj.\n");
			unos = 0;
		}
			else if (A>=B) {
			printf ("A nije manje od B.\n");
			unos = 0;
		}
		else if (B<=0) {
			printf ("B nije prirodan broj.\n");
			unos = 0;
		}
		else unos = 1;
	}
	while (unos==0);
	
	for (i=A+1; i<B; i++) {
		prost = daj_prost();
		if (prost<=A) {
			i--; 
			continue;
		}
		if (prost>B-1)
		break;
		suma+= prost;
	}
	
	printf ("Suma prostih brojeva izmedju %d i %d je %li.", A, B, suma);
	return 0;
}
