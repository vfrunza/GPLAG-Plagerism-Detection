#include <stdio.h>

int daj_prost() {
	static int p=2;
	int i, o;
	/*Provjerava se je li staticko p prost te ako jest on se salje u main, a 
	staticko p se uvecava za 1*/
	for(i=2; i<=p; i++) {
		if(i==p) {
			p++;
			o=p;
			o--;
			return o;
		}
		/*Uslov koji vraca petlju unazad ako je p slozen te ga povecava ujedno za 1
		da se provjerava je li njegov sljedbenik prost sve dok se ne dodje do sljedeceg
		prostog broja*/
		if(p%i==0) {
			p++;
			if(i%2==0) i--;
			if(i%3==0) i-=2;
			if(i%5==0) i-=4;
			if(i%7==0) i-=6;
		}
	}
}

int main() {
	int A, B, i, j, suma=0, x;
	/*Unos brojeva*/
	for(i=0; i<1; i++) {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A>=B) { 
			printf("A nije manje od B.\n");
			i--;
		}
		if(A<=0) {
			printf("A nije prirodan broj.\n");
			i--;
		}
	}
	/*Provjerava se je li broj "i" izmedju A i B prost,ukoliko jest poziva se 
	funkcija daj_prost sve dok broj koji vrati funkcija ne bude jednak "i" 
	te se takav broj onda dodaje na sumu koju trazimo*/
	for(i=A+1; i<B; i++) {
		for(j=2; j<=i; j++) {
			if(j==i) {
				x=daj_prost();
				if(i==x) suma+=x;
				else i--;
			}
			if(i%j==0) break;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
