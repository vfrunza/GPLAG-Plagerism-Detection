#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define b 505
#define e 0.0083


int main() {
	double niz[b]; 
	int i, n;
	int stepeni[b], minuta[b], sekundi[b];
    double x, y;
	
	printf("Unesite broj uglova: ");

	
	do {
		scanf("%d", &n);
	}while(n<1 || n>500);
	
	
    printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		
		scanf("%lf", &niz[i]);
		x = niz[i]*(180/PI) - (int)(niz[i]*(180/PI));
	   	y = (x*60-(int)(x*60));
	   	y = fabs(y)+e;
	     
		sekundi[i]=abs(y*60)+0.5;
	
		minuta[i]=abs(x*60);
        if (sekundi[i]==60){minuta[i]++; sekundi[i]=0;} 	
		
		stepeni[i]=niz[i]*(180/PI);
	    if (minuta[i]==60){if(niz[i]>0) stepeni[i]++; else stepeni[i]--; minuta[i]=0;}
	    
	    if(sekundi[i]>30) {n--;i--;}
		
	}
	
	for(i=0; i<n; i++)
    printf("%d stepeni %d minuta %d sekundi\n", stepeni[i],minuta[i],sekundi[i]);
	
	return 0;} 
	