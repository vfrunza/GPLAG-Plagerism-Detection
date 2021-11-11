#include <stdio.h>


int daj_prost()
{
	static int broj = 1;
	int i,prost;
	broj++;
	prost=1;
	for(i=2; i<broj; i++)
	{
		if(broj%i==0) prost=0;
	}
	if(prost==0) daj_prost();
	return broj;
}




int main() 
{
	int a,b,i,suma=0;	
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a>=b)
		{
			printf("A nije manje od B.\n");
		}
		else if(a<=0)
		{
			printf("A nije prirodan broj.\n");
		}
		else if(b<=0)
		{
			printf("B nije prirodan broj.\n");
		}
	} while(a>=b || a<=0 || b<=0);
	i=1;
	while(i<b)
	{
		i=daj_prost();
		if(i>a && i<b)
		suma += i;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
