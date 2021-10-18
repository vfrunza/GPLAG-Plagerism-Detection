#include <stdio.h>
#include <math.h>

void ubaci(int niz[],int broj){
	int i,SumaCifara,suma=0;
	/*Posto niz koji se izbacuje mora sadrzati i cifru koja je unesena i zbir cifara koja je unesena,duzina niza je duplo veća od unesenog niza*/
	for(i=broj-1;i>0;i--)
	{
		niz[2*i]=niz[i];
	}
	for(i=0;i<2*broj-1;i+=2)
	{
		suma=0;
		SumaCifara=niz[i];
		while(SumaCifara!=0)
		{
			suma+=(SumaCifara%10);
			SumaCifara=SumaCifara/10;
		}
		if(suma<0)suma*=-1;
		niz[i+1]=suma;
	}
}
/*Trazenje fibonacijevog niza*/
int fib(int a)
{
	int sljedeci=1,prethodni=0;
	while(sljedeci<=a)
	{
		sljedeci+=prethodni;
		prethodni=sljedeci-prethodni;
		if(a==sljedeci)return 1;
	}
	return 0;
}
/*izbacivanje brojeva fibonacijevog niza iz drugog niza*/
int izbaci(int niz[],int n)
{
	int i,j,v=n;
	for(i=0;i<v-1;i++)
	{
		if(fib(niz[i])){
			for(j=i;j<v-1;j++)
			{
				niz[j]=niz[j+1];
			}
			i--;v--;
		}
	}
	if(fib(niz[i]))v--;
	return v;
}
int main(){
	int broj,niz[2000],kraj;
	printf("Unesite niz od 10 brojeva: ");
	for(broj=0;broj<10;broj++)
	{
		scanf("%d",&niz[broj]);
	}
	ubaci(niz,10);
	kraj=izbaci(niz,20);
	printf("Modificirani niz glasi:");
	for(broj=0;broj<kraj;broj++){
		if(broj==kraj-1)printf(" %d.",niz[broj]);
		else printf(" %d,",niz[broj]);
	}

	return 0;
}