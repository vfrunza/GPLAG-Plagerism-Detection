#include <stdio.h>
int daj_prost () {
	int i,k;
	do {
		k=0;
		/*Koristimo staticku promjenljivu jer zelimo zadrzati njenu vrijednost*/
		static int n=2;
		for(i=2;i<n;i++) {
			if(n%i==0) k++;
		}
		/*Prost broj zadovoljava uslov*/
		if(k==0) {
			n++;
			return n-1;
		}
		/*Ako broj nije prost, promjenljiva se svejedno mora povecati*/
	n++;
	} while (k!=0);
}
int main() {
	int a,b;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if (a<1) printf("A nije prirodan broj.\n");
		if (a>=b) printf("A nije manje od B.\n");
	} while (a<1 || b<1 || a>=b);
	int suma=0,broj;
	broj=daj_prost();
	while(broj<b) {
		if(a<broj && broj<b) {
			suma+=broj;
		}
		broj=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
