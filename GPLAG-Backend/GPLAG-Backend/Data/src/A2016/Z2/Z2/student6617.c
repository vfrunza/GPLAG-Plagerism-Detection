#include <stdio.h>
#include <math.h>
#define BROJ_EL 500
#define PI 3.1415926
int main() {
	int t,n;
	double niz_stepeni[BROJ_EL],niz_minute[BROJ_EL],niz_sekunde[BROJ_EL],x[BROJ_EL];
	do{
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	}while(n>500 || n<0);
	
	for(t=0; t<n; t++)
	{
		printf("",t+1);
		scanf("%lf",&niz_stepeni[t]);
	}
	for(t=0;t<n ;t++) 
	{
	        niz_stepeni[t]=niz_stepeni[t]*(180/PI);
	        if(niz_stepeni[t]>360)
	        {
	            niz_stepeni[t]=(niz_stepeni[t]-((int)(niz_stepeni[t]/360)*360));
	        }
	        niz_minute[t]=(niz_stepeni[t]*60)-(int)niz_stepeni[t]*60;
	        niz_sekunde[t]=(niz_minute[t]*60-(int)niz_minute[t]*60);
	        niz_sekunde[t]=(floor(niz_sekunde[t]+0.5));
	        
	        if((niz_sekunde[t]>30 && niz_sekunde[t]<=59.49) || ( niz_sekunde[t]<-30 && niz_sekunde[t]>=-59.49)       )
	        {
	            x[t]=0;
	        }
	        else
	        {
	            x[t]=1;
	        }
	        if(niz_sekunde[t]>59.5)
	        {
	            niz_minute[t]=niz_minute[t]+1;
	            niz_sekunde[t]=0;
	        }
	        else if(niz_sekunde[t]<-59.5)
	        {
	            niz_minute[t]=niz_minute[t]-1;
	            niz_sekunde[t]=0;
	        }
	        if(niz_minute[t]>59.5)
	        {
	            niz_stepeni[t]=niz_stepeni[t]+1;
	            niz_minute[t]=0;
	        }
	        else if(niz_minute[t]<-59.5)
	        {
	            niz_stepeni[t]=niz_stepeni[t]-1;
	            niz_minute[t]=0;
	        }
	}
	printf("Uglovi su:\n");
	for(t=0;t<n ;t++) 
	{
	    if(x[t]==1)
	{    
	niz_minute[t]=fabs(niz_minute[t]);
	niz_sekunde[t]=fabs(niz_sekunde[t]);
	printf("%d stepeni ",(int)niz_stepeni[t]);
	printf("%d minuta ",(int)niz_minute[t]);
	printf("%d sekundi",(int)niz_sekunde[t]);
	printf("\n");
	}
	}
	return 0;
}