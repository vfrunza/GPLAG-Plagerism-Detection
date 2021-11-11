#include <stdio.h>
#include <math.h>
void zaokruzi1(float *p1, int n)
{
	int i;
	for (i=0; i<n; i++) {
		*(p1+i)=round((*(p1+i)) * 10.0)/10.0;
	}
}
void preslozi(float *p1, int n, int k)
{
	int i, suma,broj,brojac=0,cifra;
	double pom[100];
	zaokruzi1(p1,n);
	for(i=0; i<n; i++) {
		suma=0;
		broj=(*(p1+i))*10;
		while(broj!=0) {
			cifra=broj%10;
			if(cifra<0) cifra*=-1;
			suma+=cifra;
			broj/=10;
		}
		if(suma>=k) {
			pom[brojac]= *(p1+i);
			brojac++;
		}
	}
	for(i=0; i<n; i++) {
		suma=0;
		broj=(*(p1+i))*10;
		while(broj!=0) {
			cifra=broj%10;
			if(cifra<0) cifra*=-1;;
			suma+=cifra;
			broj/=10;
		}
		if(suma<k) {
			pom[brojac]= *(p1+i);
			brojac++;
		}
	}
	for(i=0; i<brojac; i++) {
		(*(p1+i))=pom[i];
	}
}
int main()
{
	int i;
	float niz[]= {13.1, 15.749999, 15.75 ,9.222 ,78.1};
	preslozi(niz,5,14);
	printf("Niz glasi: ");
	for(i=0; i<5; i++)
		printf("%g ", niz[i]);
	return 0;
}