#include <stdio.h>
#include <stdlib.h>
int suma(int n)/* Funkcija koja racuna sumu cifara broja*/
{
	int s=0;
	while(n>0)
	{
		s=s+n%10;
		n=n/10;
	}
	return s;
}
void ubaci(int niz[],int velicina)
{
	int *q,*p; /*pokazivaci koji uzimaju clan niza i sumu cifara clana*/
	int i,z;
	for(i=velicina -1;i>=0;i=i-1)
	{
		p=niz+i*2;
		q=niz+i;
		*p=*q;
	}
	for(i=0;i<2*velicina;i=i+2)
	{
		p=niz+i;
		q=p+1;
		z=abs(*p);
		*q=suma(z);
	}
}
int izbaci(int niz[], int velicina)
{
	int fib[1000]={0};/*deklaracija Fibornacijevog niza*/
	int maks,t=2,i,j,z,v2;
	maks=niz[0];
	for(i=0;i<velicina;i++)
	if (maks<niz[i]) maks=niz[i];/*najveci clan niza*/
	fib[0]=1; fib[1]=1;/*po definiciji prvi i drugi clan Fib. niza*/
	for(i=2;i<1000;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>maks) break;
		else (t++);/*racunanje broja elemenata Fib. niza*/
	}
	v2=velicina;
	for(i=0;i<v2;i++)
	{
		for(j=0;j<t;j++)
		{
			if(niz[i]==fib[j])
			{
				for(z=i;z<v2-1;z++)/*Izbacanje elemenata iz niza koji se nalaze u Fib. nizu*/
				niz[z]=niz[z+1];
				v2--;
				i--;
				break;
			}
		}
	}
return v2;
}
int main() {
	int niz[20],i,velicina=10,izb;
	printf("Unesite niz od 10 brojeva: ");/*unos niza*/
	for(i=0;i<10;i++)
	scanf("%d",&niz[i]);
	ubaci(niz,velicina);/*pozivanje ubacivanja sume svakog clana zasebno na mjesto poslije clana*/
	velicina=velicina*2;
	izb=izbaci(niz,velicina);/*pozivanje izbacivanja elemenata niza*/
	printf("Modificirani niz glasi: ");
	for(i=0;i<izb-1;i++){
	printf("%d, ",niz[i]);
	}
	printf("%d.",niz[i]);
	return 0;
}