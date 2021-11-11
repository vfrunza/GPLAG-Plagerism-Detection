#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define MAX_EL 500


int main() {
	int n, i, j;
	double uglovir[MAX_EL], ugao, stepeni[MAX_EL], minute[MAX_EL], sekunde[MAX_EL];
	printf ("Unesite broj uglova: ");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
	    scanf("%lf", &ugao);
	    uglovir[i]=ugao;
	}
	
	for (i=0; i<n; i++)
	{   
	    uglovir[i]*=180./PI;
	    stepeni[i]=(int)uglovir[i];
	    minute[i]=(int)((fabs(uglovir[i]) - (int)(fabs(uglovir[i])))*60);
	    sekunde[i]=(int)(((((fabs(uglovir[i])-(int)(fabs(uglovir[i])))*60)-(int)((fabs(uglovir[i])-(int)(fabs(uglovir[i])))*60))*60)+0.5);
	}
	
	for(i=0; i<n; i++)
	{
	    if (sekunde[i]>=60)
	    {
	        sekunde[i]-=60;
	        minute[i]++;
	    }
	    if(minute[i]>=60)
	    {
	        minute[i]-=60;
	        if(stepeni[i]<=0)
	        stepeni[i]--;
	        else
	        stepeni[i]++;
	    }
	}

	for (i=0; i<n; i++)
	{
	    if (sekunde[i]>30)
	    {
	        for(j=i; j<n-1; j++)
	        {
	            stepeni[j]=stepeni[j+1];
	            minute[j]=minute[j+1];
	            sekunde[j]=sekunde[j+1];
	        }
	        n--;
	        i--;
	    }
	}
	
	printf("Uglovi su: \n");
	for (i=0; i<n; i++)
	{
	    printf("%g stepeni %g minuta %g sekundi\n", stepeni[i], minute[i], sekunde[i]);
	}
	return 0;
}
