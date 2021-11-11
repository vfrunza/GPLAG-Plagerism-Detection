#include <stdio.h>
#define Pi 3.1415926
#include <stdlib.h>
#include <math.h>

int main() {
	int n,i,j;
	double ugao[500],min[500],sek[500];
	/*BROJ uglova tj cl niza*/ 
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	/*unos UGLOVA tj clanova ugao[i] i pretvaranje*/ 
	for (i=0;i<n;i++) {
		scanf("%lf",&ugao[i]);
		ugao[i]=ugao[i] * (180/Pi);
	/*MINUTE min[i] npr 45,27 treba mi 0,27 znaci od ukupnog oduzimam zaokruzeno
	 pomnoziti sa 60, moze biti neg ug pa apsolutnu*/
	min[i]=(fabs(ugao [i])-abs((int)ugao[i]))*60;
	/*SEKUNDE sek[i] opet oduzeti od minuta sad i pomn*/
	sek[i]=(min[i]-(int)min[i])*60;
	sek[i]=(int)(sek[i]+0.5);
	/*npr 60sek*/
	if (sek[i]>=60){
		min[i]=min[i]+1;
		sek[i]=0;}
	if (min[i]>=60){
		if (ugao[i]<0) ugao[i]=ugao[i]-1;
		else ugao[i]=ugao[i]+1;
		min[i]=0;}
		
	/*izbacivanje*/	
	if(sek[i]>30){
	 for(j=i;j<n-1;j++){
	 	ugao[j]=ugao[j+1];
	 }
	 n--; i--;
	}
	}
	
	/*ispis*/
	printf("Uglovi su: ");
	for (i=0;i<n;i++)
	 printf("\n%d stepeni %d minuta %d sekundi",(int)ugao[i],(int)min[i],(int)sek[i]);
	
	return 0;
}
