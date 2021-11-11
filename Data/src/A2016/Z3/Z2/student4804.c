#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int suma(int x)
{
	int y,s=0;
	do {
		y=abs(x)%10;
		x=abs(x)/10;
		s=s+abs(y);
	} while(x>0);

	return s;
}

void ubaci(int *niz,int n)
{
	int i,j;

	for(i=n-1; i>=0; i--) {

		for(j=n-1; j>=i; j--) {
			*(niz+j+1)=*(niz+j);
		}
		n++;

	}
	

	for(i=0; i<n; i++) {
		if(i%2==1)
			*(niz+i)=suma(*(niz+i));
	}
}

int fib(int x)
{
	int y1=1,y2=1,yz;
	do
	{
	yz=y1+y2;
	y1=y2;
	y2=yz;
	}
	while (yz<x);
	
	if(yz==x || x==1)
	return 1;
	else
	return 0;
}


int izbaci(int *niz,int n)
{
	int i,j;
	for(i=0; i<n; i++) {
		if(fib(*(niz+i))==1 && *(niz+i)>0) {
			for(j=i; j<n-1; j++) {
				*(niz+j)=*(niz+j+1);
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
	int niz[20]= {0},i,*pniz=&niz[0],n;

	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d",&niz[i]);

	ubaci(pniz,10);
	n=izbaci(pniz,20);

	printf("Modificirani niz glasi: ");
	for(i=0; i<n; i++) {
		printf("%d",niz[i]);
		if(i!=n-1)
			printf(", ");
		else
			printf(".");
	}
	return 0;
}
