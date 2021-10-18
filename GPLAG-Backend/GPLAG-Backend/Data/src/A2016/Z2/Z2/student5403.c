#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	
	
	int i,broj,x[500],y[500],z[500],j;
	double sekunde [500],minute[500],stepeni[500],ugao[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &broj);
	for(i=0;i<broj;i++){
		scanf("%lf",&ugao[i]);
		
	}
	printf("Uglovi su: \n");
	
	/*Pretvaranje uglova u stepene,minute i sekunde*/
	
	for(i=0;i<broj;i++){
	stepeni[i]=(180/PI)*ugao[i];
	minute[i]=((fabs(stepeni[i])-(int)(fabs(stepeni[i])))*60.0);
	sekunde[i]=((minute[i]-(int)(minute[i]))*60.0);
 
   x[i]=(int)(stepeni[i]);
   y[i]=(int)(minute[i]);
   z[i]=(int)(sekunde[i]+0.5);
   
    if(x[i]==-0)
     x[i]=-x[i];
    
    
    if(z[i]==60){
    	
    	z[i]=0;
    	if(x[i]<0){
    	y[i]++;
    	if(y[i]==60){
    	  y[i]=0;
    	  x[i]=abs(x[i])+1;
    	  x[i]=-x[i];
    	}}

      else{
       y[i]++;
       if(y[i]==60){
        y[i]=0;
        x[i]++;
    }}}
    
  
   /*Izbacivane ugla cije su sekunde vece od 30*/
   	 if(z[i]>30){
   	 for(j=i;j<broj-1;j++){
   	   ugao[j]=ugao[j+1];
   	 }
   	 i--;
   	 broj--;
     } 
     }	 
     
   /*Ispis uglova*/
   for(i=0;i<broj;i++)
    printf("%d stepeni %d minuta %d sekundi\n", x[i], y[i], z[i]);

	
	return 0;
}
