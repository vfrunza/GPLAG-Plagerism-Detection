#include <stdio.h>

int daj_prost()
{
	static int a=1;
	int i,prostJe=1;
	int sljedeciBroj;
	for(sljedeciBroj=a+1;  ;sljedeciBroj++)
	{
		for(i=2;i<=sljedeciBroj/2;i++)
		{
			if(sljedeciBroj % i == 0)
			{
				prostJe=0;
				break;
			}
			else  prostJe=1;
		}
		if(prostJe==1)
		{
			a=sljedeciBroj;
			return a;
		}
		prostJe = 1;
	}
}

int main() {
	int A,B,suma=0,noviProst;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	while(A<=0 || A>=B || B<=0)
	{
		if(A<=0)
			printf("A nije prirodan broj.\n");
		else if(A>=B)
			printf("A nije manje od B.\n");
		else if(B<=0)
			printf("B nije prirodan broj.\n");
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
	}
	do
	{
		noviProst=daj_prost();
		if(noviProst>A && noviProst<B)
			suma+=noviProst;
		else  
			continue;
	}
	while(noviProst<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}
