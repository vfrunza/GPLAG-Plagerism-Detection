#include <stdio.h>
#define PI 3.1415926
#include <math.h>

int main() {
	int i , j;
	double niz[500];
	int n, step, min, sekundi;
	double sek;
	
	
		printf("Unesite broj uglova: ");
        scanf("%d",&n);

	
	for ( i = 0 ; i < n ; i++)
	{
		scanf("%lf",&niz[i]);
	}
	
	printf ("Uglovi su: \n");
	for ( i = 0 ; i < n ; i++)
	{
		step = niz[i]*(180/PI);
		min = fabs(niz[i]*(180/PI)*60) - fabs(step*60);
		sek = fabs(niz[i]*(180/PI)*3600) - fabs(step*3600) - fabs(min*60);
		sekundi = (int)(sek + 0.5);
		
		if (sekundi > 59) {
			min += 1;
			sekundi = 0;
		}
		if (min > 59) {
			if (step>0) {
			step += 1;
			}
			else {
			step -= 1;
			}
			min = 0;
		}
		
		if (sekundi>30)
		{
			for ( j=i ; j < n-1 ; j++)
			{
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			continue;
		}
		printf ("%d stepeni %d minuta %d sekundi\n", step, min, sekundi);
	}
	return 0;
}
