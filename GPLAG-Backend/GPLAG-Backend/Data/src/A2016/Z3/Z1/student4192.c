#include <stdio.h>

int daj_prost ()
{
	static int x=2;
	int i,prost=0;
	while(prost!=1)
	{
		prost=1;
		for(i=2;i<x;i++)
		{
			if(x%i==0)
			{
				prost=0;
				break;
			}
		}
		if(prost==0) x++;
	}
	return x++;
	
}
int main() {
	int a,b,suma=0,broj;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0) printf("A nije prirodan broj.\n");
		if(a>=b) printf("A nije manje od B.\n");
	}
	while(a<=0 || b<=0 ||a>=b);
	broj=daj_prost();
	while(broj<=b)
	{
		if(broj>a&&broj<b) suma+=broj;
		broj=daj_prost();
	}
		

	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
