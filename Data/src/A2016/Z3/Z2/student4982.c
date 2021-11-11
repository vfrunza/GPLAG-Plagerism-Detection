#include <stdio.h>
#include <stdlib.h>
void ubaci(int *p, int velicina)
{
	int i;
	for(i=2*velicina-2;i>0;i-=2)
	{
		p[i]=p[i/2];
	}
	
	for(i=0;i<2*velicina;i+=2)
	{
		int suma=0;
		int x=abs(p[i]);
		while(x!=0)
		{
			suma+=x%10;
			x=x/10;
		}
		p[i+1]=suma;
	}
}

int Fibonaccijev(int n)
	{  if(n<=0) return 0;
		int x=1,y=1,z;
		while(1)
		{
			z=x+y;
			if(z==n || n==1) return 1;
			if(z>n) return 0;
			x=y; y=z;
		}
	}
	
	int izbaci (int *x, int velicina)
	{
		int i,j;
		for(i=0;i<velicina;i++)
		{
			if(Fibonaccijev(x[i]))
			{
				for(j=i;j<velicina-1;j++)
				{
					x[j]=x[j+1];
				}
				velicina--; i--;
			}
		}
		return velicina;
	}

int main() {
	int niz[500],i,velicina=10,velicina2;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<velicina;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,velicina);
	velicina2=izbaci(niz,2*velicina);
	printf("Modificirani niz glasi: ");
	for(i=0;i<velicina2-1;i++)
	{
		printf("%d, ",niz[i]);
	}
	printf("%d.",niz[velicina2-1]);
	return 0;
}
	
	



