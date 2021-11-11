#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int k,i,j,m, minute, stepeni, sekunde;
	double ugao[500],a,b,c;
	printf("Unesite broj uglova: ");
	scanf("%d", &k);
	for(i=0;i<k;i++){
		scanf("%lf", &ugao[i]);}
m=k;
printf("Uglovi su: \n");
for(i=0;i<k;i++){

	    
	    b=ugao[i]*(180/PI);
	    stepeni=(int)b;
	    a= (b-stepeni)*60;
	    minute=(int)(a);
	    c=(a-minute)*60;
	    
	    if(c<0)
	    sekunde=(abs)(c-0.5);
	    else if (c>0)
	    sekunde=(int)(c+0.5);
	    else 
	    sekunde=0;
	 
	   if(sekunde==60){
	   	sekunde=0;
	   	minute=(abs)(minute);
	   	minute++;
	   if(minute==60)
	   { minute=0;
	   	if(stepeni<0)
	   		stepeni--;
	    else if(stepeni>0)
	   		stepeni++;}
	   }
	   
	    minute=(abs)(minute);
	 if(sekunde<=30 && sekunde>=-30){
	 	
	 	printf("%d stepeni %d minuta %d sekundi\n",stepeni, minute, sekunde);
	 	
	 }
	    
	    
	if(sekunde>30 || sekunde<-30){
		for(j=i;j<m-1;j++){
			ugao[j]=ugao[j+1];
		
		m--;
		j--;
	}}}
	
return 0;
}
