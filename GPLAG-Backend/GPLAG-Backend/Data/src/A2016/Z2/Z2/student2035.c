#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	double ugao[500], stepeni[500]={0}, minute[500]={0}, sekundepomocne[500]={0}, sekunde[500]={0};
	int n, i, j;
	printf("Unesite broj uglova: ");
	do 
	scanf("%d", &n);
	while (n>=500 && n<0);
	
	for(i=0; i<n; i++) {
		scanf("%lf", &ugao[i]); 
		
		ugao[i]=ugao[i]*(180/PI);
        stepeni[i]=(int)ugao[i];
        minute[i]=((int)((ugao[i]-stepeni[i])*60));
        sekundepomocne[i]=(((ugao[i]-stepeni[i])*60-minute[i])*60);
       
        if(sekundepomocne[i]>=0)
        sekunde[i]=((int)((sekundepomocne[i])+0.5)); 
        else sekunde[i]=((int)((sekundepomocne[i]-0.5)));
        
        if (sekunde[i]>59) {minute[i]=minute[i]+1; 
        sekunde[i]=sekunde[i]-60;}
        
        if(sekunde[i]<-59) { minute[i]=minute[i]-1;
        sekunde[i]=sekunde[i]+60; }
       
    
        if (minute[i]>59) {stepeni[i]=stepeni[i]+1;
       
       	minute[i]=minute[i]-60;
       }
        if (minute[i]<-59) {
            stepeni[i]=stepeni[i]-1;
            minute[i]=minute[i]+60;
        }       
    	if(sekunde[i]>30 || sekunde[i]<-30) {
    	    for(j=i; j<n-1; j++) {
    	        stepeni[j]=stepeni[j+1];
    	        minute[j]=minute[j+1];
    	        sekunde[j]=sekunde[j+1];}
    	        n--;
    	        i--;
    	    }
    	}
    

    printf("Uglovi su: ");
      for(i=0; i<n; i++) {
          minute[i]=abs(minute[i]);
          sekunde[i]=abs(sekunde[i]);
          printf("\n%g stepeni %g minuta %g sekundi", stepeni[i], minute[i], sekunde[i]);
      }
	
	
	
	
	
	return 0;
}
