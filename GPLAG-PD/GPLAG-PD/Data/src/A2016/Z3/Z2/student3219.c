#include <stdio.h>
#include <stdlib.h>

void ubaci(int *niz,int vel)
{
	int *kraj=niz+vel, c, suma, *pom;
	while(niz!=kraj)
	{
		c = abs(*niz);
		suma = 0;
		while(c!=0)
		{
			suma=suma+c%10;
			c=c/10;
		}
		pom = kraj;
		while (pom != niz) {
			*pom = *(pom-1);
			pom--;
		}
		niz++;
		*niz = suma;
		niz++;
		kraj++;
	}
}

int izbaci(int *niz, int vel)
{
	int p[100] = {1,1}, i, j, k;
	for(i = 2; i < 100; i++) {
		p[i] = p[i-1]+p[i-2];
	}
	for(i=0;i<vel;i++)
	{
		for(j=1;j<100;j++)
		{
			if(niz[i] == p[j])
			{
				for(k=i;k<vel-1;k++)
				{
					niz[k]=niz[k+1];
				}
				i--;
				vel--;
				break;
			}
		}
	}
	
	return vel;
}

int main() {
	int niz[20];
	int i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	int x=izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	for(i=0;i<x-1;i++)
	{
		printf("%d, ",niz[i]);
	}
	printf("%d.",niz[x-1]);
	return 0;
}
