#include <stdio.h>
#include <stdlib.h>
#define epsilon 0.5
#define PI 3.1415926
int main() {
	int broj_el;
	int i, j, minute, stepeni, sekunda, negativna;
	float sekunde;
	double niz[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_el);
	if(broj_el>500 || broj_el<0) return 0;
		for(i=0; i<broj_el; i++){
		scanf("%lf", &niz[i]);
	} 
	printf("Uglovi su: \n");
	
	for(i=0; i<broj_el; i++) {
		
		niz[i]=niz[i]*180/PI;
		
		stepeni=(int)niz[i];
		
		if(stepeni<0) negativna = -1;
		else negativna=1;
		
		
		sekunde=(niz[i]-stepeni)*3600*negativna + epsilon;
		
		sekunda=(int)sekunde;
		
		minute=sekunda/60;
		
		sekunda=sekunda-60*minute;
	/* if(minute>=60) { if (stepeni>0)stepeni++; else stepeni--; minute=0; }*/
	if(minute>=60) {if(stepeni>0) stepeni++; else stepeni--; minute=0; } 
	
	if(sekunda<=30) printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunda);
		else {
			for(j=i; j<broj_el-1;j++) {
				niz[j] = niz[j+1];
			}
			broj_el--;
			i--;
	

	}
	
		
			}

	return 0;
}


	/*	sekunde=(niz[i]*180/PI)*3600;
		
		sekunde=(int)(sekunde+epsilon);
		
		stepeni=sekunde/3600;

		minute=(sekunde-stepeni*3600)/60;
		
	
		sekunda=sekunde-stepeni*3600 - minute*60;
		if (sekunda<0) sekunda-=1;
		
		if(sekunda>=60) { minute++; sekunda=sekunda-60;}
		if(minute>=60) {stepeni++; minute= minute-60;}
		
		
		minute=abs(minute);
		sekunda=abs(sekunda); */
		