#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	
	int i,br,stepen1,minuta1;
	float niz[500],stepen,minuta,sekunda;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&br);
	
	for(i=0;i<br;i++) scanf("%f",&niz[i]);
	
	printf("Uglovi su: \n");
	
	
	for(i=0;i<br;i++) {
		
		stepen=(niz[i]*180)/PI;
	
	
		 if(stepen-(int)stepen>0.9998 && stepen-(int)stepen<1) {
			stepen++;
			stepen1=(int)stepen;
			minuta1=0; sekunda=0; 
			printf("%d stepeni %d minuta %.f sekundi\n",stepen1,minuta1,sekunda); }
			else if(stepen-(int)stepen<-0.9998 && stepen-(int)stepen>-1) {
				stepen--;
				stepen1=(int)stepen;
				minuta1=0; sekunda=0;
					printf("%d stepeni %d minuta %.f sekundi\n",stepen1,minuta1,sekunda); } 
		else { 	 
	
		stepen1=(int)stepen;
	
		
		minuta=stepen-stepen1;
		minuta*=60;
		minuta1=(int)minuta;
		minuta1=abs(minuta);
	    minuta=fabs(minuta);
	   
	    
	    sekunda=minuta-minuta1;
	    sekunda*=60;
	    
	    if(sekunda<=0) sekunda*=-1;
	    if(sekunda-(int)sekunda>=0.5) sekunda++;
	    sekunda=(int)sekunda;
	    
	    if(sekunda<=30) printf("%d stepeni %d minuta %.f sekundi\n",stepen1,minuta1,sekunda); 
	} }
		
	


	return 0;
}
