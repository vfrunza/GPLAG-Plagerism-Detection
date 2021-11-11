#include <stdio.h>
#include <math.h>

int Izracunaj_Sumu (int n) {
	int suma=0;
	if (n<0)
	n*=-1;
	while (n!=0) {
		suma+=n%10;
		n/=10;
	}
	return suma;
}

void ubaci (int niz[], int n) {
	int i=0,j=0,brojac=n+1,suma;
	for (i=0; i<2*n-1; i+=2) {
		suma=Izracunaj_Sumu(niz[i]);
		for (j=brojac-1;j>i;j--) {
			niz[j]=niz[j-1];
		}
		niz[j+1]=suma;
		brojac++;
	}
}

int Da_Li_Je_Fibonacijev (int n) {
	int a,b,c;
	a=0;
	b=1;
	c=a+b;
	while(c<n) {
		a=b;
		b=c;
		c=a+b;
		
	}
	if (c==n)
	   return 1;
	return 0;
}

int izbaci (int niz[],int n) {
	int brojac,j,i;
	brojac=n;
	for (i=0; i<n; i++)	{
		if (Da_Li_Je_Fibonacijev(niz[i])) {
			for (j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
			}
		i--;
		n--;
		brojac--;
		}
	}
	return brojac;
}

int main() {
	int niz[20],duzina,i;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	duzina=izbaci(niz,20);
	izbaci(niz,20);
	printf ("Modificirani niz glasi: ");
	for (i=0; i<duzina; i++) {
		if (i==duzina-1)
		printf ("%d.",niz[i]);
		else
		printf ("%d, ",niz[i]);
	}
	return 0;
}