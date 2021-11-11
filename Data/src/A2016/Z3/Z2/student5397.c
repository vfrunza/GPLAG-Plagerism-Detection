#include <stdio.h>
#include <stdlib.h>

/*Funkcija prima niz u kojem smo u mainu prethodno unijeli clanove, pa ga modificira 
tako sto nakon svakog elementa originalnog niza dodaje pozitivni element koji je suma cifara tog elementa*/
void ubaci (int niz[], int n)
{
	int i, j, r, o, suma, t;
	/*Ide od prvog elementa originalnog niza tako sto prvo racuna sumu cifara tog elementa*/
	for (i=0; i<(2*n); i++)
	{
		suma=0;
		r=niz[i];
		while (r!=0)
		{
			o=r%10;
			if (r<0)
			{suma=suma-o;}
			else
			{suma=suma+o;}
			r=r/10;
		}
		
		/*Nakon toga pomijera sve elementa osim tog elementa za jedno mjesto u 
		desno i na novonastalo slobodno mjesto unosi sumu cifara tog elementa*/
		for (j=(2*n)-1; j>i; j--)
		{
			t=suma;
			
			if (j==(i+1))
			{
				niz[j]=t;
			}
			
			else
			{
				niz[j]=niz[j-1];
			}
		}
		i++;
	}
}

/*Funkcija prima niz i iz njega izbacuje sve elemente koji su takodjer u 
Fibonaccijevom nizu, nakon cega vraca broj elemenata niza*/
int izbaci (int niz[], int n)
{
	int h, l, f, m, fib[1000]={0}; 
	
	/*Unos Fibonaccijevog niza*/
	fib[0]=1;
	fib[1]=2;
	for (f=2; f<1000; f++)
	{
		fib[f]=fib[f-1]+fib[f-2];
	}
	/*Poredjenje elemenata glavnog niza i Fibonaccijevog niza*/
	for (h=0; h<n; h++)
	{
		for (l=0; l<1000; l++)
		{
			if (niz[h]==fib[l])
			{
				/*Ukoliko je pronadjen isti element, on se izbacuje iz niza*/
				for (m=h; m<n-1; m++)
				{
					niz[m]=niz[m+1];
				}
				/*Smanjuje se duzina niza jer se izbacivanjem jednog elementa
				smanjio ukupan broj elemenata*/
				n--;
				h--;
				break;
			}
		}
	}
	return n;
}

int main() 
{
	int niz[20]={0}, x, y;
	int n;
	
	/*Unos niza od deset brojeva kako bi se on kasnije mogao modifikovati 
	pomocu funkcija ubaci i izbaci*/
	printf("Unesite niz od 10 brojeva: ");
	
	for (x=0; x<10; x++)
	{
		scanf ("%d", &niz[x]);
	}
    
    n=10;
	ubaci(niz,n);
	n=n*2;
	n=izbaci(niz,n);
	
	/*Ispis modificiranog niza*/
	printf ("Modificirani niz glasi:");
	
	for (y=0; y<(n); y++)
	{
		/*Ako je zadnji element niza stavlja tacku nakon njega umjesto zareza 
		koji se pojavljuje nakon svakog od ostalih elemenata*/
		if (y==(n-1))
		{
			printf (" %d.",niz[y]);
		}
		
		else
		{
		    printf (" %d,",niz[y]);
		}
	}
	
	return 0;
}
