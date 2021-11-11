#include <stdio.h>
#include <math.h>
#define BR_EL 100

void ubaci (int niz[], int vel)
{
	int i, cifra, suma=0, koeficijent=1;
	for (i=0; i<vel; i++)
	{
		scanf ("%d", &niz[i]);
		
	cifra = i%10;
	suma=suma+fabs(cifra)*koeficijent;
	koeficijent*=10;
	i/=10;
	}
}

int Fibnacijev_niz(int niz[], int vel)
{
	int i, prvi, drugi, treci;
	for (i=0; i<vel; i++)
	{
		if (i==0)
		{
			prvi=1;
		}
		else if (i==1)
		{
			drugi=1;
		}
		else 
		{
			treci = prvi+drugi;
			prvi = drugi;
			drugi = treci;
		}
	}
	return vel;
}

int izbaci (int niz[], int vel)
{
	int i, j;
	for (i=0; i<vel; i++)
	{
		if (Fibnacijev_niz(niz, i))
		{
			for (j=i; j<vel; j++)
			{
				niz[i]=niz[i+1];
			}
			
			vel--;
			i--;
		}
	}
	return vel;
}

void Ispisi(int *niz, int vel)
{
	int x;
	ubaci(niz, vel);
	izbaci(niz, vel);
	int i;
	for (i=0; i<vel; i++)
	{
		printf ("%d", *(niz+i));
	}
	x=izbaci(niz, vel);
	if (x==0) return 0;
	else return 1;
}

int main() 
{
	int i, niz[10];
	printf ("Unesite niz od 10 brojeva: ");
	scanf ("%d", &niz[i]);
	
	// ubaci(niz,10);
	// izbaci(niz,10);
	//printf ("Modificirani niz glasi: ");
	// for (i=0; i<10; i++) 
	// {
	// 	printf ("%d", niz[i]);
	// }
	//Ispisi(niz, 10);
	
	printf ("Modificirani niz glasi: ");
	Ispisi(niz, 10);
	
	int x;
	x=izbaci(niz, 10);
	if (x == 0) printf ("Prazan niz. ");
	else printf ("Velicina niza je %d.", x);
	
	return 0;
}
