#include <stdio.h>
#include <stdlib.h>
int sum(int br)
{
	int suma=0,cifra=0;
	while(br>0)
	{
		
		cifra=br%10;
		suma+=cifra;
		br=br/10;
	}
	return suma;
}
void ubaci(int p[],int n)
{
	int *q,*z;
	int i=2*n;
	int k;
	for(i=n-1;i>=0;i-=1)
	{
		z=p+i*2;
		q=p+i;
		*z=*q;
	}
	for(i=0;i<2*n;i+=2)
	{
		z=p+i;
		q=z+1;
		k=abs(*z);
		*q=sum(k);
	}
}
int izbaci(int p[], int n)
{
	int f[1000]={0};
	int max,z=2,i,j,k,n2; /*n2 je druga velicina*/
	max=p[0];
	for(i=0;i<n;i++)
	{
		if(max<p[i])
		{
			max=p[i];
		}
	}
	f[0]=1;
	f[1]=1;
	for(i=2;i<1000;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>max) break;
		else (z++);
	}
	n2=n;
	for(i=0;i<n2;i++)
	{
		for(j=0;j<z;j++)
		{
			if(p[i]==f[j])
			{
				for(k=i;k<n2-1;k++)
				{
					p[k]=p[k+1];
				}
				n2--;
				i--;
				break;
			}
		}
	}
	return n2;
}
int main() {
	int i, niz[20]={0},n=10,izlaz;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,n);
	n=n*2; /*nova velicina niza*/
	izlaz=izbaci(niz,n);
	printf("Modificirani niz glasi: ");
	for(i=0;i<izlaz;i++)
	{
		if(i==izlaz-1)
		{
			printf("%d.",niz[i]);
		}
		else
		{
			printf("%d, ",niz[i]);	
		}
	}
	return 0;
}
