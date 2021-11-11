#include <stdio.h>
#include <stdlib.h>

int suma_cif(int broj)
/* Funkcija izracunava sumu cifara cijelog broja */
{
	int suma=0, zad_cif=0;
	int nov_broj=0;
	
	if(broj<0) nov_broj=broj*(-1);
	else nov_broj=broj;
	do
	{
		zad_cif=nov_broj%10;
		nov_broj=nov_broj/10;
		
		suma+=zad_cif;
	} while(nov_broj!=0);
	return suma;
}

void ubaci(int* pok_niz, int vel_niz)
/* Funkcija ubacuje nove clanove niza 
   koji su jednaki zbiru cifara prethodnog clana niza */
{
	int  i, j, zbir=0;
	
	for(i=0; i<2*vel_niz; i+=2)
	{
		zbir=suma_cif(pok_niz[i]);
		for(j=2*vel_niz-1; j>i+1; j--)
		{
			pok_niz[j]=pok_niz[j-1];
		}
		pok_niz[i+1]=zbir;
	}
}

int prov_fibon(int broj)
/* Funkcija provjerava da li je broj clan Fibonaccijevog niza */
{
	int fibon[3]; 
	
	if(broj<=0) return 0;
	if(broj==1) return 1;
	
	fibon[0]=1;
	fibon[1]=1;
	do
	{
		fibon[2]=fibon[0]+fibon[1];
		if(fibon[2]==broj) return 1;
		else
		{
			fibon[0]=fibon[1];
			fibon[1]=fibon[2];
		}
	} while(fibon[2]<broj);
	return 0;
}

int izbaci(int* pok_niz, int vel_niz)
{
	int i, j;
	/* Izbacivanje Fibonaccijevih clanova iz niza */
	for(i=0; i<vel_niz; i++)
	{
		if(prov_fibon(pok_niz[i]))
		{
			for(j=i; j<vel_niz-1; j++)
			{
				pok_niz[j]=pok_niz[j+1];
			}
			vel_niz--;
			i--;
		}
	}
	return vel_niz;
}

int main() 
{
	int niz[20]={0};
	int i, j, vel_niz=0;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d", &niz[i]);

	ubaci(niz, i);
	vel_niz=izbaci(niz, 2*i);
	
	printf("Modificirani niz glasi: ");
	for(j=0; j<vel_niz-1; j++)
		printf("%d, ", niz[j]);
	
	printf("%d.", niz[vel_niz-1]);
	return 0;
}
