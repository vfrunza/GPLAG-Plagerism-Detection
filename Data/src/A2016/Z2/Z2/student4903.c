#include <stdio.h>
#define br_clanova 500
#define pi 3.1415926

int n, i, printanje=1, j, negativan=0;
double niz[br_clanova], minute, sekunde, stepeni; 

int main() {
	do{
	printf("Unesite broj uglova: ");
	scanf("%d", &n);} while(n<0 || n>500);
	 printf("Uglovi su:");
	 
	 for(i=0; i<n; i++) scanf("%lf", &niz[i]); 
	
	
	for(i=0; i<n; i++){
		
		niz[i]=niz[i]*180/pi;
		if(niz[i]<0) {niz[i]=-niz[i]; negativan=1;}
		else negativan=0;
		stepeni=(int)niz[i];
		minute=niz[i]-(int)niz[i];
		minute=minute*60;
		sekunde=minute-(int)minute;
		sekunde=sekunde*60;
		minute=(int)minute;
		sekunde=(int)(sekunde+0.5);
		if(sekunde>=59.5){sekunde=0; minute++;
		if(minute>59){minute=0; stepeni++;}}
		if(sekunde>30) {printanje=0;
			for(j=i; j<n-1; j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
		if(printanje==1) {
			if (negativan==0)printf("\n%g stepeni %g minuta %g sekundi", stepeni, minute, sekunde);
			else if(negativan==1){printf("\n-%g stepeni %g minuta %g sekundi", stepeni, minute, sekunde); 
	
	}}
		printanje=1;
		
	}
		
		

	return 0;
}
