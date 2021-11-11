#include <stdio.h>

int daj_prost() {
	static int prost_br=1;
	int i;
	prost_br++;
	for(i=2; i<prost_br; i++){
		if (prost_br%i==0){
			prost_br++;
			i=2;
		}
	}
	return prost_br;
}

int main() {
	int A,B,i,prost_br,suma=0;
	// Unos
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A>=B){
			printf("A nije manje od B. \n");
		}
		if(A<=0){
			printf("A nije prirodan broj. \n");
		}
	}while(A>=B || A<=0);
	// Obrada podataka
	for(i=0; i<B; i++){
		prost_br=daj_prost();
		if(A<prost_br && B>prost_br){
			suma+=prost_br;
		}
		if(prost_br>=B){
			break;
		}
	}
	// Ispis
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
