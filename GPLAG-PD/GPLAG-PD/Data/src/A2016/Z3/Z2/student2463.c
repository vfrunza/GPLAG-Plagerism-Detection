#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void ubaci (int p[],int brojac)
{
	int i, sum, n;

	for(i=brojac-1; i>0; --i) {
		p[2*i]=p[i];
	}
	for(i=0; i<(2*brojac)-1; ++i) {
		n=(int)fabs((float)p[i]);
		sum=0;
		while(1) {

			sum=sum+(n%10);
			if((n/10)==0)
				break;
			n=n/10;
		}
		i++;
		p[i]=sum;
	}
	brojac=brojac*2;
}
int izbaci(int p[],int brojac)
{
	int a1=1, a2=1, i, j, pom;

	for(i=0; i<brojac; i++) {
		a1=1;
		a2=1;
		while(1) {
			if(p[i]==a2) {
				for(j=i; j<(brojac-1); ++j) {
					p[j]=p[j+1];
				}
				brojac--;
				i--;
				break;
			}
			if(a2>p[i])
				break;

			pom=a2;
			a2=a1+a2;
			a1=pom;
		}
	}
	return brojac;
}
int main()
{

	int i=0, x, polje[20];
	char c;
	int brojac=0;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d ", &polje[i]);
		brojac++;
	}
	ubaci (polje,brojac);

	x=izbaci(polje,brojac);
	printf("Modificirani niz glasi: ");
	for(i=0; i<x; i++) {
		printf("%d", polje[i]);
		if(i<x-1)
			printf(", ");
		if(i==x-1)
			printf(".");
	}
	return 0;
}
