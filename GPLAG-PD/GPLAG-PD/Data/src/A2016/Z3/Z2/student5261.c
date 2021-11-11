#include <stdio.h>
#include <stdlib.h>

int ubaci(int *niz, int vel);
int izbaci(int *niz, int vel);
int dajSumuCifara(int broj)
{
	int povratni=0;
	broj=abs(broj);
	while(broj!=0)
	{
		povratni+=broj%10;
		broj/=10;
	}
	return povratni;
}
int jeLiFibonacijev(int broj)
{
	int prvi=1, drugi=1, treci;
	while(1)
	{
		treci=prvi+drugi;
		prvi=drugi;
		drugi=treci;
		if(broj==treci || broj==prvi || broj==drugi)
			return 1;
		if(broj<treci)
			break;
	}
	return 0;
}

int main()
{
	int niz[20] = {0}, i, habsburskaMonarhija;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
	{
		scanf("%d", &niz[i]);
	}
	habsburskaMonarhija=ubaci(niz, 10);
	habsburskaMonarhija=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<habsburskaMonarhija; i++)
	{
		if(i==habsburskaMonarhija-1)
		printf("%d.", niz[i]);
		else
		printf("%d, ", niz[i]);
	}
	return 0;
}

int izbaci(int *niz, int vel)
{
	int i, j;
	for(i=0; i<vel; i++)
	{
		if(jeLiFibonacijev(niz[i])){
			for(j=i; j<vel-1; j++)
				niz[j]=niz[j+1];
			i--;
			vel--;
		}
	}
	return vel;
}

int ubaci(int *niz, int vel)
{
	int i, j;
	for(i=0; i<2*vel; i+=2)
	{
		for(j=2*vel-1; j>i+1; j--)
			niz[j]=niz[j-1];
		niz[i+1]=dajSumuCifara(niz[i]);
	}
	return vel*2;
}

