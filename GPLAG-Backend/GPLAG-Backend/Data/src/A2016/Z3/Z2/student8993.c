#include <stdio.h>
#include <stdlib.h>

void ubaci(int* niz, int vel)
{
	int *pom=niz;
	int i;
	for(i=vel-1; i>=0; i--)
	{
		*(pom+2*i)=*(pom+i);
	}
	for(i=0; i<2*vel-1; i+=2)
	{
	
		
		int suma=0;
		int x=niz[i];
		while(x!=0)
		{
			int cifra=x%10;
			suma+=cifra;
			x/=10;
		}
		niz[i+1]=abs(suma);
		
		
	}
}
int fibonacijev(int broj)
{
	

	int broj1=0;
	int broj2=1;
	int fib=0;
	if(broj==0) return 0;
	for(;;)
	{
		if(fib>=broj) break;
		fib=broj1+broj2;
		broj1=broj2;
		broj2=fib;
	}
	if(fib==broj) return 1;
	else return 0;
	
}
int izbaci(int *niz, int vel)
{
	int nova=vel;
	int i;
	int j;
	for(i=0;i<nova; i++)
	{
		if(fibonacijev(niz[i])==1)
		{
		for(j=i; j<nova-1;j++)
		{
			niz[j]=niz[j+1];
		}
		i--;
		nova--;	
		}
	}
	return nova;
}

int main() {
	int niz[20];
	int i;
	int nova;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	nova=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<nova-1; i++)
	{
		printf("%d, ",niz[i]);
	}
	printf("%d.",niz[nova-1]);
	


	

	return 0;
}
