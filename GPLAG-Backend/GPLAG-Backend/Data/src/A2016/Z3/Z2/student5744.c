#include <stdio.h>
#include <stdlib.h>

void ubaci(int* p,int n)
{
	int i;
	int temp,suma;
	//Pomjera clanove da bi bilo mjesta za dodane
	for(i=n-1;i>0;i--)
	{
		p[2*i]=p[i];
	}
	//Dodaje clanove
	for (i=0;i<2*n;i+=2)
	{
		suma=0;
		if(p[i]>=0)
			temp=(p[i]);
		else
			temp=-p[i];
		while(temp>0)
		{
			suma+=temp%10;
			temp/=10;
		}
		p[i+1]=suma;
	}
}
int izbaci(int *p,int n)
{
	int i,j,k;
	int fib[87];
	fib[0]=1;
	fib[1]=1;
	for(i=0;i<n;i++)
	{
		j=1;
		//Provjerava da li je broj fibonccijev, ako jeste izbacuje ga
		while(p[i]>=fib[j])
		{
			if(p[i]==fib[j])
			{
				for(k=i;k<n-1;k++)
				{
					p[k]=p[k+1];
				}
				i--;
				n--;
				break;
			}
			fib[j+1]=fib[j]+fib[j-1];
			j++;
		}
	}
	return n;
}

int main()
{
	int i,l;
	int niz[20]={0};
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	l=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<l;i++)
	{
		printf("%d",niz[i]);
		if(i==l-1)
		{
			printf(".");
		}
		else
		{
			printf(", ");
		}
	}
	return 0;
}