#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz2[], int vel2)
{
	int i;
	for(i=0; i<vel2; i++) {
		niz2[i]=round(niz2[i]*10)/10;
	}
}

void preslozi(float niz[], int vel, int k)
{
	int i, j, pozicija=0, broj;
	zaokruzi1(niz,vel);
	for(i=0; i<vel; i++) {
		int suma=0;
		broj=(int)(niz[i]*10);
		if (broj<0) broj=broj*(-1);
		do {
			int cifra;
			cifra=broj%10;
			suma+=cifra;
			broj/=10;
		} while (broj>0);
		if (suma>=k) {
			float  temp=niz[i];
			for(j=i; j>pozicija; j--) {
				niz[j]=niz[j-1];
			}
			niz[pozicija]=temp;
			pozicija++;
		}
	}
}

int main()
{
	return 0;
}
