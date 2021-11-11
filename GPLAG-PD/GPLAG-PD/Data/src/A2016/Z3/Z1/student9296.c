#include <stdio.h>

int daj_prost()
{

	static int broj=1;
	int i;
	
	broj++;
	for(i=2; i<broj; i++) {

		if(broj%i==0) {
			i=1;
			broj++;
		}
	}
	return broj;
}

int main()
{

	int A, B, suma=0, stuffing=0;

	while(1) {
		printf("Unesite brojeve A i B: ");
		scanf("%d", &A);
		scanf("%d", &B);

		if(A>=B) {
			printf("A nije manje od B.\n");
			continue;
		} else if(A<=0) {
			printf("A nije prirodan broj.\n");
			continue;
		} else if(B<=0) {
			printf("B nije prirodan broj.\n");
			continue;
		} else break;
	}

	for(;;) 
	{
		stuffing=daj_prost();

		if(stuffing>A && stuffing<B) 
		{
			suma+=stuffing;
		}
		else if(stuffing<=A) continue;
		
		else break;
	}

	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);

	return 0;
}
