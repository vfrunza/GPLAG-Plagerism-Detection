#include <stdio.h>
#include <stdlib.h>

void ubaci(int *niz,int n)
{
	int i,suma,a,cif;
	for(i=(n-1)*2;i>=2;i=i-2)
	{
		niz[i] = niz[i/2];
	}
	for(i=1;i<=2*n-1;i=i+2)
	{
		suma=0;
		a=niz[i-1];
		while(a!=0)
		{
			cif=a%10;
			a=a/10;
			suma += abs(cif);
		}
		niz[i]=suma;
	}
}


int izbaci(int *niz, int n)
{
	int i,j1,j2,temp,fib,k,v;
	v=n;
	for(i=0;i<v;i++)
	{
		fib=0;
		j1=1;
		j2=1;
		if(niz[i]==1)
		{
			fib=1;
		}
		while(j1<niz[i])
		{
			temp=j1;
			j1 = j2;
			j2 += temp;
			if(niz[i]==j1)
			{
				fib=1;
			}
		}
		if(fib==1)
		{
			for(k=i;k<v-1;k++)
			{
				niz[k] = niz[k+1];
			
			}
			i--;
			k--;
			v--;
		}
	}
	return v;
}


int main() 
{
	int i,niz[100],br;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	br = izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<br;i++)
	{
		if(i!=br-1)
		{
			printf("%d, ",niz[i]);
		}
		else printf("%d.",niz[i]);
	}
	return 0;
}
