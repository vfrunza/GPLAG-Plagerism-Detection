#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int velicina)
{
	int i;
	for(i=0; i<velicina; i++) {
		niz[i]=round(niz[i]*10) / 10;
	}
}

void preslozi(float niz[], int velicina, int k)
{

	int i, temp,  brojac1=0, brojac2=0, predznak=1;
	float veciodk[1000], manjiodk[1000], sumacfr=0;

	zaokruzi1(niz, velicina);

	for(i=0; i<velicina; i++) {
		sumacfr=0;

		temp=(int)niz[i];
		if(temp<0) predznak=-1;
		else predznak=1;
		temp*=predznak;
		sumacfr+=(fabs(niz[i])-temp)*10;
		sumacfr=round(sumacfr*10)/10;
		if(sumacfr-(int)sumacfr>0.5) sumacfr=(int)sumacfr+1;
		while(temp!=0) {
			sumacfr+=temp%10;
			temp/=10;
		}
		if(sumacfr>=k) {
			veciodk[brojac1]=niz[i];
			brojac1++;
		} else {
			manjiodk[brojac2]=niz[i];
			brojac2++;
		}
	}

	for(i=0; i<brojac1; i++) {
		niz[i]=veciodk[i];
	}
	for(i=brojac1; i<brojac1+brojac2; i++) {
		niz[i]=manjiodk[i-brojac1];
	}



}


int main()
{

	int i, k, n;
	float niz[100];
	printf("Unesite broj clanova niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) {
		scanf("%f", &niz[i]);
	}
	printf("Unesite k: ");
	scanf("%d", &k);

	preslozi(niz, n, k);

	return 0;



}
