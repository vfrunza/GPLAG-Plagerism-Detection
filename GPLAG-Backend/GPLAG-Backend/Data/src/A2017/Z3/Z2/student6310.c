#include <stdio.h>
#include <math.h>

/*Funkcija koja zaokruzuje clanove niza na jednu decimalu*/
void zaokruzi1 (float *niz, int vel)
{
	int i;
	for (i=0; i<vel; i++) {
		niz[i]*=10;
		niz[i]=round (niz[i]);
		niz[i]/=10;
	}
}

void preslozi (float *niz, int vel, int k)
{
	/*Poziv prve funkcije*/
	zaokruzi1(niz, vel);

	int m, n, z, zbir;
	double privremena;

	/*Sortiranje niza*/
	int zbir_cifara (float x);
	m=0;
	for(z=0; z<vel; z++) {
		zbir=zbir_cifara(niz[m]);

		if(zbir<k) {
			privremena=niz[m];

			for(n=m; n<vel-1; n++) {
				niz[n]=niz[n+1];
			}
			niz[vel-1] = privremena;
			m--;
		}
		m++;
	}
}

int main()
{

	return 0;
}

int zbir_cifara (float x)
{
	int cifra, y, sum=0;
	/*Da bi bio pozitivan*/
	x = fabs(x);
	/*Da bi bio cijeli broj, jer smo prethodno zaokruzili na jednu decimalu*/
	cifra=x*10;
	/*Suma cifara*/
	while (cifra!=0) {
		y=cifra % 10;
		sum+=y;
		cifra/=10;
	}
	/*Vracamo sumu cifara*/
	return sum;
}