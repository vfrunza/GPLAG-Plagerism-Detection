#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void zaokruzi1(float [], int );
int preslozi (float [], int ,int );

int main ()
{

	int i;
	float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
	preslozi(niz, 5, 14);
	printf("Niz glasi: ");
	for (i=0; i<5; i++)
		printf("%g ", niz[i]);

	return 0;
}



void zaokruzi1(float *niz, int vel)
{

	int i;
	for (i=0; i<vel; i++) {

		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]= niz[i]/10;
	}

}


int preslozi (float *niz, int vel,int k)
{

	zaokruzi1(niz,vel);
	int suma;
	int sada=0;
	int trenutna=0;
	int i;
	float broj;



	int velicinaNizaVecegOdK=0;
	int velicinaNizaManjegOdK=0;

	float veciOdK [50];
	float manjiOdK [50];
	int indexVeciOdK=0;
	int indexManjiOdK=0;
	int j;
	
	for (j=0; j<vel; j++) {
		suma=0;
		broj=niz[j]*10;
		trenutna=abs(broj);
		//razbijanje broja na cifre 
		while (trenutna>0) {
			sada=trenutna%10;
			suma=suma+sada;
			trenutna=trenutna/10;
		}
		//smjestanje broja u odgovarajuci niz
		if (suma>=k) {
			veciOdK[indexVeciOdK]=niz[j];
			indexVeciOdK++;
			velicinaNizaVecegOdK++;

		}

		else {
			manjiOdK[indexManjiOdK]=niz[j];
			indexManjiOdK++;
			velicinaNizaManjegOdK++;
		}


	}


	//ispis nizova u koje smo smjestili brojeve 
	for(i=0; i<velicinaNizaVecegOdK; i++) {
		niz[i] = veciOdK[i];
	}
	for(j = 0; j<velicinaNizaManjegOdK; j++) {
		niz[i] = manjiOdK[j];
		i++;
	}

}