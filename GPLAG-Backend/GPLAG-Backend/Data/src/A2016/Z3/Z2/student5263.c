
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int square(long int x)
{
	long int k;
	k=sqrt(x);
	if(pow(k,2)==x)	{return 1;}
	else {return 0;}
}
int zbir(int x)
{
	int y,S=0;
	do {
		y=abs(x)%10; /*abs je u slucaju da je broj neg*/
		x=abs(x)/10;
		S=abs(y)+S;
	} while(x>0);
	return S;
}
/* Cilj funkcije ubaci: "uduplamo" niz, pa onda te vrijednosti koje smo dodali pretvorimo u zbir cifara*/
void ubaci(int *niz,int n)
{
	int i,j,r;
	i = n-1;
	while(i>=0) {
		j = n-1;
		while(j>=i) {
			*(niz+j+1)=*(niz+j);
			j--;
		}
		n=n+1; /* Povecava se velicina niza za 1*/
		i--;
	}
	i = 0;
	while(i<n) {
		if(i%2==1)
			*(niz+i)=zbir(*(niz+i));
			i++;
	}
}
int fibonachi(long int x)
{
	long int a = 5*x*x+4;
	long int b = 5*x*x-4;
	if(square(b)==1 || square(a)==1) {return 1;}
	else {return 0;}
}
int izbaci(int *niz,int n)
{
	int i,j;
	i = 0;
	while(i<n) {
		if(fibonachi(*(niz+i))==1 && *(niz+i)>0) {
			j = i;
			while(j<n-1) {
				*(niz+j)=*(niz+j+1);
				j++;
			}
			i= i -1;
			n= n -1;
			if(n==0)
			break;
		}
		i++;
	}
	return n;
}
int main()
{
int niz[20],i;
printf ("Unesite niz od 10 brojeva: ");
i = 0;
while (i<=9)
{scanf ("%d",&niz[i]); i++;}
/* Prvo pozivamo funkciju ubaci pa tek onda izbaci jer ona na kraju "filtrira" i Fibonachija i zbir cifara*/
ubaci (niz,10); /* ubacujemo */
int x=izbaci(niz,20); /*izbacujemo */
printf("Modificirani niz glasi: ");
i = 0;
while (i<x){
   printf("%d",niz[i]); 
   if (i == (x-1)){printf(".");} else printf(", "); i++;} /* samo na zadnji clan koji je odredjen sa x-1 stavljamo tacku */
	return 0;
}  