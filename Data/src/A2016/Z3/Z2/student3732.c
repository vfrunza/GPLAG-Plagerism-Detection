#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#define broje_elemenata 10
void ubaci(int *niz, int duzina_niza)
{
	int i,broj,broj2=0,cifra;
	for(i=duzina_niza-1;i>=0;i--)
	{
		niz[2*i]=niz[i];
	}
	for(i=0;i<2*duzina_niza;i+=2)
	{
		broj=abs(niz[i]);
		if(broj<10)
		{
			broj2=broj;
		}
		else
		{
			do
			{
				cifra=broj%10;
				broj2=broj2+cifra;
				broj=broj/10;
			}while(broj!=0);
		}
		niz[i+1]=broj2;
		broj2=0;
	}
}
/*funkcija treba vratiti broj elmenata*/
int izbaci(int *niz,int duzina_niza)
{
	/*fibonacijevi brojevi*/
	int prvi,drugi,treci;
	int i,j,k;
	for(k=0;k<duzina_niza;k++)
	{
		prvi=0;
		drugi=1;
		for(i=1;i<10000;i++)
		{
			
			if(i==1)
			{
				treci=1;
			}
			else
			{
				treci=prvi+drugi;
				prvi=drugi;
				drugi=treci;
			}
			if(niz[k]==treci)
			{
				for(j=k;j<duzina_niza-1;j++)
				{
					niz[j]=niz[j+1];
				}
				duzina_niza--;
				k--;
				break;
			}
		}
	}	
	return duzina_niza;
}

int main() {
	int niz[2*broje_elemenata],i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,broje_elemenata);
	int funkcija;
	funkcija=izbaci(niz,2*broje_elemenata);
	printf("Modificirani niz glasi: ");
	for(i=0;i<funkcija;i++)
	{
		if(i==funkcija-1)
		{
			printf("%d.",niz[i]);
		}
		else
		{
			printf("%d, ",niz[i]);
		}
	}
	return 0;
}
