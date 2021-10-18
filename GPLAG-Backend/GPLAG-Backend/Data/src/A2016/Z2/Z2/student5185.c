#include <stdio.h>
#include <math.h>
#define max 500
#define PI 3.1415926


int main() {
	/*Variable declaration*/
	int i, n;
	double niz[max], a, b, stepen, minute, sekunde, stepenOstatak, minuteOstatak;
	
	/*Data input*/
	printf("Unesite broj uglova: ");
	scanf ("%i", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a);
		
		if (a < 0)
		{
			niz[i] = a;
		}
		
		if (a >= 0)
		{
		stepen = ((a * 180) / PI);
		stepenOstatak = stepen - (int) stepen;
		
		minute = stepenOstatak * 60;
		minuteOstatak = ((stepenOstatak * 60) - (int)( stepenOstatak * 60));
		
		sekunde = (int)(minuteOstatak*60 + 0.5);
		
		if (sekunde == 60)
		{
			minute += 1;
			sekunde = 0;
		}
		
		if (minute == 60)
		{
			stepen += 1;
			minute = 0;
		}
		
		if ((int)sekunde > 30)
		{
			n--;
			i--;
		}
		else
		{
			niz[i] = a;
		}
		}
	}


	
	printf("Uglovi su:");
	
	for (i = 0; i < n; i++)
	{
		if (niz[i] >= 0)
		{
			stepen = (int) ((niz[i] * 180) / PI);
			minute = (int)((((niz[i] * 180) / PI) - stepen) * 60);
			sekunde = ((((((niz[i] * 180) / PI) - (int) ((niz[i] * 180) / PI)) * 60) - minute) * 60) + 0.5;

			sekunde = (int) sekunde;
		
			if (sekunde >= 60)
			{
				minute = minute + 1;
				sekunde = 0;
			}
		
			if (minute == 60)
			{
				stepen = stepen + 1;;
				minute = 0;
			}
			
			printf("\n%g stepeni %g minuta %g sekundi", stepen, minute, sekunde);
		}
		
		else if (niz[i]<0)
		{
			stepen = (int) ((niz[i] * 180) / PI);
			minute = (int)((((niz[i] * 180) / PI) - stepen) * 60);
			sekunde = ((((((niz[i] * 180) / PI) - (int) ((niz[i] * 180) / PI)) * 60) - minute) * 60) - 0.5;

			sekunde = (int) sekunde;
			
			if (sekunde == -60)
			{
				minute = minute - 1;
				sekunde = 0;
			}
		
			if (minute == -60)
			{
				stepen = stepen - 1;
				minute = 0;
			}
			
			if (sekunde < -30)
			{
				continue;
			}
			else{
			if (sekunde < 0)
				sekunde = sekunde * -1;
			if (minute < 0)
				minute = minute * -1;
			printf("\n%g stepeni %g minuta %g sekundi", stepen, minute, sekunde);
			}
		}
		
	}

	
	return 0;
}
