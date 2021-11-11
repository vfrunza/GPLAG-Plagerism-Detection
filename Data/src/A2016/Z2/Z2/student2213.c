#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int BR_EL,i,stepen=0,minuta=0,sekunda;
double ukbrsec,niz[500],sekundatemp;
	int ispravnost_unosa=0;
	while(ispravnost_unosa==0){
printf("Unesite broj uglova: ");
		scanf("%d",&BR_EL);
	
	
if (BR_EL<501&&BR_EL>0) {
	 ispravnost_unosa++;
	}}

	for(i=0;i<BR_EL;i++){
		scanf("%lf",&niz[i]);
	}
		printf("Uglovi su: ");
		for(i=0;i<BR_EL;i++){
			 ukbrsec=(niz[i]*(180/PI))*3600;
			
    stepen=ukbrsec/3600;
	minuta=(ukbrsec-stepen*3600)/60;
	sekundatemp=((ukbrsec-stepen*3600)-minuta*60);

		sekunda=round(sekundatemp);
		minuta=abs(minuta);
		sekunda=abs(sekunda);
	
	 if (sekunda>=60) {minuta++; sekunda-=60;}
	 	if(stepen<0){
     if (minuta>=60) {stepen--; minuta-=60;} }
     	if(stepen>0){
     	if (minuta>=60) {stepen++; minuta-=60;} }
	if(sekunda<31)

	printf("\n%d stepeni %d minuta %d sekundi",stepen,minuta,sekunda);
	}


	
	
	return 0;
}
