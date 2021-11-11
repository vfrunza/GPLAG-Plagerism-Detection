#include <stdio.h>

int daj_prost() {
	static int brojac=1;
	int i, j;
	brojac++;
	for(i=brojac;;i++) {
		for(j=2; j<i; j++) {
			if(i%j==0) 
				break;
			
		}
		if(i==j) {
			brojac=i;
			break;
		}
	}
	return brojac;
}


int main() {

	int A,B, suma=0, prost_broj;

	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	while(A<1 || A>=B) {
		if(A<1)
			printf("A nije prirodan broj.");
		else if(A>=B)
			printf("A nije manje od B.");
			
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);	
	
	}

	prost_broj=daj_prost();
	while(prost_broj<B) {
		if(prost_broj>A && prost_broj<B)
			suma=suma+prost_broj;
		prost_broj=daj_prost();
	}

	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);

return 0;
}
