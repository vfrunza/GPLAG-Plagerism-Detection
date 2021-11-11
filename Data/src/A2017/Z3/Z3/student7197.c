#include <stdio.h>
int brojCifara(int n)
{
	int i=0;
	do{
		i++;
		n/=10;
	}while(n);
	return i;
}
int izbaci_cifre(int *niz1, int velicina1, int *niz2, int velicina2)
{
	int i,j,k,l;
	int cifre[10],duzina,negativan=0;
	//provjera da li se cifre ponavljaju i da li us izvan opsega
	for(i=0;i<velicina2;i++)
	{
		if(niz2[i]<0 || niz2[i]>9)return 0;
		for(j=i;j<velicina2;j++)
		if(niz2[i]==niz2[j] && i!=j)return 0;
	}
	//sada cemo cjepkat broj i trpat ga u niz
	//iz tog niza izbacujemo cifre koje se nalaze u niz2
	//i onda ofrmiramo novi broj u kojem smo izbacili te cifre iz niz2
	for(i=0;i<velicina1;i++)
	{
		//moramo poaziti i na negativne
		int n=niz1[i];
		if(n<0)
		{
			n=-n;
			negativan=1;//da znamo za kasnije kad budemo formirali novi broj
		}
		duzina = brojCifara(niz1[i]);
		for(j=0;j<duzina;j++)
		{
			cifre[j]=n%10;//cifre su poredane neopako
			n/=10;
		}
		//izbacivanje cifara
		for(j=0;j<duzina;j++)
		{
			for(k=0;k<velicina2;k++)
			{
				if(cifre[j]==niz2[k])
				{
					for(l=j;l<duzina-1;l++)
						cifre[l]=cifre[l+1];
					j--;
					duzina--;
				}
			}
		}
		niz1[i]=0;
		if(duzina>0)
		for(j=duzina-1;j>=0;j--)
			niz1[i]=niz1[i]*10+cifre[j];
		if(negativan)niz1[i]=-niz1[i];	
	}
	return 1;
}

int main() {
	
	return 0;
}
