 #include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define vel 500
int main() {
	int n, a, b;
	float niz[vel], stepen, minuta, sekunda, ostatak, ostatak1;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(a = 0; a < n; a++){
		scanf("%f", &niz[a]);
	}
	printf("Uglovi su: \n");
	for (a = 0; a < n; a++){
		 stepen = niz[a] * (180 / PI);
		 ostatak = stepen - (int)stepen;
		 stepen = (int)stepen;
		 minuta = ostatak * 60;
		 ostatak1 = minuta - (int)minuta;
		 minuta = (int)minuta;
		 sekunda = ostatak1 * 60; 
		 
		 if ( sekunda >= 59.5) { 
		 	minuta++; 
		 	sekunda = 0;}
		 if ( sekunda <= -59.5) {
		 	minuta--;
		 	sekunda = 0;}
		 if ( minuta >= 59.5) {
		 	stepen++;
		 	minuta = 0;}
		 if( minuta <= -59.5) {
		 	stepen--; 
		 	minuta = 0;}
		 	
		 if ( sekunda > 30 || sekunda < -30){
		        for ( b = a; b < n; b++){
		        	niz[b] = niz[b+1];
		        }	
		        a--;
		        n--;
		        continue;}
		  if ( minuta < 0) { minuta = -minuta; }
		  if ( sekunda < 0) { sekunda = -sekunda; }
		 
		 printf ("%.f stepeni %.f minuta %.f sekundi\n", stepen, minuta, sekunda);
	}
	return 0;
	}