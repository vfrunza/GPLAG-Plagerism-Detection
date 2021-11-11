#include <stdio.h>

int daj_prost ();
int daj_prost ()
{
	static int broj=2;
	int i;
	for(i=2; i<broj; i++) {
		if(broj%i==0) {
			broj++;
			i=1;

		}
	}
	return broj++;
}
int main ()
{
	int suma=0, A, B, S;

	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<1)
			printf("A nije prirodan broj.\n");

		else if(A>=B)
			printf("A nije manje od B.\n");

	} while(A<1 || A>=B);

	while (1) {
		S=daj_prost();
		if(S>A && S<B)
			suma+=S;
		if(S>=B)
			break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.\n", A, B, suma);
	return 0;
}
