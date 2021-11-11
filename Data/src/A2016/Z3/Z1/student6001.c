#include <stdio.h>
#include <math.h>

int daj_prost();

int main() {
	long int broj, a, b, suma=0;
 while(42)
	{
	printf("Unesite brojeve A i B: ");
	scanf("%ld %ld", &a, &b);
	if(b<=a)
		printf("A nije manje od B.\n");
	else if(b<=0)
		printf("A nije prirodan broj.\n");
	else if(a<=0)
		printf("A nije prirodan broj.\n");
	else
		break;
	}
 while((broj = daj_prost()) < b)
 		if(broj>a)
 			suma += broj;
 		printf("Suma prostih brojeva izmedju %ld i %ld je %ld.", a,b,suma);
 		return 0;
 	}

int daj_prost()
{
	static int broj=2;
	int i, prost;
	while(42)
	{
		prost=1;
		for(i=2; i<= sqrt(broj); i++)
			if(broj % i==0)
			{
				prost=0;
				break;
			}
		if(prost==1)
			return broj++;
		else
			broj++;
	}
}