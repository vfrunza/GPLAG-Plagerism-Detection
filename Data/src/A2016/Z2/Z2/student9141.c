#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
    int broj_uglova, i, j;
    double uglovi[500];
    double stepeni, minuta, sekundi, tempsec;
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_uglova);
	for(i=0; i<broj_uglova; i++){
	    scanf("%lf", &uglovi[i]);
	}
	for(i=0; i<broj_uglova; i++){
	    stepeni=(uglovi[i]*180)/PI;
	    minuta=(stepeni-(int)stepeni)*60;
	    sekundi=(minuta-(int)minuta)*60;
	    if(sekundi-(int)sekundi>=0.5)
	        sekundi=sekundi+0.5;
	    if(sekundi-(int)sekundi<=-0.5)
	        sekundi=sekundi-0.5;
	    if((int)sekundi==60){
	        minuta=minuta+1;
	        sekundi=0;
	    }
	    if((int)minuta==60){
	        stepeni=stepeni+1;
	        minuta=0;
	    }
	    if((int)sekundi<=-60){
	        minuta=minuta-1;
	        sekundi=0;
	    }
	    if((int)minuta<=-60){
	        stepeni=stepeni-1;
	        minuta=0;
	    }
	    if(abs(sekundi)>=31){
	        for(j=i; j<broj_uglova-1; j++)
	        uglovi[j]=uglovi[j+1];
	        broj_uglova--;
	        i--;
	    }
	}
	printf("Uglovi su:\n");
	for(i=0; i<broj_uglova; i++){
	    stepeni=(uglovi[i]*180)/PI;
	    minuta=(stepeni-(int)stepeni)*60;
	    sekundi=(minuta-(int)minuta)*60;
	    tempsec=sekundi*10;
	    tempsec=(int)tempsec;
	    sekundi=tempsec/10;
	    if(sekundi-(int)sekundi>=0.5)
	        sekundi=sekundi+0.5;
	    if(sekundi-(int)sekundi<=-0.5)
	        sekundi=sekundi-0.5;
	    if((int)sekundi==60){
	        minuta=minuta+1;
	        sekundi=0;
	    }
	    if((int)minuta==60){
	        stepeni=stepeni+1;
	        minuta=0;
	    }
	    if((int)sekundi==-60){
	        minuta=minuta-1;
	        sekundi=0;
	    }
	    if((int)minuta==-60){
	        stepeni=stepeni-1;
	        minuta=0;
	    }
	    printf("%d stepeni %d minuta %d sekundi\n", (int)stepeni, (int)(abs(minuta)), (int)(abs(sekundi)));
	}
	    
	    
	return 0;
}
