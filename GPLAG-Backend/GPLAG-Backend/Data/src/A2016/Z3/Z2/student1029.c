#include <stdio.h>

int cifre(int n)
{
	int suma=0;
	if(n<0) n=-n; /*za negativne brojeve*/
	
	while(n>0)
	{
		suma+=n%10; /*rastavljane broja na cifre i sabiranje njegovih cifara*/
		n/=10; /*sljedeca cifra*/
	}
	
	return suma;
}

void ubaci(int *niz, int n)
{
	int niz2[100];
	int i=0;
	
	for(i=0;i<n;i++)
	{
		niz2[i*2]=niz[i]; /*na parnim indeksima stari niz*/
		niz2[i*2+1]=cifre(niz[i]); /*ubacujemo izmedju elemenata starog niza sumu njegovuh cifara, na neparnim indeksima*/
	}

	for(i=0;i<2*n;i++) niz[i]=niz2[i]; /*niz nakon ubacivanja*/
}

int fibonacijev(int n)
{
	int a[100]={1,1,2}; /*prva tri broja Fibonacijevog niza*/
	int i=2; /* krecemo od elementa u nizu sa indeksom 2*/
	
	do{
		i++; /*povecavamo indeks*/
		a[i]=a[i-1]+a[i-2]; /*novi element je suma prethodna dva*/
	}while(a[i]>0);
	
	for(;i>=0;i--)
	{
		if(n==a[i]) return 1; /*broj je Fibonacijev*/
	}
	
	return 0;
}

int izbaci(int *niz, int n)
{
	int niz2[100];
	int i=0,j=0;
	
	for(i=0;i<n;i++)
	{
		if(fibonacijev(niz[i])==0) niz2[j++]=niz[i]; /*Ako broj nije Fibonacijev dodajemo ga u novi niz, j++ nam povecava indeks*/
	}

	
	for(i=0;i<j;i++)
	{
		niz[i]=niz2[i]; /*Niz nakon izbacivanja*/
	}
	
	return j;
}

int main()
{
	int niz[100];
	
	int i;
	int n=20;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}

	ubaci(niz, 10);
	n=izbaci(niz, 20);

	if(n==0) printf("Prazan niz.\n"); /*Ukoliko nam ne ostane nijedan element u nizu nakon izbacivanja*/
	else
	{
		printf("Modificirani niz glasi: ");
		printf("%d", niz[0]);
		
		for(i=1;i<n;i++)
		{
			printf(", %d", niz[i]);
		}
		
		printf(".");
	}
	

	return 0;
}