#include <stdio.h>
#include <math.h>
int daj_prost()
{
	int i, prost;
	static int broj=1;
	do {
		broj++;
		prost = 1;
		for(i=2; i<=broj/2; i++)				//Provjera je li broj prost
			if(broj%i == 0) {
				prost=0;
				break;
			}
	} while(prost == 0);
	if(prost==1)
		return broj;
	else return 0;
}

int main()
{
	int A, B, suma=0, i, broj, uslov;
	do {												//Uslovi unosa
		uslov = 1;
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A < 1) {
			printf("A nije prirodan broj.\n");
			uslov = 0;
		} else if (A >= B) {
			printf("A nije manje od B.\n");
			uslov = 0;
		}
	} while(uslov == 0);

	do {												//Poziv funkcije daj_prost
		broj=daj_prost();
		if(broj > A && broj < B)
			suma+=broj;
	} while(broj<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);


	return 0;
}
