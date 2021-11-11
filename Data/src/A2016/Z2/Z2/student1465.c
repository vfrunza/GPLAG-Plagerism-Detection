#include <stdio.h>
#define PI 3.1415926

int main() {
	
	int n, i, j;
	int stepeni, minute, sekunde;
	double step;
	double niz[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	scanf("%lf", &niz[i]); 
	
	printf("Uglovi su: \n");
	for(i=0; i<n; i++)
	{
		step = niz[i] * 180/PI;
		if(step<0) step=-step;
		stepeni = (int)step;
		step -= (int)step;
		step *= 60;
	
		minute = (int)step;
		step -= (int)step;
		step *= 60;
		
		sekunde = (int)(step + 0.5);
		if(sekunde >= 60) { sekunde-=60; minute++; }
		if(minute >= 60) { minute-=60; stepeni++; }
		
		if(sekunde > 30) 
		{
			for(j=i; j<n-1; j++)
			{
				niz[j] = niz[j+1];
			}
			n--;
			i--;
		}
	}
	
	for(i=0; i<n; i++)
	{
		int negativan=0;
		step = niz[i] * 180/PI;
		if(step<0)
		{
			step=-step; 
			negativan = -1;
		}
		stepeni = (int)step;
		step -= (int)step;
		step *= 60;
	
		minute = (int)step;
		step -= (int)step;
		step *= 60;
		
		sekunde = (int)(step + 0.5);
		if(sekunde >= 60) { sekunde-=60; minute++; }
		if(minute >= 60) { minute-=60; stepeni++; }
		
		if(negativan) printf("-");
		printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
	}
	return 0;
}
