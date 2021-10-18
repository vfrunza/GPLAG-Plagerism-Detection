#include <stdio.h>
int daj_prost() {
	static int prost=1;
	int i;
trazenje:
	prost++;
	for(i=2; i<prost; i++) {
		if(prost%i==0) goto trazenje;
	}
	return prost;
}

int main() { 
	int A, B, suma=0, i, prost_broj=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<=0) { printf("A nije prirodan broj.\n"); continue; }
		else if(A>B || A==B) { printf("A nije manje od B.\n"); continue; }
	}while(A<=0 || A>B || A==B);
	for(i=1;; i++) {
		prost_broj=daj_prost();
		if(prost_broj<=A) continue;
		if(prost_broj>=B) break;
		suma+=prost_broj;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}