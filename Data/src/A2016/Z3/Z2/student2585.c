#include <stdio.h>
#include <stdlib.h>
void ubaci(int *niz, int n)
{
	int i, j, broj, suma=0, novi, cifra;
	for (i=0; i<n; i++)
	{
		suma=0;
		broj=abs(*(niz+i));
		while (broj!=0)
		{
			cifra=broj%10;
			suma=suma+cifra;
			novi=suma;
			broj=broj-cifra;
			broj=broj/10;
		}
		for (j=n-1; j>i; j--)
		{
			niz[j+1]=niz[j];
		}
		n++; //povecava se dimenzija niza jer smo ubacili clanove
		i++;
		niz[i]=suma;
	}
}

int fib(int n)
{
	int fibniz[50]={1,1,2};
	int i=2;
	for(i=2;i<50;i++) 
	{
		fibniz[i] = fibniz[i-1] + fibniz[i-2]; //bilo koji fibonaccijev broj nastaje kao suma prethodna dva 
	}
	i=0;
	while(i<50)
	{
		if(fibniz[i]==n) return 1; //provjera da li je fibonaccijev 
		i++;
	}
	return 0;
}

int izbaci(int *niz, int n)
{
	int niz2, i, m;
for(i=0; i<n; i++)
{
	if(fib(*(niz+i))==1)
	{
		for(m=i; m<n-1; m++)
		{
			niz[m]=niz[m+1]; //izbacivanje clana niza
		}
		i--; //smanjenje broja indeksa 
		n--; // smanjenje dimenzije niza jer smo izbacili clan 
	}
}
return n;
}



int main() {
	int niz[20];
	int i,n=10, k;
	printf("Unesite niz od 10 brojeva: "); 
	for(i=0; i<10; i++)
	{
		scanf("%d", &niz[i]); //unos niza 
	}
	
	ubaci(&niz[0],n); //poziva se funkcija ubaci
	n=20;
	
	k=izbaci(&niz[0], n); //poziva se funkcija izbaci 
	n=k;

	
	printf("Modificirani niz glasi: ");

	for(i=0; i<n-1; i++)
	{
		printf("%d, ", niz[i]); //ispis niza 
	}
	printf("%d.", niz[n-1]);
	return 0;
}
