#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() 
{
	int n, i;
	double v[500];
	double step, min, sec;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%lf", &v[i]);
	}
	
	printf("Uglovi su: \n");
	for(i = 0; i < n; i++)
	{
		step = fabs(v[i] * 180 / PI);
		min = (step - (int)step) * 60;
		sec = (min - (int)(min)) * 60;
		
		step = (int)(step);
		min = (int)(min);
		sec = (round)(sec);
		
		if (sec >= 60) 
		{
			sec = 0;
			min++;
		}
		
		if (min >= 60)
		{
			min = 0;
			step++;
		}
		
		if(sec > 30)
		  continue;
		
		else if(v[i] < 0)
		  step *= -1;
		
		printf("%.f stepeni %.f minuta %.f sekundi\n", step, min, sec);
	}
	return 0;
}
