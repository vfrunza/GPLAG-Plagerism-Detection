#include<stdio.h>
int daj_prost() {
	static int n=2; /* Svakim pozivom vraca sljedeci prost broj */
	int i;
	if (n==2) {
		n++;
		return 2;
	}
	for(i=2; i<n; i++) {
		if(n%i==0) {
			n++;
			i=1;
		}
	}
	n++;
	return n-1;
}
int main () {
	int A, B, prostbr;
	int suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<=0) {
			printf("A nije prirodan broj.\n");
		}
		if(A>=B) {
			printf("A nije manje od B.\n");
		}
	} while (A>=B || A<=0);
	for(;;) {
		prostbr=daj_prost();
		if(prostbr>=B) {
			break;
		}
		if(prostbr>A) {
			suma=suma+prostbr;
		}
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}