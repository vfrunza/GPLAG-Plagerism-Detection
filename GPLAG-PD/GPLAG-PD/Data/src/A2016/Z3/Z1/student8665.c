#include <stdio.h>
int daj_prost () {
	int prost,i=0;
	static int broj=1;
	if(broj==1) {
		broj++;
		return 2;
	} else {
		do {
			broj++;
			prost=1;
			for(i=2; i<broj; i++) {
				if(broj%i==0)
					prost=0;
			}
		}while(prost==0);
	}
	return broj;
}

int main() {
	int A=0,B=0,suma=0,i=0,broj=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A<=0) printf("A nije prirodan broj.\n");
		if(A>=B) printf("A nije manje od B.\n");
	} while(A<=0 || A>=B);
	while(broj<=B) {
		broj=daj_prost();
		if(broj>A && broj<B)
			suma += broj;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);

	return 0;
}

	