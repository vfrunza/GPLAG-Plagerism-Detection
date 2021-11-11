#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	
	double pocetni[500], step[500], min[500], sek[500];
	int n, i, stepeni[500], minute[500], sekunde[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%lf", &pocetni[i]);
		
		step[i] = pocetni[i] * (180/PI);
		stepeni[i] = (int)step[i];
	
		min[i] = (step[i] - stepeni[i])*60; 
		minute[i] = (int)min[i];
	
		sek[i] = (min[i] - minute[i])*60; 
		
		
		sekunde[i] = round(sek[i]);
		
		if(sekunde[i] == 60)
		{ sekunde[i]=0;
		minute[i]++;}
		
		else if(sekunde[i] == -60) 
		{minute[i]--;
		sekunde[i]=0;}
	
		if(minute[i] == 60)
		{stepeni[i]++;
		minute[i]=0;}
		
		else if(minute[i] == -60)
		{stepeni[i]--;
		minute[i]=0;}
	
		
		if(sekunde[i]>30 || sekunde[i]<-30)
		{
			i--; 
			n--;
			continue;
		}
		
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++)
	{
		printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], abs(minute[i]), abs(sekunde[i]));
	}
	return 0;
}
