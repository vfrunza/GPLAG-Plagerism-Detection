#include <stdio.h>
#define PI 3.1415926
#define max 500
int main() {
	int i, j, br_el=0, step=0, min=0, sek=0, uk_sek=0;
	double niz [max];
	printf ("Unesite broj uglova: ");
	scanf ("%d", &br_el);
	if (br_el>max)
	{
		printf ("Pogresan unos!");
	}
	printf ("Uglovi su: \n");
	for (i=0; i<br_el; i++)
	{
		scanf ("%lf", &niz[i]);
		uk_sek= (((niz[i]*180)/PI)*3600)+0.5;
		step=(int) (uk_sek/3600);
		min=(int) ((uk_sek%3600)/60);
		if (min>=60)
		{
			if (step>=0)
			{
				step++;
			}
			else
			step--;
			min=min-60;
		}
		sek=(int) ((uk_sek%3600)%60);
		if (sek>=60)
		{
			min++;
			sek=sek-60;
		}
		if (sek>30)
		{
			for (j=i; j<br_el; j++)
			{
				niz[j]=niz[j+1];
			}
			br_el--;
			i--;
		}
		else
		{
			printf ("%d stepeni %d minuta %d sekundi\n", step, min, sek);
		}
	  	
	}
	return 0;
}
