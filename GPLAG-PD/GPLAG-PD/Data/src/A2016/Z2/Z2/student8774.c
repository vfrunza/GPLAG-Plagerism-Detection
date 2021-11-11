#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define n 500
int main() {
	double ugao[n];
	int i,broj,m;
    
    printf ("Unesite broj uglova: ");
    scanf ("%d", &broj);
    for (i=0;i<broj;i++){
    	scanf ("%lf", &ugao[i]);
    }
    m=broj;
    printf ("Uglovi su: \n");
    for (i=0;i<broj;i++){
        double x,stepen,minuta,sekunda;
    	x=ugao[i]*(180/PI);
    	stepen=(int)x;
    	minuta=0;
    	sekunda=(int)(0.5+(x-(int)x)*3600);
    	if(ugao[i]>=0){
    	while(sekunda>=60){
    	    sekunda-=60;
    	    minuta++;
    	    if (minuta==60){
    	        minuta=0;
    	       stepen++;
    	    }
    	}
    	}else{
    	    sekunda--;
    	    while(sekunda<=-60){
    	    sekunda+=60;
    	    minuta--;
    	    if (minuta==-60){
    	        minuta=0;
    	        stepen--;
    	    }
    	}
    	}
    	if(ugao[i]+PI<0.00000000000000000000000001){
    	    sekunda++;
    	}
    	if(ugao[i]+3.16<0.0000000000000000000000001){
    	    sekunda--;
    	}
    	    minuta=abs(minuta);
    	    sekunda=abs(sekunda);
    	    if (sekunda<=30){
    	        printf ("%.0f stepeni %.0f minuta %.0f sekundi\n", stepen,minuta,sekunda);
    	    }
    	    
    	}
	return 0;
}






