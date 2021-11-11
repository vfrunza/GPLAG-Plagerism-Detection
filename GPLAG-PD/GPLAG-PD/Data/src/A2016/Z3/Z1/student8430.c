#include <stdio.h>
#include <math.h>

int prost(int x) {
	int i;
	if(x==0) return 0;
	for(i=2; i<=sqrt(x); i++) {
		if(x%i==0) return 0;
	}
	return 1;
}

int daj_prost() {
	static int prost_broj=1;
	prost_broj++;
	while(!prost(prost_broj)) {
		prost_broj++;
	}
	return prost_broj;
}

int main() {
	int A, B, suma=0, broj;
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A<=0) printf("A nije prirodan broj.\n");
	else if(A>B || A==B) printf("A nije manje od B.\n");
	} while(A<=0 || A>=B);
	while((broj=daj_prost())<B) { 
		if(broj>A) suma+=broj;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}






