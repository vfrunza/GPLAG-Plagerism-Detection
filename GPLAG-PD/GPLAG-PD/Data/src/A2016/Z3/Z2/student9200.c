#include <stdio.h>

int suma(int broj)
{
	int suma=0;
	if(broj<0) broj*=-1;
	while(broj>0)
	{
		int i=broj%10;
		suma+=i;
		broj/=10;
	}
	return suma;
}

void ubaci(int *niz, int duzina)
{
	int i=0;
	for (i=0;i<duzina;i++)
	{
		int j;
		for(j=duzina;j>i;j--)
		{
			niz[j]=niz[j-1];
		}
		duzina++;
		i++;
		niz[i]=suma(niz[i-1]);
	}
}


long fibonaci(int i)
{
	static long f1=1, f2=1;
	long f;
	
	f=(i<3) ? 1: f1+f2;
	f2=f1;
	f1=f;
	return f;
}
int dalifibonaci(int i)
{
	int f1=1,f2=1;
	for(;;)
	{
		if(f2>i) return 0;
		if(f2==i) return 1;
		int temp=f2;
		f2=f2+f1;
		f1=temp;
	}
}
int izbaci(int *b, int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(dalifibonaci(b[i]))
		{
			for(j=i;j<n-1;j++)
			{
			b[j]=b[j+1];
			}
		n--;
		i--;
		}
	}
	return n;
}

int main() {
	int niz[20];
	int i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	int velicina=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<velicina-1;i++)
	{
		printf("%d, ",niz[i]);
	}
	if(i==velicina-1) printf("%d.",niz[i]);
	return 0;
}
