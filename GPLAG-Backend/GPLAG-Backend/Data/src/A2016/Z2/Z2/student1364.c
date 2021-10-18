#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int n, i, j, stepeni [500], znak[500]={1}; 
	double ugao_radijani[500], ugao_stepeni[500], minute[500], sekunde[500], sekunde_zaokruzeno[500], e=0.0000000000001;

	do
	{
		printf("Unesite broj uglova: ");
	    scanf ("%d", &n);
	}
	while (n<0 || n>500);
	
	for (i=0; i<n; i++)
	{
		scanf ("%lf", &ugao_radijani [i]);
		if (ugao_radijani[i]<0)
		{
			ugao_radijani[i]=-1*ugao_radijani[i];
			znak[i]=-1;
		}
		
		ugao_stepeni [i] = ugao_radijani [i]*180/PI;  
		stepeni [i] = (int) ugao_stepeni [i];
		minute [i] = fabs ((int)((ugao_stepeni [i] - stepeni [i]) * 60));
		
		sekunde [i]= (((ugao_stepeni [i] - stepeni [i]) * 60 - minute [i]) * 60);
		
		sekunde_zaokruzeno[i]= fabs ((int)(sekunde[i]+0.5));
		
		if (fabs(sekunde_zaokruzeno[i]- 60)<e)
		{
			sekunde_zaokruzeno[i]=0;
			minute[i]++;
			if (fabs (minute[i]-60)<e)
			{
				minute[i]=0;
				stepeni[i]++;
			}
		}
		
			if (sekunde_zaokruzeno [i]>30)
		{
			for (j=i; j<n-1; j++)
			{
				sekunde_zaokruzeno [j] = sekunde_zaokruzeno [j+i];
				znak[j]=znak[j+i];
			}
			n--;
			i--;
		}
	}
	
	printf ("Uglovi su: \n");
	
    for (i=0; i<n; i++)
    {
    	if (znak[i]==-1)
    	printf ("-%d stepeni %g minuta %g sekundi\n", stepeni [i], minute [i], sekunde_zaokruzeno [i]);
    	else 
    	printf ("%d stepeni %g minuta %g sekundi\n", stepeni [i], minute [i], sekunde_zaokruzeno [i]);
    }
	
	return 0;
}
