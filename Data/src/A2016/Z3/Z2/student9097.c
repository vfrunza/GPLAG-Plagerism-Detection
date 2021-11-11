#include <stdio.h>
#include <stdlib.h>
int suma (int p1) /*Funkcija koja racuna sumu cifara clana iz niza*/
{
	int s=0;
	while (p1>0)
	{
		s=s+p1%10;
		p1=p1/10;   
	}
	return s;
}
void ubaci(int niz[], int n) /*Funkcija koja ubacuje pozitivan broj u niz nakon svakog clana*/
{
	int *p, i, *q, p1;
	for (i=n-1; i>=0; i--)
	{
		q=niz+i;
		p=niz+i*2;
		*p=(*q);
	}
	for (i=0; i<2*n; i=i+2)
	{
		p=niz+i;
		q=p+1;
		p1=abs(*p); /*Koristimo abs jer treba ubaciti pozitivan broj koji predstavlja sumu cifara clana*/
		*q=suma(p1);
	}
	
}
int izbaci (int niz[], int n) /*Funkcija koja izbacuje clanove niza koji su Fibonaccijevi brojevi*/
{
	int niz1[1111]={0}, MAX, i=0, j, k=2, w, z, m=niz[0]; /* {0} znaci da su svi clanovi jednaki 0*/
	for (i=0; i<n; i++)
	{
		if (m<niz[i])
		{
			m=niz[i];
		}
	}
	MAX=m; /*Najveci broj u nizu. Da ne bi doslo do opterecenja programa dovoljno je da najveci Fibonaccijev broj bude jednak najvecem clanu, ali da ne bude veci od najveceg clana niza*/
	niz1[0]=1; niz1[1]=1; /*Prva 2 clana Fibonaccijevog niza su 1 i 1*/
	for (j=2; j<1111; j++) /*Buduci da imamo prva 2 clana pocinjemo sa brojacem j=2*/
	{
		niz1[j]=niz1[j-2]+niz1[j-1];
		k++;
		if (niz1[j]>MAX)
		{
			break;
		}
	}
		k--;
		w=n;
		i=0;
		for (i=0; i<w; i++)
		{
			for (j=1; j<k; j++)
			{
				if (niz[i]==niz1[j])
				{
					for (z=i; z<w-1; z++)
					{
						niz[z]=niz[z+1];
					}
						w--;
						i--;
						break;
				}
			}
		}
			return w;
		
}

int main() {
	int niz[20], i, n=10, a, b;
	/*n=10 jer unosimo niz od 10 clanova, dok je niz[20] jer ce se u funkciji ubaci nakon svakog originalnog clana ubaciti jos jedan clan*/
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<n; i++)
	{
		scanf ("%d", &niz[i]);
	}
	ubaci (niz, n);
	a=2*n; /*Velicina niza ce biti duplo veca nakon ubacivanja clanova*/
	b=izbaci (niz, a);
	printf ("Modificirani niz glasi: "); /*Nakon izvrsenja funkcija*/
	for (i=0; i<b-1; i++) /*Izvrsava se do b-1 da se ne bi ispisalo nesto tipa "4, 4, 6, 6, "*/
	{
		printf ("%d, ", niz[i]); 
	}
	printf ("%d.", niz[i]); /*U for petlji smo isli do predzadnjeg clana, pa je potrebno posljednji clan ispisati posebno*/
	return 0;
}
