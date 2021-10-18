#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int sumacifara (int x)
{
	int suma=0;
	do
	{
		x=abs(x);
		suma+=x%10;
		x=x/10;
	}
	while(x!=0);
	return suma;
}
void ubaci (int niz[], int VEL)
{
	int i,j;
	for(i=0;i<VEL;i++)
	{
		for(j=VEL+i;j>2*i+1;j--)
		{
			niz[j]=niz[j-1];
		}
		niz[j]=sumacifara(niz[j-1]);
	}
}
int fibonaci (int x)
{
	if(x==1 || x==2)
	{
		return 1;
	}
	else
	{
		return fibonaci(x-1) + fibonaci(x-2);
	}
}
int izbaci (int niz[], int VEL)
{
	int i;
	for(i=0;i<VEL;i++)
	{ 
		int j=0;
		int br=0;
		do
		{
			j++;
			if(niz[i]==fibonaci(j))
			br++;
		}
		while(fibonaci(j)<niz[i]);
		if(br)
		{
			for(j=i;j<(VEL-1);j++)
			niz[j]=niz[j+1];
			VEL--;
			i--;
		}
	}
	return VEL;
}
int main() 
{
	int i,VEL;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	scanf("%d",&niz[i]);
	ubaci(niz,10);
	VEL= izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<VEL-1;i++)
	printf("%d, ",niz[i]);
	if(VEL>0)
	printf("%d.",niz[i]);
	return 0;
}
