#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#define maks 500

int main()
{
	int stepeni, minute, sekunde, i, duzina2=0, duzina;
	double n;
	int niz1[maks], niz2[maks], niz3[maks];
	printf("Unesite broj uglova: ");
	scanf("%d", &duzina);
	for(i=0;i<duzina;i++)
	{
		scanf("%lf", &n);
		n = n*180/PI;
		stepeni = n;
		minute = (n-stepeni)*60;
		if(stepeni >= 0)
			sekunde = 3600*(n-stepeni)-minute*60+0.5;
		else
			sekunde = 3600*(n-stepeni)-minute*60-0.5;
		if(sekunde == 60)
		{
			minute++;
			sekunde = 0;
		}
		if(minute == 60)
		{
			stepeni++;
			minute = 0;
		}
		if(sekunde == -60)
		{
			minute--;
			sekunde = 0;
		}
		if(minute == -60)
		{
			stepeni--;
			minute = 0;
		}
		if(sekunde<=30 && sekunde >= -30)
		{
			niz1[duzina2]=stepeni;
			niz2[duzina2]=minute;
			niz3[duzina2]=sekunde;
			duzina2++;
		}
		
	}
	printf("Uglovi su:\n");
	for(i=0;i<duzina2;i++)
	{
		printf("%d stepeni %d minuta %d sekundi\n", niz1[i], (abs(niz2[i])), (abs(niz3[i])));
	}
	
	return 0;
	
}


