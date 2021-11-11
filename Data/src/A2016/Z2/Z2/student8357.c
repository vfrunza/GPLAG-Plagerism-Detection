#include <stdio.h>
#define PI 3.1415926
#include <math.h>
int main() {
	int i,x;
	int step,min,sec,usec;
    float niz[500];
	printf("Unesite broj uglova:");
	scanf("%d",&x);
	    for(i=0;i<x;i++){
	    scanf("%f",&niz[i]);
	    }   
	    for(i=0;i<x;i++){
		    float usec=(niz[i]*180/PI)*3600;
		    if(usec<0){
		    usec=(int)(usec-0.5);
		    step=(int)usec/3600;
		    min=fabs((int)(usec-step*3600)/60);
		    sec=fabs((int)usec-step*3600-min*60);
		    }
		    else{
		    usec=(int)(usec+0.5);
		    step=(int)usec/3600;
		    min=(int)(usec-step*3600)/60;
	        sec=(int)usec-step*3600-min*60;}
            if(sec>=60){
            	min++;
            	sec=(sec-60);
            }
            if(min>=60){
            	step++;
            	min=(min-60);
            }
               min=fabs(min);
               sec=fabs(sec);
		    	if(i<1) printf(" Uglovi su:");
	            if(sec<31)printf("\n%d stepeni %d minuta %d sekundi",step,min,sec);
	    }
	return 0;
}
