#include <stdio.h>

int daj_prost() {
	static long int broj=1;
	long int j;
	broj++;
	for(j=2; j<broj; j++) {
		if(broj%j==0) {
			j=2;
			broj++;
		}
	}
	
	return broj;
}

int main() {
	long int a,b,suma=0,i,broj;
	while(1) {
		printf("Unesite brojeve A i B: ");
		scanf("%ld%ld", &a,&b);
		if(a<b && a>0) break;
		if(a>=b && a>0) printf("A nije manje od B.\n");
		if(a<1) printf("A nije prirodan broj.\n");
	}
	
	for(i=1; ; i++) {
		broj=daj_prost();
		/* Ako je broj manji ili jednak A preskace donje naredbe i prelazi na uvecanje i iz petlje */
		if(a>=broj) continue;
		/* Cim je broj veci ili jednak B prekida se petlja */
		if(b<=broj) break;
		suma+=broj;
	}
	
	printf("Suma prostih brojeva izmedju %ld i %ld je %ld.", a,b,suma);
	return 0;
}
