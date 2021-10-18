#include <stdio.h>

/*funkcija koja pronalazi i vraca proste brojeve*/
int daj_prost() {
	static int prost=1;
	int i=2;
	do {
	    prost++;  
		for (i=2; i<prost; i++) {
			if (prost%i==0) 
				break;
		}
	} while (prost!=i);
	if (prost==i)
		return prost;
}

int main() {
	int broj_a,broj_b,prost,suma=0;
	/*unos granica intervala*/
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &broj_a, &broj_b);
		if (broj_a<1)
			printf("A nije prirodan broj.\n");
		else if (broj_a>=broj_b)
			printf("A nije manje od B.\n");
	} while (broj_a<1 || broj_a>=broj_b);
	/*sabira sve proste brojeve u intervalu od A do B*/	
	prost=daj_prost();
	while ((broj_a<=prost && broj_b>prost) || prost==0 || broj_a>prost) {
		if (broj_a<prost || prost==0)
			suma+=prost;
		prost=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.\n", broj_a, broj_b, suma);
	return 0;
}
