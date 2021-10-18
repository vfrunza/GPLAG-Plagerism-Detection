#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz, int vel)
{
	int i;
	for (i=0; i<vel; i++) {
		niz[i] *= 10;
		niz[i] = round(niz[i]);
		niz[i] /= 10;
	}
}

void preslozi(float *niz, int vel, int k)
{

	int i,j,broj=0,suma=0,n=0;
	
	float temp;

	zaokruzi1(niz,vel);

	for(i=0; i<vel-n; i++) {

		broj=0;
		suma=0;

		niz[i]=niz[i]*10;
		broj=(int)niz[i];

		if(broj<0) broj=broj*(-1);

		while (broj>0) {
			int cifra=broj%10;
			suma=suma+cifra;
			broj/=10;
		}

		niz[i]=niz[i]/10;

		if(suma<k) {

			temp=niz[i];
			for(j=i+1; j<vel; j++) {
				niz[j-1]=niz[j];
				niz[j]=temp;
			}
			n++;
			i--;
		}
	}
}


int main()
{
	return 0;
}