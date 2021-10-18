#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define broj 500

int main() {
	int   i, n, stp, mn, sc, j;
	double niz[broj], D;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%lf", &niz[i]); }
		printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		D= (niz[i]/PI)*180; 
		stp=(int)D;
		
		D=fabs(D) - abs(stp);
		D= D*60;
		mn=(int)D;
		mn=abs(mn);
		
		if (mn) D=D-mn;
		D=D*60;
		sc=(int)(D+0.5);
		sc=abs(sc);
		
		if(stp>0 &&(mn==59 && sc>=59.5)){
			stp=stp+1; 
			mn=0;
			sc=0;
		}
		else if (stp<0 &&(mn==59 && sc>=59.5)) {
			stp= stp-1;
			mn=0;
			sc=0;
		}
		else if(sc==60 && mn<59) {mn=mn+1; sc=0;}
		if (sc>30) {
				for(j=i; j<n-1; j++) {
					niz[j]=niz[j+1]; }
				n--;
				i--; }
				
		if(sc<=30) { printf("%d stepeni %d minuta %d sekundi\n", stp, mn, sc); }
		}
	return 0;
}
