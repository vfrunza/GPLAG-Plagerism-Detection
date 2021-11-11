#include <stdio.h>

int daj_prost() {
	
	static int j=1; /*Statički int (globalne zabranjene & funkc. ne smije imat parametara)*/
	int i=2, broj=0;
	
	while (broj==0) {
		j++;
		broj=1;
		for (i; i<j; i++) {
			if (j%i==0) {
				br=0;
				break;
			}
		}
		if (broj!=0)
			return j;
	}
}

int main()
{
	int A , B, p, suma=0, i;

	do {
		printf("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);

		if (A<=0) {
			printf ("A nije prirodan broj.\n");
		}

		if (A>=B) {
			printf ("A nije manje od B.\n");
		}
	} while (A<=0 || A>=B);

	p=daj_prost();

	while (p<B) {
		if (p>A && p<B)
			suma+=p;
		p=daj_prost();
	}

	printf ("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);

	return 0;
}