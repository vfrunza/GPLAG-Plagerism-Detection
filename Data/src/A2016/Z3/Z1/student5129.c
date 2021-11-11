#include <stdio.h>

int daj_prost(){
	static int pr=1;
	int i;
	
	/* Inkrement staticke varijable */
	pr++;
	
	for(i=2; i<pr; i++){
		/* Ako je djeljiv sa brojacem, inkrementuje se max vrijednost brojaca, a brojac se resetuje na pocetnu vrijednost  */
		if(pr%i==0) {
			pr++;
			i=2;
		}
	}
	
	return pr;
}

int main() {
	int a, b, i, prost, suma;
	
	/* Input */
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		
		/* A mora biti prirodan broj, tj. mora biti cijeli broj veci od 0 */
		if(a<1) printf("A nije prirodan broj.\n");
			
		/* Provjera uslova da A mora biti manje od B */
		if(a>=b) printf("A nije manje od B.\n");

	} while(a<1 || a>=b);
	
	/* Racunanje sume */
	suma=0;
	for(i=0; i<b; i++){
		/* Uvodimo prost jer se daj_prost ponavlja svaki put kad je spomenemo, veoma je stidna */
		prost=daj_prost();
		
		/* Gledamo ako je unutar intervala */
		if(prost>a && prost<b) suma+=prost;
		/* Ako je prost veci od B, svaki sljedeci prost ce biti veci od B pa mozemo komotno zavrsiti petlju */
		if(prost>b) break;
	}
	
	/* Ispis */
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	return 0;
}

/*
0 15
5 -5
10 10
-5 -2
2 10
*/