#include <stdio.h>
#include <math.h>
#define BROJ_EL 500
#define PI 3.1415926
int main() {
	int i,n;
	
	double niz_stepeni[BROJ_EL],niz_minute[BROJ_EL],niz_sekunde[BROJ_EL],x[BROJ_EL];
	
	do{
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	}while(n>500 || n<0);
	
	
	for(i=0; i<n; i++)
	{
		printf("",i+1);
		scanf("%lf",&niz_stepeni[i]);
	}
	for(i=0;i<n ;i++) 
	{
	        niz_stepeni[i]=niz_stepeni[i]*(180/PI);
	        if(niz_stepeni[i]>360)
	        {
	            niz_stepeni[i]=(niz_stepeni[i]-((int)(niz_stepeni[i]/360)*360));
	        }
	        niz_minute[i]=(niz_stepeni[i]*60)-(int)niz_stepeni[i]*60;
	        niz_sekunde[i]=(niz_minute[i]*60-(int)niz_minute[i]*60);
	        niz_sekunde[i]=(floor(niz_sekunde[i]+0.5));
	        
	        if((niz_sekunde[i]>30 && niz_sekunde[i]<=59.49) || ( niz_sekunde[i]<-30 && niz_sekunde[i]>=-59.49)       )
	        {
	            x[i]=0;
	        }
	        else
	        {
	            x[i]=1;
	        }
	        if(niz_sekunde[i]>59.5)
	        {
	            niz_minute[i]=niz_minute[i]+1;
	            niz_sekunde[i]=0;
	        }
	        else if(niz_sekunde[i]<-59.5)
	        {
	            niz_minute[i]=niz_minute[i]-1;
	            niz_sekunde[i]=0;
	        }
	        if(niz_minute[i]>59.5)
	        {
	            niz_stepeni[i]=niz_stepeni[i]+1;
	            niz_minute[i]=0;
	        }
	        else if(niz_minute[i]<-59.5)
	        {
	            niz_stepeni[i]=niz_stepeni[i]-1;
	            niz_minute[i]=0;
	        }
	}
	printf("Uglovi su:\n");
	for(i=0;i<n ;i++) 
	{
	    if(x[i]==1)
	{    
	niz_minute[i]=fabs(niz_minute[i]);
	niz_sekunde[i]=fabs(niz_sekunde[i]);
	printf("%d stepeni ",(int)niz_stepeni[i]);
	printf("%d minuta ",(int)niz_minute[i]);
	printf("%d sekundi",(int)niz_sekunde[i]);
	printf("\n");
	}
	else
	;
	}
	return 0;
}
