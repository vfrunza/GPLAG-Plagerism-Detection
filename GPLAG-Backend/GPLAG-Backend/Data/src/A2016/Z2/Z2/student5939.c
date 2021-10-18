#include <stdio.h>
#define PI 3.1415926
#include <math.h>
#include <stdlib.h>
int main() {
	
	int i=0,n=-1,stepeni=0,minute=0,sekunde=0;
	double radijani=0,sekundeo=0,niz[500]={0};
	
while (n<0 || n>=500) {
	
	printf ("Unesite broj uglova: ");
	scanf ("%d", &n);
}
	
for (i=0; i<n; i++) {
	
	scanf ("%lf", &radijani);
 	niz[i]=radijani;
}


printf ("Uglovi su: \n");

for (i=0; i<n; i++) {
	


	

	sekundeo=(niz[i]*180/PI)*3600;
	if (sekunde<0) {
	sekundeo=(int) sekundeo - 0.5;
	} else sekundeo=(int) (sekundeo + 0.5);

	stepeni=sekundeo/3600;
	minute=(sekundeo-stepeni*3600)/60;
	sekunde=sekundeo-(stepeni*3600)-(minute*60);
	sekunde=abs(sekunde);
	minute=abs(minute);
	
		if (sekunde==60) {
		
		sekunde=sekunde-60;
		minute++;

	}
	
		if (minute==60) {
		
		minute=minute-60;
		stepeni++;
		
	}
	
	

	
	if (sekunde<=30) {
		
		printf ("%d stepeni %d minuta %d sekundi\n",(int)stepeni,(int)minute,(int)sekunde);
	}

	
}
 return 0;
 
}
	
	
	
	
	
	
	

