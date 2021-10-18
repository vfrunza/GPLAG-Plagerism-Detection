#include <stdio.h>

int daj_prost()
{
	static int x=1;
	int i,prost=0;
	x++;
	//Provjerava da li je broj prost, ako nije prelazi na sljedeci
	for(;prost!=1;x++)
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
	}
	x--;
	return x;
}
int main()
{
	int A,B,mprost,suma=0;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A<1)
		{
			printf("A nije prirodan broj.\n");
		}
		else if(B<=A)
		{
			printf("A nije manje od B.\n");
		}
	}while(A<1||B<=A);
	//Ispisuje proste brojeve između A i B
	for(;;)
	{
		mprost=daj_prost();
		if(mprost>=B)
		{
			break;
		}
		if(mprost>A)
		{
			suma+=mprost;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}