#include <stdio.h>

int daj_prost()
{
	static int broj=1;
	int i;
	broj++;
	for(i=2; i<broj; i++)
	{
		if(broj%i==0)
		{
			broj++;
			i=2;
		}
	} 
		return broj;
}

int main() 
{
	int a, b, i, suma=0, prost, j;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
	if(a>=b)
	{
		printf("A nije manje od B.\n");
	}
	
	else if((a<=0 && b<=0) || (a<=0))
	{
		printf("A nije prirodan broj.\n");
	}
	
	else break;
	}
	while (1);
	
	for(i=a+1; i<b; i++)
	{
		prost=daj_prost();
			for(j=0; j<1; j++)
			{
				if(prost<=a)
				{
					prost=daj_prost();
					j--;
				}
				else
				break;
			}
			if(prost>=b)
			break;
		suma+=prost;
	}

	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	return 0;
}
