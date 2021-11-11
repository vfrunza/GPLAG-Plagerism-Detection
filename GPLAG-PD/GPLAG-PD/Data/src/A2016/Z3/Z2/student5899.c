#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define VEL 10
#define velicina 20
void ubaci(int *niz, int vel)
{
	int i,broj,broj1,nbroj=0,j;
	for(j=vel-1;j>=0;j--)
	{
		niz[2*j]=niz[j];
	}
		for(i=0; i<2*vel; i+=2)
		{
			broj=abs(niz[i]);
			if(broj<10)
			{
				nbroj=broj;
			}
			else
			{
				do
				{
					broj1=broj%10;
					nbroj=nbroj+broj1;
					broj=broj/10;
				}
				while(broj!=0);
			}
			niz[i+1]=nbroj;
			nbroj=0;
		}
}
	
	
int izbaci(int *niz, int vel)
{
	int i,j,a=1,b=1,c,s;
	for(i=0;i<vel;i++)
	{
		a=1;
		b=1;
		for(j=1;j<10000;j++)
		{
			if(j==1)
			{
				c=1;
			}
			else
			{
				c=a+b;
				a=b;
				b=c;
			}
			if(niz[i]==c)
			{
				for(s=i; s<vel-1; s++)
				{
					niz[s]=niz[s+1];
					
				}
			vel--;
			i--;
			break;
		}
	}
}
return vel;
}
int main()
{
	int niz[2*VEL],s,i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<VEL;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,VEL);
	s=izbaci(niz,velicina);
	printf("Modificirani niz glasi: ");
	for(i=0;i<s;i++)
	{
		if(i==s-1)
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
	
