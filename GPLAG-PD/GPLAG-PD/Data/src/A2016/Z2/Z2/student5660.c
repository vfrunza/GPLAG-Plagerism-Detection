#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define eps 0.0000000000000000000000000000000000000000000001

int main()
{
	int i, j, brUglova, sekF, ste, min;
	double niz[500] = {0}, sek;

	printf ("Unesite broj uglova: ");
	scanf ("%d", &brUglova);

	for (i = 0; i < brUglova; i++)
	{
		scanf ("%lf", &niz[i]);
		niz[i]*=180./PI;
	}
	
	for (i = 0; i < brUglova; i++)
	{
		
		sek = fabs(60 * ((60*(niz[i] - (int)(niz[i]))) - (int)(60*(niz[i] - (int)(niz[i])))));
		
		sek += 0.5;
		
		sekF = sek;
		if (sekF == 60) sekF = 0;
		if (sekF > 30)
			{
				for(j = i; j < brUglova; j++)
					niz[j] = niz[j+1];
				brUglova--;
				i--;
			}
	}
	
	
	printf ("Uglovi su: \n");
	
	for (i = 0; i < brUglova; i++)
	{
		ste = niz[i];
		min = abs((60*(niz[i]-(int)niz[i])));
		if (niz[i] >= 0)
		sek = fabs((int)((60 * ((60*(niz[i] - (int)(niz[i]))) - (int)(60*(niz[i] - (int)(niz[i])))))+0.5));
		else 
		sek = fabs((int)((60 * ((60*(niz[i] - (int)(niz[i]))) - (int)(60*(niz[i] - (int)(niz[i])))))-0.5));
		
		if (fabs(sek - 60) < eps) { min++; sek = 0;}
		if (niz[i] >= 0)
		{
			if (min >= 60) { ste++; min = 0;}
		}
		else 
			if (min >= 60) { ste--; min = 0;}
		sekF = sek;
		printf ("%d stepeni %d minuta %d sekundi\n", ste, min, sekF);
	}
	
	return 0;
}
