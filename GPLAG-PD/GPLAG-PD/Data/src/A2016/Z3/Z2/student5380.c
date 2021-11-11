#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ubaci (int *niz, int duzniza)
{
	int i, suma, duzniza2=2*duzniza-2, broj;
	for (i=duzniza-1; i>=0; i--) {
		niz[duzniza2]=niz[i];
		duzniza2=duzniza2-2;         /*prazno mjesto izmedu clanova niza*/
	}
	for (i=1; i<2*duzniza; i=i+2) {
		suma=0;
		broj=abs(niz[i-1]);
		do {
			suma=suma+broj%10;
			broj=broj/10;
		} while (broj>0);
		niz[i]=suma;            /*ubacivanje sume (cifara) u prazna mjesta*/

	}

}

int izbaci (int* niz, int duzniza)
{
	int i,j,fbr1=1,fbr2=1,fbr3,fib;
	for (i=0; i<duzniza; i++) {
		fib=0;
		fbr1=1;
		fbr2=1;
		fbr3=1;

		while (fbr3<niz[i]) {

			fbr3=fbr1+fbr2;
			fbr1=fbr2;
			fbr2=fbr3;      /*provjeravanje da li je u pitanju fibonacijev broj*/
		}


		if (fbr3==niz[i]) {
			fib=1;
		}
		if (fib==1) {
			for (j=i; j<duzniza-1; j++) {
				niz[j]=niz[j+1];
			}
			i--;
			duzniza--;
		}
	}                      /*izbacivanje fib brojeva*/

	return duzniza;

}


int main()
{
	int niz[20]= {0},duzniza=10,i,duzniza2;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf ("%d", &niz[i]);
	}

	ubaci (niz, duzniza);
	duzniza = 2 * duzniza;
	duzniza2 = izbaci (niz, duzniza);

	printf ("Modificirani niz glasi: ");  /*ispis*/

	for (i=0; i<duzniza2; i++) {
		if (i<duzniza2-1)
			printf ("%d, ", niz[i]);
		else
			printf ("%d.", niz[i]);
	}

	return 0;
}
