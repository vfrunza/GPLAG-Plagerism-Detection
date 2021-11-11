#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define BREL 500
#define EPS 0.0001


int main() {
 	int n, i, j, stepeni=0, minute=0, sekunde=0, ukupno_sekundi=0;
 	double uglovi[BREL];
 	
 	printf("Unesite broj uglova: ");
 	scanf("%d", &n);
 	
 	for(i=0; i<n; i++) {
 		scanf("%lf", &uglovi[i]);
 	}
 	
 	
 	printf("Uglovi su:\n");
 	for(i=0; i<n; i++) {
 	    if(uglovi[i]<0){
 	        ukupno_sekundi=(uglovi[i]*(180./PI)*3600) - 0.5;
 	    }
 	    else {
 	        ukupno_sekundi=(uglovi[i]*(180./PI)*3600) + 0.5;
 	    }
 		    stepeni=ukupno_sekundi/3600;
 		    minute=fabs((ukupno_sekundi-stepeni*3600)/60);
 		    sekunde=fabs(ukupno_sekundi-stepeni*3600-minute*60);
 		
 		if(sekunde>30) {
 		    for(j=i; j<n-1; j++) {
 		        uglovi[j]=uglovi[j+1];
 		    }
 		    n--;
 		    i--;
 		}
 		else{
 		    if(sekunde>=60) {
 		        minute++;
 		        sekunde-=60;
 		    }
 		    if(minute>=60) {
 		        stepeni++;
 		        minute-=60;
 		    }
 		    printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
 	    }
 	}
 	
 	
 	return 0;
 }