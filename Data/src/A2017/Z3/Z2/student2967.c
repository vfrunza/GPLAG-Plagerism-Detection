#include <stdio.h>

int jeLiFib(int n)
{
	int a=1,b=1,c=0;
	
	while(c<n)
	{
		c=a+b;
		a=b;
		b=c;
	}
	
	if((c==n ||n==1) && c!=0)
		return 1;
	else return 0;
}

int izbaci(int niz[], int n)
{
	int i,j; 
	
	for(i=0;i<n;i++)
	{
		if(jeLiFib(niz[i])==1)
		{
			for(j=i;j<n-1;j++)
			{
				niz[j]=niz[j+1];
				
			}
			n--;
			i--;
		}
	}
	
	return n;	
}


int sumaCifara(int n)
{
	int suma=0;
	if(n<0) n*=-1;
	
	while(n>0)
	{
		suma+=n%10;
		n/=10;
	}
	
	return suma;
	
}

void pomjeri(int niz[],int n,int i)
{
	int j;
	
	for(j=n;j>i;j--)
	{
		niz[j]=niz[j-1];
	}
}


int ubaci(int niz[], int n)
{
	int i,vel=n;
	
	for(i=0;i<2*vel;i++)
	{
		if(i%2!=0)
		{
			pomjeri(niz,n,i);
			n++;
			niz[i]=sumaCifara(niz[i-1]);
		}
	}
	
	return n;
}


int main() {
	
	int niz[20];
	int i;
	int n;

	n=20;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	
	n=10;
	
	n=ubaci(niz,n);
	n=izbaci(niz,n);
	printf("Modificirani niz glasi: ");
	for(i=0;i<n;i++)
	{
		printf("%d",niz[i]);
		if(i<n-1)printf(", ");
		else printf(". ");
	}
	

	return 0;
}
