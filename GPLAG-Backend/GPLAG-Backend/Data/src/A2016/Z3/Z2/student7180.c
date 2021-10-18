#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int suma_cifara(int n)
{
	int suma=0;
	if(n<0)
	n=(-1)*n;
	while(n!=0)
	{
		suma+=n%10;
		n/=10;
	}
	return suma;
}

void ubaci(int niz[], int n)
{
int i;
int j;
int x=2*n-2;
for(j=n-1; j>0; j--)
	{
		niz[x]=niz[j];
		x-=2;
	}
for(i=1; i<2*n; i+=2)
	{
		niz[i]=suma_cifara(niz[i-1]);
	}
}

bool jel_fibonacci(int n)
{
	int a=0;
	int b=1;
	int c=a+b;
	while(c<n)
	{
		a=b;
		b=c;
		c=a+b;
	}
	if(c==n)
	return true;
	return false;
}

int izbaci(int niz[], int n)
{
	int x;
	int counter=0;
	int c=n-1;
	int i, j;
	for(i=n-1; i>=0; i--)
	{
		if(jel_fibonacci(niz[i]) && niz[i]>0)
		{
			for(x=i; x<c; x++)
			{
				niz[x]=niz[x+1];
			}
			c--;
		}
	}
	if(c<0) return 0;
	for(j=0; j<c; j++)
	counter++;
	return counter+1;
}

int main() {
	int i;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	scanf("%d %d %d %d %d %d %d %d %d %d", &niz[0], &niz[1], &niz[2], &niz[3], &niz[4], &niz[5], &niz[6], &niz[7], &niz[8], &niz[9]);
	ubaci(niz,10);
	int x=izbaci(niz,20);
	int j;
	printf("Modificirani niz glasi: ");
	for(i=0; i<x-1; i++)
	printf("%d, ", niz[i]);
	for(i=x-1; i<x; i++)
	printf("%d.", niz[i]);
	return 0;
}
