#include <stdio.h>
#include <stdlib.h>
#define velicina 10

void ubaci(int *array, int vel)
{
	int i=0,j,suma=0,nizic,num,kontakt=0;
	for(i=0;i<vel;i++)
	{   
/*uzimanje vrijednosti iz niza(prvobitnog)*/
		if(i==0)
			nizic=*(array+i);
		else nizic=*(array+i+kontakt);
		nizic=abs(nizic);
/**/
		if(nizic<10)
		{
			suma=nizic;
		}
		if(nizic>9)
		{
			do
			{
				num=nizic%10;
				suma=suma+num;
				nizic=nizic/10;
			}while(nizic>=1);
		}
/*pomjeranje niza za ubacivanje novog elementa(zbira cifara)*/
		for(j=vel+i;j>i+kontakt+1;j--)
		{
			*(array+j)=*(array+j-1);
		}
		if(i==0)
			*(array+i+1)=suma;
		else *(array+i+kontakt+1)=suma;
/**/
		suma=0;
		kontakt++;
	}
}

int izbaci(int *array, int vel)
{
	int fib,i,j,k,dod_1,dod_2;
	for(i=0;i<vel;i++)
	{
		fib=0;
		dod_1=*(array+i)+1;
/*if(jer nema negativnih fibbonacijevih*/
		if(dod_1<0)
			continue;
/*provjera da li je element niza iz fibbonacijevog razvoja*/
		for(j=1;j<dod_1;)
		{	
			dod_2=*(array+i);
			fib=fib+j;
/*ako jeste izbaciti iz niza*/
			if(fib==dod_2)
			{
				for(k=i;k<vel-1;k++)
				{
					*(array+k)=*(array+k+1);
				}
				i--;
				vel--;
				break;
			}
/*postavljanje prethodne vrijednosti*/
			if(fib>=3)
				j=fib-j;
		}
	}
	return vel;
}

int main() 
{
    int i,niz[20],glava_dva;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<velicina;i++)
	    scanf("%d",&niz[i]);
	ubaci(niz,velicina);
	glava_dva=izbaci(niz,velicina*2);
	printf("Modificirani niz glasi: ");
/*ide do glava_dva jer je to nova velicina niza*/
	for(i=0;i<glava_dva;i++)
	{
	    if(i==glava_dva-1)
	        printf("%d.",niz[i]);
	    else printf("%d, ",niz[i]);
	}
	return 0;
}