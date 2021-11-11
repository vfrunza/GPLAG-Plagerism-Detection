#include <stdio.h>
#include <stdlib.h>

int suma (int k)
{
	int suma=0;
	while(k>0) //fukcija koja odredjuje sumu cifara svakog broja u nizu
	{
		suma+=k%10;
		k/=10;
	}	
	return suma;
}

void ubaci (int *niz, int velicina)
{
	int i,novi[1000],j=0,broj=0;
	
	for(i=0; i<velicina; i++) //u funkciji se pravi novi niz u koji ce se ubaciti i suma cifri 
	{
		novi[j]=niz[i];
		j++;
		broj=niz[i];
		if (broj<0) //osigurava da se sabiraju pozitivne cifre 
		{
			broj*=-1;
		}
		novi[j]=suma(broj);
		j++;
	}
	
	for (i=0; i<2*velicina; i++)
	{
		niz[i]=novi[i];
	}
	
}

int fibniz (int br)
{
	int a=1, b=1, c=2; //fukcija ispituje da li je broj clan fibonaccijevog niza

	if (br==1)
	{
		return 1;
	}
	if (br<1)
	{
		return 0;
	}
	
	while(c<br) 
	{
		c=a+b;
		a=b;
		b=c;
	}
	
	if (c==br)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int izbaci (int *niz2, int velicina)
{
	int i=0,j,novi[1000];
	int *niz;

	niz=niz2;

	while (niz<niz2+velicina) //ukoliko je clan niza[i] jednak nekom clanu fibonaccijevog niza, izbacuje se
	{
		if (fibniz(*niz)==0)
		{
			novi[i]=*niz;
			i++;
		}
		niz++;
	}

	niz=niz2;

	for (j=0; j<i; j++)
	{
		*niz=novi[j];
		niz++;
	}
	return i; //vraca vrijednost novog niza iz kojeg su izbaceni clanovi 
}

int main() 
{
	int niz[1000],i,velicina=10,p=0;

	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++)
	{
		scanf ("%d", &niz[i]);
	}
	
	ubaci(niz,velicina);
	
	velicina*=2;
	p=izbaci(niz,velicina);
	
	printf("Modificirani niz glasi: ");
	for (i=0; i<p; i++) //ispisuje dobijeni niz, a duzina novog niza nije pocetna velicina vec velicina niza nakon sto se obje funkcije izvrse
	{
		if (i<=p-2) //ispituje da li je clan posljednji kako bi se ispisali zareci i tacka
		{
		printf("%d, ", niz[i]);
		}
		else
		{
		printf ("%d.", niz[i]);
		}
	}

	return 0;
}
