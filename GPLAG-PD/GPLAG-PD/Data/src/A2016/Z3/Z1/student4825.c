#include <stdio.h>

int daj_prost()
{
	int i, prost=1;
	static int x=2;
	for (i=2; i<=x-1; i++)
	{
		if (x%i==0)
			{
				prost=0;
				x++;
				break;
			}
	}
	if (prost==1) 
		return x++;
}
int main() {
	int i, A, B, suma=0;
	
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	while (A<=0)
	{
		printf("A nije prirodan broj.");
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}
	while (B<=0)
	{
		printf("B nije prirodan broj.");
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}
	while (A>=B)
	{
		printf("A nije manje od B.");
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}
	while (A<=0 && B<=0)
	{
		printf("A nije prirodan broj.");
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}
	for (i=A+1; i<B; i++)
	{
		daj_prost(i);
		if (i==daj_prost())
		suma+=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}