#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_EL 500

int main() { 
	
	int i, j, bru; 
	double niz[BROJ_EL];
	int stepeni, minute, sekunde; 
	double s,m,s1; 
	
	printf ("Unesite broj uglova: "); 
	scanf ("%d", &bru); 
	
    printf ("Uglovi su: "); 
	for (i=0; i<bru; i++) {
		scanf ("%lf", &niz[i]); 
	
	}	
	
	for (i=0; i<bru; i++) { 
     	
		s=niz[i]*180/PI;
		stepeni=(int)s; 
		
		m=(s-stepeni)*60; 
		minute=(int)m; 
		
		s1=(m-minute)*60;
		if (s>0) s1=s1+0.5;
		else s1=s1-0.5;
        sekunde=(int)s1; 
       
       if (abs(sekunde)>=59.5) {
       	sekunde=0; 
       	if (niz[i]>0) minute++; 
       	else minute--; 
       }
       if (abs(minute)>=59.5) {
       	minute=0; 
       	if (niz[i]>0) stepeni++; 
       	else stepeni--; 
       }
    	if (abs(sekunde)>30) {
		for (j=i; j<bru-1; j++) {
			niz[j]=niz[j+1];
		}
			bru--;
			i--; 
		
		}
		else printf ("\n%d stepeni %d minuta %d sekundi", stepeni, abs(minute), abs(sekunde));
}
	return 0;
}