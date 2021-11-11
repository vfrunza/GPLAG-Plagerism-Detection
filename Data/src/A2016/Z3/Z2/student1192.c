#include <stdio.h>
#include <stdlib.h>

int zbir_cifara(int broj) /*funkcija racuna zbir cifara cijelih brojeva*/
{
	int cifra, suma;
	suma=0;
     while(broj>0)
		{
			cifra=broj%10;
			broj=broj/10;
			suma=suma+cifra;
		}	
		return suma;
}

void ubaci (int niz[],int velicina) /*funkcija prima niz i u njega ubacuje zbir cifara svakog od clanova */
{
	int i;
    int pomocni[100];
for(i=0;i<velicina; i++)
{
	pomocni[i]=niz[i];
}
	
	for(i=0; i<2*velicina; i++)
	{
		if(i==0)
		continue;
		else if(i==1)
		niz[i]=zbir_cifara(abs (niz[0]));
		else if ((i%2)==0)
		niz[i]=pomocni[i/2];
		else if ((i%2)==1)
		niz[i]=zbir_cifara(abs(niz[i-1]));
		
	}
}

int izbaci (int niz[], int velicina) /*funkcija izbacuje sve clanove niza koji su clanovi Fibonaccijevog niza*/
{
	int i, j,k,  fib[100];
	for(i=0;i<100; i++) /*U niz f program ubacuje clanove Fibonaccijevog niza*/
	{
		if((i==0)||(i==1))
		fib[i]=1;
		else 
		fib[i]=fib[i-1]+fib[i-2];
	}
	
	for(i=0;i<velicina; i++)
	{
		for(j=0; j<100; j++)
		{
		if((niz[i])==fib[j])
		{
			for(k=i;k<(velicina-1); k++)
			{
			niz[k]=niz[k+1];
			}
			velicina--;
			i--;
		break;
		}
		}
	}
	return velicina;
}

int main() {
	int niz [20], velicina, i;
	/*ulaz*/
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
	scanf("%d", &niz[i]);
	
	ubaci(niz, 10);
	velicina=izbaci(niz, 20);
	
	/*izlaz*/
	printf("Modificirani niz glasi: ");
	for(i=0; i<(velicina-1); i++)
	printf("%d, ", niz[i]);
	printf("%d.", niz[(velicina-1)]);
	return 0;
}
