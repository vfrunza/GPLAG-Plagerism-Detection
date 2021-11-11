#include <stdio.h>
int daj_prost()
{
	int prost=1;
	int i;
	static int broj=1;
	while(1) {
		broj++;
		if(broj==2) {
			return broj;
		} else {
			for (i=2; i<broj; i++) {
				if (broj%i==0) {
					prost=0;
					break;
				}
			}
			if (prost) {
				return broj;
			} else {
				prost=1;
			}
		}
	}
}

int main()
{
	int A;
	int B;
	int suma=0;
	int broj=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d",&A);
		scanf("%d",&B);
		if (A<1) {
			printf("A nije prirodan broj.\n");
		} else if (A>=B) {
			printf("A nije manje od B.\n");
		}

	} while(A<1 || A>=B || B<=0);
	while(broj<B) {
		broj=daj_prost();
		if (broj<B && broj>A) {
			suma+=broj;
		}
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d." ,A,B,suma);
	return 0;
}