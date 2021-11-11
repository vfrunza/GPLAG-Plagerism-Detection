#include <stdio.h>
#include <math.h>

int daj_prost()
{
	int j;
	
	static int i = 1;
	i++;
	
	for(j = 2; j < i; j++)
	{
		if(i % j == 0)
		{
			i++;
			j = 2;
		}
	}


		return i;
	
}



int main() 
{
	int i,a,b,suma = 0;
	
	for(;;)
	{
		printf("Unesite brojeve A i B: ");
		
		scanf("%d %d", &a, &b);
		
		if(a < 1 && b < 1)
		
		printf("A nije prirodan broj.\n");
		
		else if(a < 1)
		
		printf("A nije prirodan broj.\n");
		
		
		else if(a >= b)
		
		printf("A nije manje od B.\n");
		
		else break;
	
}

	for(; ;)
	{	
		i=daj_prost();
		
		if(i > b) break;
		
		
		else if((i > a) && (i < b))
		{
			suma = suma + i;
		}
		
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}