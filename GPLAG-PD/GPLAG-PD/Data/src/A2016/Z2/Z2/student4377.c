#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define E 0.000001

int main() 
{
	double niz[500] = {0};
	double stepeni[500] = {0};
	double minute[500] = {0};
	double sekunde[500] = {0};
	int br=0,i,j,x;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &br);
	
	for(i=0; i< br; i++)
	{
		scanf("%lf", &niz[i]);
		
		stepeni[i] = niz[i]*180/PI;
		minute[i]= 60*(stepeni[i]-(int)stepeni[i]);
		sekunde[i]= 60*(minute[i]-(int)minute[i]);
		
		stepeni[i] = (int)stepeni[i];
		minute[i]= abs(minute[i]);
		sekunde[i]= abs(round(sekunde[i]));
		
		if(sekunde[i] >= 60)
		{
			minute[i]++;
			sekunde[i]=0;
		}
		if(minute[i] >= 60)
		{
		
			if(stepeni[i] > 0) stepeni[i]++;
			else stepeni[i]--;
			minute[i]=0;
			
		}
		if(sekunde[i] > 30)
		{
			for(j=i; j<br; j++)
			{
				niz[j] = niz[j+1];
				stepeni[j] = stepeni[j+1];
				minute[j] = minute[j+1];
				sekunde[j] = sekunde[j+1];
			}
			i--;
			br--;
		
			
		}
		
	}
	
	printf("Uglovi su: ");
	for(x = 0; x<br; x++)
	{
		if(fabs(stepeni[x]-0) < E && niz[x] < 0)
		{
			minute[x]*=-1;
		
		}
		
		printf("\n%.0f stepeni %.0f minuta %.0f sekundi", stepeni[x], minute[x], sekunde[x]);
	}
	
	
	return 0;
}
