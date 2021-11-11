#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n, i, stepeni, minute, ukupnosekundi, sekunde;
	float niz[500];
	do {
		 printf("Unesite broj uglova: ");
	     scanf("%d", &n);
	} while(n<1 || n>500);
	for(i=0;i<n;i++) {
		scanf("%f", &niz[i]);

	}
	printf("Uglovi su: ");
	
	


		for(i=0;i<n;i++) {
	    	ukupnosekundi=round((niz[i]*180*3600)/PI);
	  
			stepeni=ukupnosekundi/3600;
			minute=(ukupnosekundi%3600)/60;
			sekunde=(int)((ukupnosekundi%3600)%60);
			minute=fabs(minute);
			sekunde=fabs(sekunde);
			if(sekunde>=59.5) {
				minute=minute+1;
			    sekunde=0;
			}
			
			if(minute>=59.5 && stepeni>0) {
				stepeni=stepeni+1;
				minute=0;
			}
			else if(minute>=59.5 && stepeni<0) {
				stepeni=stepeni-1;
				minute=0;
			}
			if(sekunde<=30)
			printf("\n%d stepeni %d minuta %d sekundi", stepeni,minute,sekunde);
		
}
	return 0;
}
