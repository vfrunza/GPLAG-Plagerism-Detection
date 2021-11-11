#include <stdio.h>
#define PI 3.1415926

int main() {
	int n=0,i,j;
	double niz[500];
	int sek=0, min=0, step=0;
	double ukupno=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	}
	for(i=0;i<n;i++){
			ukupno=(niz[i]*180/PI)*3600;
			if (niz[i]<0)
				ukupno=(int)(ukupno-0.5);
			else
				ukupno=(int)(ukupno+0.5);
			step=ukupno/3600;
			min=(ukupno-step*3600)/60;
			sek=ukupno-step*3600-min*60;
			if(sek>30 || sek<-30) {
				for(j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		ukupno=(niz[i]*180/PI)*3600;
			if (niz[i]<0)
				ukupno=(int)(ukupno-0.5);
			else
				ukupno=(int)(ukupno+0.5);
			step=ukupno/3600;
			min=((ukupno-step*3600)/60);
			sek=(ukupno-step*3600-min*60);
			if (min<0) min*=-1;
			if (sek<0) sek*=-1;
		printf("%d stepeni %d minuta %d sekundi\n", step, min, sek);
	}
	
	
	
	
	
	
	
	
	
	return 0;
}
