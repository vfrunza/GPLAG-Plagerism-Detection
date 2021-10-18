#include <stdio.h>

/*Funkcija koja svaki put kada se pozove vraca sljedeci prost broj*/
int daj_prost() {
	int i,j;
	static int c=1;
	for (i=c+1; i<10000; i++) {
		int prost=1;
		if (i==2 || i==3 || i==5 || i==7) {
			c=i;
			return c;
		} else {
			for(j=2; j<i-1; j++) {
				if (i%j==0) prost=0;
			}
			if (prost==1) {
				c=i;
				return c;
			}
		}
	}
}



int main() {
	int A,i,B,suma=0;
	int sabirak;
	
	/*Unos brojeva A i B*/
	do { 
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
	
		if (A<=0) {
			printf("A nije prirodan broj. ");
		} else if (A>=B) {
			printf("A nije manje od B.");
		}
	} while (A<1 || A>=B);
	
	/*Racunanje sume prostih uz pozivanje funkcije daj_prost*/
	for (i=0; i<B; i++) {
		sabirak=daj_prost();
		if (sabirak>A && sabirak<B) {
			suma+=sabirak;
		}
	}
	
	/*Ispis*/
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}