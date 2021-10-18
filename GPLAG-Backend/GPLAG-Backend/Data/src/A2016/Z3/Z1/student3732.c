#include <stdio.h>

int daj_prost()
{
	static int prost_broj=1;
	int prost=1;
	while(1)
	{
		prost_broj++;
		if(prost_broj==2)
		{
			return prost_broj;
		}
		int i;
		for(i=2;i<prost_broj;i++)
		{
			if(prost_broj%i==0)
			{
				prost=0;
				break;
			}
		}
		if(prost==1)
		{
			return prost_broj;
		}
		else
		{
			prost=1;
		}
	}
}

int main() {
	int A,B,sum=0,pozivanje=daj_prost();
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d",&A);
		scanf("%d",&B);
		if(A<1)
		{
			printf("A nije prirodan broj.\n");
		}
		if(A>=B)
		{
			printf("A nije manje od B.\n");
		}
	}while(A<1 || A>=B);
	while(pozivanje<B)
	{
		
		if(pozivanje>A)
		sum+=pozivanje;
		pozivanje=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,sum);
	return 0;
}