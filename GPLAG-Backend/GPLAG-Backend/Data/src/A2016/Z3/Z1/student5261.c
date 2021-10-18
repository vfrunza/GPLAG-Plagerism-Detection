#include <stdio.h>

int daj_prost()
{
	static int prostbroj = 1;
	int i, kontrolna = 1;
	while(1)
	{
		kontrolna = 1;
		prostbroj++;
		for(i=2; i<prostbroj; i++)
		{
			if(prostbroj%i == 0)
			{
				kontrolna = 0;
				break;
			}
		}
		if(kontrolna == 0)
			continue;
			return prostbroj;
	}
}

int main()
{
	int A, B, suma = 0, prostibroj = 0;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<=0)
		{
			printf("A nije prirodan broj.\n");
			A--;
			B--;
		}
		else if(A==B || A>B)
		{
			printf("A nije manje od B.\n");
			A--;
			B--;
		}
	}
	while(A>B || A<=0 || A==B);
	
	while(1)
	{
		prostibroj = daj_prost();
		if(prostibroj <= A)
		{
			continue;
		}
		else if(prostibroj >= B)
		{
			break;
		}
		suma = suma + prostibroj;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
	
}


