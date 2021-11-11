#include <stdio.h>
#include <stdlib.h>

void ubaci(int *niz,int n){
	int i,j,suma=0,broj,cifra;
	for(i=0;i<n;i++)
	{
		suma=0;
		broj=abs(*(niz+i));
		while(broj!=0)
		{
			cifra=broj%10;
			suma=suma+cifra;
			broj=broj-cifra;
			broj=broj/10;
		}
		for(j=n-1;j>i;j--)
		{
			niz[j+1]=niz[j];
		}
		n++;
		i++;
		niz[i]=suma;
	}
} 


int fibonacijevi(int n){
	int nizf[50]={1,1,2};
	int i=2;
	for(i=2;i<50;i++){
		nizf[i]=nizf[i-1]+nizf[i-2]; /* formula za racunanje fibonacijevih clanova*/
	}
	i=0;
	while(i<50){
		if(nizf[i]==n){
			return 1; /* provjera da li je fibonacijev broj */
			i++;
		}
	}
	return 0;
}

int izbaci(int *niz,int n)
{
	
	int i,k;
	for(i=0;i<n;i++)
	{
		if(fibonacijevi(*(niz+i))==1)
	{
		for(k=i;k<n-1;k++)
		{
			niz[k]=niz[k+1]; /*izbacivanje clanova*/
		}
		i--; /*smanjivanje indeksa u nizu*/
		k--; 
	}
	}
	return n;
}

int main() 
{
	int niz[20];
	int i;
	int n=10;
	int t;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);	
	}
	ubaci(&niz[0],n);
	n=20;
	
	t=izbaci(&niz[0],n);
	n=t;
	printf("Modificirani niz glasi: ");
	for(i=0;i<n-1;i++)
	{    
		printf("%d, ",niz[i]);
	}
	printf("%d.",niz[n-1]);
	return 0;
}
