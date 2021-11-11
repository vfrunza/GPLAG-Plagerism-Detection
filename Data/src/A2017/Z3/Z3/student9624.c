#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz[],int vel1,int cifre[],int vel2)
{
	int i,j,broj,cifra,k=0,istina=0,provjera;
	for(i=0;i<vel2;i++)
	{
		if(cifre[i]<0 || cifre[i]>9)	return 0;
		for(j=i+1;j<vel2;j++)
		{
			if(cifre[i]==cifre[j])
			{
				return 0;
			}
		}
	}
	for(i=0;i<vel1;i++)
	{
		broj=niz[i];
		niz[i]=0;
		while(broj!=0)
		{
			cifra=broj%10;
			broj=broj/10;
			provjera=cifra;
			if(cifra<0)	provjera*=-1;
			for(j=0;j<vel2;j++)
			{
				if(provjera==cifre[j])
				{
					istina=1;
				}
			}
			if(istina==0)
			{
				niz[i]=niz[i]+cifra*pow(10,k);
				k++;
			}
			istina=0;
		}
		k=0;
	}
	return 1;
}
int main() {
	int brojevi[] = {123, 456},rez;
int cifre1[] = {1, 2, 3, 1};
rez = izbaci_cifre(brojevi, 2, cifre1, 4);
printf("%d\n", rez);
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
