#include <stdio.h>

int Da_Li_Je_Prost (int n) {
	int prost=1,i;
	for (i=2; i<=n/2; i++) {
		if (n%i==0) {
			prost=0;
			break;
		}
	}
	return prost;
}

int daj_prost() {
	static int prost_broj=1;
	do {
		prost_broj++;
	} while (Da_Li_Je_Prost(prost_broj)==0);
	return prost_broj;
}

int main() {
	int A,B,i,suma=0,b;
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d%d",&A,&B);
		if (A<=0) {
			printf("A nije prirodan broj.\n");
		}
		else if (A>=B) {
			printf("A nije manje od B.\n");
		}
		else if (B<=0) {
			printf("B nije prirodan broj.\n");
		}
		
	} while (A>=B || A<=0 || B<=0);
	
	
	b=daj_prost();
	for (i=A+1; i<B; i++) {

		if (b<i) {
			b=daj_prost();
			i--;
		}
		else if (b==i) {
			suma+=b;
			b=daj_prost();
		}
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}