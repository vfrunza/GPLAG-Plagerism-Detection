#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int suma(int broj)
{
	broj=fabs(broj);
	int c;
	int suma=0;
	while(broj!=0) {
		c=broj%10;
		suma=suma+c;
		broj=broj/10;
	}
	return suma;
}

void ubaci(int *niz,int n)
{
	int i,j ;

	for(i=n-1; i>=0; i--) {
		for(j=n-1; j>=i; j--) {
			*(niz + j + 1)=*(niz +j);
		}
		n++;
	}
	for(i=1; i<n; i+=2) {
		*(niz + i)=suma(*(niz+i-1));
	}
}

int square(long int x)
{
	long int k;
	k=sqrt(x);
	if(k*k==x) {
		return 1;
	} else {
		return 0;
	}
}

int Fibonacci(long int x)
{
	long int a = 5*x*x+4;
	long int b = 5*x*x-4;
	if(square(b)==1 || square(a)==1) {
		return 1;
	} else {
		return 0;
	}
}

int izbaci(int *niz,int n)
{
	int i ,j;
	for(i=0; i<n; i++) {
		if(Fibonacci(*(niz+i))==1 && *(niz+i)>0) {
			for(j=i; j<n-1; j++) {
				*(niz+j)=*(niz+1+j);
			}
			i--;
			n--;
			if(n==0)
				break;
		}
	}
	return n;
}

int main()
{
	int niz[20],i;
	printf("Unesite niz od 10 brojeva:");
	for(i=0; i<10; i++) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	int x;
	x=izbaci(niz,20);
	printf(" Modificirani niz glasi: ");
	for(i=0; i<x; i++) {
		printf("%d",niz[i]);
		if(i==(x-1)) {
			printf(".");
		} else {
			printf(", ");
		}
	}


	return 0;
}
