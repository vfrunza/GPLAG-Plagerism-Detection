#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int n,i,j;
	double niz[500];
	int stepeni[500];
	int minute[500];
	int sekunde[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%lf", &niz[i]);
	}
	for(i=0;i<n;i++)
	{
		niz[i]=niz[i]*180/PI;
		stepeni[i]=niz[i];
		niz[i]=fabs((niz[i]-stepeni[i])*60);
		minute[i]=niz[i];
		niz[i]=fabs((niz[i]-minute[i])*60)+0.5;
		sekunde[i]=niz[i];
        
	    if(sekunde[i]==60) {
	    	sekunde[i]=0;
	    	minute[i]++;
	}
	    if(minute[i]==60) {
	    	minute[i]=0;
	    	if(stepeni[i]<0)
	    	{
	    		stepeni[i]--;
	    	}
	    	else {
	    		stepeni[i]++;
	    	}
	    }
}
	    
	    
	
	for(i=0;i<n;i++)
	{
		if(sekunde[i]>30)
		{
			for(j=i;j<n-1;j++)
			{
				niz[j]=niz[j+1];
				stepeni[j]=stepeni[j+1];
				minute[j]=minute[j+1];
				sekunde[j]=sekunde[j+1];
			}
			n--;
			i--;
			
		}
	}
	printf("Uglovi su:");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d stepeni %d minuta %d sekundi\n", stepeni[i],minute[i],sekunde[i]);
	}
	return 0;
}
