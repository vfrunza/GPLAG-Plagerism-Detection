#include <stdio.h>

int sumacifara(int n)
{
	int suma=0,cifra;
	while(n>0)
	{
		cifra=n%10;
		suma=suma+cifra;
		n/=10;
	}
	return suma;
}

void ubaci (int *niz, int n)
{
	int i,k,a; 
	for(i=2*n-1;i>=0;i--)
	{
		k=i/2;
		niz[i]=niz[k];
	}
	for(i=0;i<2*n;i++)
	{
		if(i%2==0)
		{
			a=sumacifara(niz[i]);
		
		}
		if(i%2!=0)
		{
			niz[i]=a;
			
		}
	}
}


int Fibonacci (int n)
{
	int i,niz[20];
	for(i=0;i<20;i++)
	{
		if(i==0) 
		{
			niz[0]=0;
		}	
		else if(i==1) 
		{
			niz[1]=1;
		}	
        else if(i!=0 && i!=1)
		{
			niz[i]=niz[i-1]+niz[i-2];
		}	
	}
	for(i=0;i<20;i++)
	{
		if(n==niz[i]) return 1;
	}
	return 0;

}


int izbaci (int *niz, int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
	   if(Fibonacci(niz[i])) 
	   {
	   	for(j=i;j<n-1;j++)
	     {
	     	niz[j] = niz[j+1];
	     } 
	    n--;
	   	i--;
	   }
	}
	return n;
}

int main() {
	int i,a;
	int niz[10];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	a = izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	
	for(i=0;i<a;i++)
	{
		if(i==a-1)
		printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}
	
	
	return 0;
}
