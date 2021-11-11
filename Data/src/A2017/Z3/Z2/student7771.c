#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[],int vel)
{
	int i;
	for(i=0; i<vel; i++) {
		niz[i]=round(niz[i]*10)/10;
	}


}
void preslozi(float niz[],int vel,int k)
{
	zaokruzi1(niz,vel);
	int i,vel2=0;
	float niz2[100];
	for(i=0; i<vel; i++) {
		int broj=niz[i]*10;
		if(broj<0)
			broj=broj*(-1);
		int cifra,suma=0;
		do {
			cifra=broj%10;
			broj=broj/10;
			suma=suma+cifra;
		} while(broj>0);
		if (suma>=k) {
			niz2[vel2]=niz[i];
			vel2++;

		}

	}
	for(i=0; i<vel; i++) {
		int broj=niz[i]*10;
		if(broj<0)
			broj=broj*(-1);
		int cifra,suma=0;
		do {
			cifra=broj%10;
			broj=broj/10.;
			suma=suma+cifra;
		} while(broj>0);
		if (suma<k) {
			niz2[vel2]=niz[i];
			vel2++;

		}


	}


	for(i=0; i<vel; i++) {
		niz[i]=niz2[i];
	}

}
int main()
{

	return 0;
}
