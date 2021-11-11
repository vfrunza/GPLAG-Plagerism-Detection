#include <stdio.h>
#include <math.h>

int daj_prost()
{
	static int i=2;
	int j;

	for(j=2;j<i;j++)
	{
		if(i%j==0)
		{
			i++;
			j=2;
		}
	}
	return i++;
}

int main() {
	
	int A, B, i, prost, suma;
	
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		
		if(A<=0) printf("A nije prirodan broj.\n");
		else if(A>=B) printf("A nije manje od B.\n");
	}while(A<=0 || B<=0 || A>=B);
	
	suma=0;
	for(i=0; i<B; i++)
	{
		prost=daj_prost();
		if(prost>=(A+1) && prost<B) suma=suma+prost;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A, B, suma );
	return 0;
}
