#include <stdio.h>
#include <math.h>

float zaokruzi_broj(float broj)
{
	int ima=0;
	int cijeli=0; float novi=0;
	if(broj<0)
	{
		broj*=-1;
		ima=1;
	}
	broj*=100;
	cijeli=broj;
	if(cijeli%10>4)
		cijeli+=10;
	cijeli/=10;
	novi=cijeli/10.;
	if(ima)
		novi*=-1;
	return novi;
}

int suma_cifara(int n)
{
	int suma=0;
	if(n<0) n*=-1;
	while(n!=0)
	{
		suma+=n%10;
		n/=10;
	}
	return suma;
}

void zaokruzi1(float *niz, int vel)
{
	int i;
	for(i=0; i<vel; i++)
		niz[i]=zaokruzi_broj(niz[i]);
}


void preslozi(float *niz, int vel, int k)
{
	int i;
	int pom[10000], br=0;
	zaokruzi1(niz, vel);
	
	for(i=0; i<vel; i++)
		pom[i]=niz[i]*10;
		
	for(i=0; i<vel; i++)
		if(suma_cifara(pom[i])>=k)
		{
			niz[br]=pom[i]/10.;
			br++;
		}
		
	for(i=0; i<vel; i++)
		if(suma_cifara(pom[i])<k)
		{
			niz[br]=pom[i]/10.;
			br++;
		}
}

int main() {
	int i;
float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
zaokruzi1(niz, 5);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
	return 0;
}
