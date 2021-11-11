#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define velniz1 10
#define velniz2 20

void ubaci(int *niz,int vel1)
{
	int i,suma=0,zadcifra,broj;
	for(i=vel1-1;i>=0;i--)
	*(niz+2*i)=*(niz+i);
	for(i=0;i<vel1*2;i++)
	{
		if (i%2==1)
		{
			broj=*(niz+i-1);
			while(broj!=0)
			{
			zadcifra=broj%10;
			suma=suma+zadcifra;
			broj=broj/10;
			}
		suma=abs(suma);	
		*(niz+i)=suma;
		suma=0;
		}
	}
}

int izbaci(int *niz,int vel2)
{
	int i,j,k,prvi,drugi,temp;
	for(i=0;i<vel2;i++)
	{
		prvi=0;
		drugi=1;
		for(j=0;j<1000;j++)
		{
			temp=prvi+drugi;
			prvi=drugi;
			drugi=temp;
			if( *(niz+i)==temp)
			{
				for(k=i;k<vel2-1;k++)
				{
					*(niz+k)=*(niz+k+1);
				}
			vel2--;
			i--;
			break;
			}
		}
	}
    return vel2;	
}

int main() {
	int niz[20],i,brclanova;
	printf("\nUnesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	scanf("%d",&niz[i]);
	ubaci(niz,velniz1);
	brclanova=izbaci(niz,velniz2);
	printf("Modificirani niz glasi: ");
	for(i=0;i<brclanova;i++)
	{
		if(i<(brclanova-1)) printf("%d, ",niz[i]);
		else printf("%d. ",niz[i]);
	}
	return 0;
}
