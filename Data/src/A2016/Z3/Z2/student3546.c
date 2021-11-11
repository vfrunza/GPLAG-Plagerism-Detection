#include <stdio.h>

void ubaci(int *niz, int velicina)
{
	int i,j;
	for(i=0;i<velicina;i+=2)
	{
		int zbir_cifara=0;
		int pomocna=niz[i];
		if(pomocna<=0) pomocna*=-1;
		while(pomocna>0)
		{
			zbir_cifara += pomocna%10;
			pomocna/=10;
		}
		for(j=velicina;j>i;j--)
			niz[j]=niz[j-1];
		velicina++;
		niz[i+1]=zbir_cifara;
	}
}

int daLiJeFib(int broj)
{
	int tren=0;
	int p = 1;
	int pp = 1;
	if(broj==0) return 0;
	if(broj==1) return 1;
	while(tren<broj)
	{
	tren = p + pp;
	pp = p;
	p = tren;
	}
	if(tren==broj) return 1;
	return 0;
}



int izbaci(int *niz, int velicina)
{
	int i,j;
	int broj_izbacenih=0;
	for(i=0;i<velicina;i++)
	{
		if(daLiJeFib(niz[i]))
		{
			for(j=i;j<velicina-1;j++)
				niz[j]=niz[j+1];
			velicina--;
			i--;
		}
	}
	return velicina;
}

int main() {
	int niz[50];
	printf("Unesite niz od 10 brojeva: ");
	int i;
	for(i=0;i<10;i++)
		scanf("%d", &niz[i]);
	ubaci(niz,10);
	int b = izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<b;i++)
	{
		if(i!=b-1)
			printf("%d, ", niz[i]);
		else
			printf("%d.", niz[i]);
	}
	return 0;
	
}
