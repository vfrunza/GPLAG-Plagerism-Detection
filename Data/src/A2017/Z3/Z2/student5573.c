#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[],int velicina)
{
	int broj,provjera,i;
	float decimala;
	for(i=0;i<velicina;i++)
	{
		broj=fabs((niz[i]-(int)niz[i])*100);
		provjera=broj%10;
		if(provjera>=5)
		{
			decimala=(broj/10 +1)/10.;
			if(niz[i]>0)	niz[i]=(int)niz[i]+decimala;
			else	niz[i]=(int)niz[i]-decimala;
		}
		else
		{
			decimala=(broj/10)/10.;
			if(niz[i]>0)	niz[i]=(int)niz[i]+decimala;
			else	niz[i]=(int)niz[i]-decimala;
		}
	}
}
void preslozi(float niz[],int vel,int k)
{
	int i,j,broj,suma_cifara=0,brojac=0;
	float temp;
	zaokruzi1(niz,vel);
	for(i=0;i<vel;i++)
	{
		broj=fabs(niz[i]*10);
		while(broj!=0)
		{
			suma_cifara+=broj%10;
			broj/=10;
		}
		if(suma_cifara>=k)
		{
			for(j=i;j>brojac;j--)
			{
				temp=niz[j-1];
				niz[j-1]=niz[j];
				niz[j]=temp;
			}
			brojac++;
		}
		suma_cifara=0;
	}
}
int main() {
	printf("Zadaća 3, Zadatak 2");
	return 0;
}
