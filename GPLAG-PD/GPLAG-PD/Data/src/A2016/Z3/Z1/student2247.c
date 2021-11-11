#include <stdio.h>

int daj_prost() {
	static int broj=1, i;
	broj++;
	for(i=2; i<broj; i++) {
		if(broj%i==0) { 
			broj++; 
			i = 2; 
		}
	}
	return broj;
}

int main() {
	int A, B, suma=0, i, prostBroj;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A>=B) printf("A nije manje od B.\n");
		else if(A<=0) printf("A nije prirodan broj.\n");
	} while(A<=0 || A>=B);
	for(i=1; i<B; i++) {
		prostBroj = daj_prost();
		if(prostBroj>A && prostBroj<B) {
			suma = suma + prostBroj;
		}	
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}