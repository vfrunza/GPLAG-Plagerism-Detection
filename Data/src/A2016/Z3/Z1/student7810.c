#include <stdio.h>
/*Funkcija koja daje sljedeci prost broj prilikom svakog poziva pocev od broja 2*/
int daj_prost(){
	static int broj=2;
	int i;
	while (1) {
		int prost=1;
		for (i=2;i<broj;i++){
		if (broj%i==0) {prost=0;break;}
	} if (prost) return broj++;
	broj++;
	
	}
}
int main() {
	int n,n1,A,B,suma=0;
	/*Petlja koja omogucava unos prirodnih brojeva A i B gdje je A strogo manje od B*/
	do {
		printf("Unesite brojeve A i B: ");
	    scanf("%d%d",&A,&B);
	    if (A<=0) {printf("A nije prirodan broj.\n");}
	    else if (A>=B) {printf("A nije manje od B.\n");}
	} while (A<=0 || B<=0 || A>=B);
	/*Petlja koja nam daje prvi prost broj veci od A*/
		do {
		    n=daj_prost();	
		} while (n<=A);
		suma+=n;
		/*Suma svih prostih brojeva izmedju A i B*/
		do {
			n1= daj_prost(); if (n1>=B) break;
			suma=suma+n1;
		} while (n1<=B);
    if (suma==n) suma=0;
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
