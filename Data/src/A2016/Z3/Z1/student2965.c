#include <stdio.h>
/*Funkcijom "prost" provjerava se jesu li brojevi prosti*/
int prost (int x) {
	int i;
	for(i=2; i<x; i++) {
		if(x%i==0) return 0;
	}
	return 1;
}
/*Funkcija "daj_prost" uzima te proste brojeve*/
int daj_prost () {
	static int t=1;
	do {
		t++;
	} while (prost(t)==0);
	return t;
}
int main() {
	int A,B,i,m,suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A<1) {
			printf("A nije prirodan broj.\n");
		}
		else if(B<=A) {
			printf("A nije manje od B.\n");
		}
	} while (A<1 || B<=A);
	for(i=2; i<B; i++) {
		if(prost(i)==1) {
			m=daj_prost();
		}
		/*Prosti brojevi moraju biti u intervalu od A do B, onda postavimo uslov i>A i i<B.*/
		if(i>A) {
			if(prost(i)==1) {
				suma=suma+m;
			}
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
    return 0;	
}