#include <stdio.h>
#define PI 3.1415926

int main() {
	double niz[500];
	int n, i, j;
	double a, b, c, d;
	int stepeni, minute, sekunde;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	
	for(i=0; i<n; i++) {
		
		scanf("%lf", &niz[i]);
		
	}
	
	for(i=0; i<n; i++) {
		
		a=niz[i];
		
		a=a*180/PI;
		
		stepeni=(int)a;
		
		
		b=(a-(int)a)*60.00;
		
		minute=(int)b;
		
		c=(b-(int)b)*60.00;
		
		d=c-(int)c;
		
		sekunde=(int)c;
		
		if(d>=0.50) sekunde++;
		
		if(d<=-0.5) sekunde--;
		
		if(sekunde==60) {
			
			sekunde=0;
			minute++;
		}
		
		if(sekunde==-60) {
			sekunde=0;
			minute--;
		}
		
		
		if(minute==60) {
			minute=0;
			stepeni++;
		}
		
		if(minute==-60) {
			minute=0;
			stepeni--;
		}
		
		if(sekunde>30 || sekunde<-30) {
			for (j=i; j<n-1; j++) {
				niz[j] = niz[j+1];
				
		}
		n--;
		i--;
			
		}
		
		
		
	}
	
	printf("Uglovi su: \n");
	
	for(i=0; i<n; i++) {
		
		a=niz[i];
		
		a=a*180/PI;
		
		stepeni=(int)a;
		
		b=(a-(int)a)*60;
		
		minute=(int)b;
		
		c=(b-(int)b)*60;
		
		d=c-(int)c;
		
		sekunde=(int)c;
		
		if(d>=0.5) sekunde++;
		
		if(d<=-0.5) sekunde--;
		
		if(sekunde==60) {
			
			sekunde=0;
			minute++;
		}
		
		if(sekunde==-60) {
			sekunde=0;
			minute--;
		}
		
		if(minute==-60) {
			minute=0;
			stepeni--;
		}
		
		if(minute==60) {
			minute=0;
			stepeni++;
		}
		
		printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
		
	}
	
	return 0;
}
