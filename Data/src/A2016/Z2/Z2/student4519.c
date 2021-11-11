#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int n,i;
	/* int brojac=0; */
	float uglovi[500];
	int pozitivan;
	float step, min, sek;
	int Cstep, Cmin, Csek;

	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	   scanf("%f", &uglovi[i]);
	
	printf("Uglovi su:");
	for(i=0; i<n; i++){
	    pozitivan=1;
	    if(uglovi[i]<0) {
	                   pozitivan=0;
	    }
	    uglovi[i]=fabs(uglovi[i]);
	    
	    step=(uglovi[i]* (180/PI));
	    
	    min=(step - (int)(step))*60;

	    sek=(min - (int)(min))*60;
	    sek=(int)(sek + 0.5);
	   
		Cstep=(int)(step);
		Cmin=(int)(min);
		Csek=(int)(sek);
		
		if(Csek==60){ 
			Csek=0;
		    ++Cmin;
	    } 
	    if(Cmin==60){
	    	Cmin=0;
			++Cstep;
	    } 
		if(pozitivan==0) Cstep=(-1)*Cstep;
	
		if(Csek<=30) printf("\n%d stepeni %d minuta %d sekundi",Cstep, Cmin, Csek);  
	    else continue;
		
	}
	   
	return 0;
}



