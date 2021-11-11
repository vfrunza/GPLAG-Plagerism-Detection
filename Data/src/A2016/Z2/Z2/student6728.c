#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	
	double nizA[500],minute1,sekunde1;
	
	int n,i,stepeni,minute,sekunde,j,k;
	
	printf("Unesite broj uglova: ");
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%lf", &nizA[i]);
	}
	
	printf("Uglovi su:");
	
	for(i = 0; i < n; i++)
	{
		nizA[i] = (nizA[i]*180) / PI;
		
		stepeni = (nizA[i]);
		
		minute1 = (nizA[i] - stepeni) * 60;
		
		minute = minute1;

		sekunde1 = (minute1 - minute)* 60;
		
		if(sekunde1 < 0)
		{
			sekunde = (int)(sekunde1 - 0.5);
		}
		else sekunde = (int)(sekunde1 + 0.5);
		
			if(stepeni >= 0)
			{
			 	if(sekunde > 59)
			 	{
			 		minute++;
			 		sekunde = 0;
			 	}
			 
			 if(minute > 59)
			 	{
			 		minute = 0;
			 		stepeni++;
			 	}
			}
			
			if(stepeni < 0)
			{
				if(fabs(sekunde) > 59)
				{
					minute--;
					sekunde = 0;
				}
				if(fabs(minute) > 59)
				{
					stepeni--;
					minute = 0;
				}
			}
			if(fabs(sekunde) > 30)
		{
			for(j = i ;j < n-1; j++)
			{
				nizA[j] = nizA[j+1];
			}
			n--;
			i--;
		}

	}
	k = n;
	for(i = 0 ; i < k; i++)
	{
		stepeni = (nizA[i]);
		
		minute1 = (nizA[i] - stepeni) * 60;
		
		minute = minute1;

		sekunde1 = (minute1 - minute)* 60;
		
		if(sekunde1 < 0)
		{
			sekunde = (int)(sekunde1 - 0.5);
		}
		else sekunde = (int)(sekunde1 + 0.5);
		
			if(stepeni >= 0)
			{
			 	if(sekunde > 59)
			 	{
			 		minute++;
			 		sekunde = 0;
			 	}
			 
			 if(minute > 59)
			 	{
			 		minute = 0;
			 		stepeni++;
			 	}
			}
			
			if(stepeni < 0)
			{
				if(fabs(sekunde) > 59)
				{
					minute--;
					sekunde = 0;
				}
				if(fabs(minute) > 59)
				{
					stepeni--;
					minute = 0;
				}
			}
			
			minute = fabs(minute);
			sekunde = fabs(sekunde);
				
			 printf("\n%d stepeni %d minuta %d sekundi", stepeni, minute, sekunde);
	}
	return 0;
}