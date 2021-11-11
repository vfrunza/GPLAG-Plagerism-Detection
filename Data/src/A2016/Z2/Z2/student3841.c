#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() 
{
	/*printf("Zadaća 2, Zadatak 2");*/
	
	double niz[500], a = 0, b = 0, c = 0;
	int s = 0, i = 0, j = 0, step = 0, min = 0, sec = 0;
	
	
	do
	{
		printf("Unesite broj uglova: ");
		scanf("%d", &s);
	}
	
	while(s < 0 || s > 500);
	
	for(i = 0; i < s; i++)
	{
		scanf("%lf", &niz[i]);
		
	}
	
	printf("Uglovi su:\n");
	
	for(i = 0; i < s; i++)
	{
		a = niz[i] * 180 / PI; /*pretvaranje radijana u stepene*/
		step = (int) a; /*stepen postaje cjelobrojan da se odredi ostatak tj minute*/
		b = a - step; /*određivanje minuta*/
		b *= 60;
		min = abs((int) b); /*minute postaju cjelobrojne da se odrede sekunde */
		c = fabs(b) - min; /*određivanje sekundi*/
		c *= 60;
		sec = abs(round(c));
		
			
		if(sec == 60)
		{
			min++;
			sec = 0;
		}
		
		if(min == 60)
		{
			if(step < 0)
				step--;
				
			else
				step++;
				
			min = 0;
				
		}
	//	printf ("F - A %f\n", fabs (b) - min);
	//	printf(">>>> %d stepeni %d minuta %d sekundi\n", step, min, sec);
			
		if(sec > 30)
		{
			for(j = i; j < (s - 1); j++)
				niz[j] = niz[j+1];
				
			s--;
			i--;
			
		}
	}
	
	for(i = 0; i < s; i++)
	{
		a = niz[i] * 180 / PI; /*pretvaranje radijana u stepene*/
		step = (int) a; /*stepen postaje cjelobrojan da se odredi ostatak tj minute*/
		b = a - step; /*određivanje minuta*/
		b *= 60;
		min = fabs((int) b); /*minute postaju cjelobrojne da se odrede sekunde */
		c = fabs(b) - min; /*određivanje sekundi*/
		c *= 60;
		sec = fabs(round (c));
		
		
		if(sec == 60)
		{
			min++;
			sec = 0;
		}
		
		if(min == 60)
		{
			if(step < 0)
				step--;
				
			else
				step++;
				
			min = 0;
		}
		
		
		printf("%d stepeni %d minuta %d sekundi\n", step, min, sec);
	}
	return 0;
}
