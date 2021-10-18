#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int duzina)
{
	int i;
	for (i=0; i<duzina; i++) {
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}
}

void preslozi(float *niz,int duzina,int k)
{
	int i,suma[100]= {0},brojac1=0,brojac2=0,j=0;
	float novi_niz1[100],dummy_niz[100],novi_niz2[100],konacni_niz[100];
	zaokruzi1(niz,duzina);

	if (k<1)
		return 0;

	for (i=0; i<duzina; i++) {
		dummy_niz[i]=niz[i];

		if (niz[i]<0)
			niz[i]=-niz[i]*10;

		else
			niz[i]=niz[i]*10;

		while (niz[i]>0) {
			suma[i]+=((int) (niz[i])%10);
			niz[i]=niz[i]/10;
		}

		if (fabs(suma[i])>=k) {
			novi_niz1[brojac1]=dummy_niz[i];
			brojac1++;
		} else {
			novi_niz2[brojac2]=dummy_niz[i];
			brojac2++;
		}
	}

	for (i=0; i<brojac1; i++) {
		konacni_niz[i]=novi_niz1[i];
	}

	for (i=brojac1; i<(brojac1+brojac2); i++) {
		konacni_niz[i]=novi_niz2[j];
		j++;
	}

	for (i=0; i<(brojac1+brojac2); i++) {
		(*niz++)=konacni_niz[i];
	}

}

int main()
{
	int k,duzina,i;
	float niz[100];
	printf ("Unesi k: ");
	scanf ("%d", &k);
	printf ("Unesi broj elemenata niza: ");
	scanf ("%d", &duzina);
	printf ("Unesi elemenate niza: ");
	for (i=0; i<duzina; i++) {
		scanf ("%f", &niz[i]);
	}
	preslozi(niz,duzina,k);
	printf ("Niz glasi: ");
	for (i=0; i<duzina; i++)
		printf ("%g ", niz[i]);


	return 0;
}