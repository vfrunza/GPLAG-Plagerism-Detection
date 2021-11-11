#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int duzina_niza)
{
	int i;
	for(i=0; i<duzina_niza; i++) {
		*niz=roundf(*niz*10)/10;
		niz++;
	}
}

void preslozi(float *niz, int duzina_niza, int k)
{
	int i,j,broj,suma_cifara,pom=1;
	float temp;
	float *pokazivac;
	if(duzina_niza>0 && k>0) {
		zaokruzi1(niz,duzina_niza);
		for(i=0; i<duzina_niza; i++) {
			broj=*niz*10;
			suma_cifara=0;
			while(broj!=0) {
				suma_cifara+=(int)fabs(broj)%10;
				broj/=10;
			}
			if(suma_cifara<k) {
				pokazivac=niz;
				for(j=pom; j<duzina_niza; j++) {
					temp=*pokazivac;
					*pokazivac=*(pokazivac+1);
					*(pokazivac+1)=temp;
					pokazivac++;
				}
			} 
			else {
				niz++;
				pom++;
			}
		}
	}
}

int main()
{
	return 0;
}