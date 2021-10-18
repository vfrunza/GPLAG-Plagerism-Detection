#include <stdio.h>
#include <stdlib.h>

int dajSumu(int broj)
{
	int suma=0;
	broj=abs(broj);
	while(broj)
	{
		suma+=broj%10;
		broj/=10;
	}
	
	return suma;
}

void ubaci(int *niz, int vel)
{
	int i,j,k=0;
	for(i=0;i<2*vel;i+=2)
	{
		for(j=vel+k;j>i;j--)
		{
			niz[j]=niz[j-1];
		}
		niz[i+1]=dajSumu(niz[i]);
		k++;
	}
}

int jeLiFib(int broj)
{
	int a=1, b=1, c;
	if(broj==1) return 1;
	do
	{
		c=a+b;
		a=b;
		b=c;
	}while(c<broj);
	if(broj==c) return 1; else return 0;
}

int izbaci(int *niz, int vel)
{
	int i,j;
	for(i=0;i<vel;i++)
	{
		if(jeLiFib(niz[i]))
		{
			for(j=i;j<vel-1;j++)
			{
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}

	return vel;
}

int main() {
	int niz[20],i,k;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	k=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<k; i++)
	{
		printf("%d",niz[i]);
		if(i==k-1) printf("."); else printf(", ");
	}
	return 0;
}
