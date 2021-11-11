#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>
int main() {
	double niz[500],u,s;
	int i,a,sec,min,step,sekunda[500],minuta[500],stepeni[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&a);
	for(i=0;i<a;i++) {
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<a;i++) {
		u=niz[i]*180/PI;
		while(u>360) {
			u=u-360;
		}
		while(u<-360) {
			u=u+360;
		}
		s=u*3600;
		s=round(s);
		sec=s;
		
		step=u;
		min=(sec-step*3600)/60;
		sec=sec%60;
		if(min==60) {
			min=0;
			step++;
		} else if (min==-60) {
			min=0;
			step--;
		}
		sekunda[i]=abs(sec);
		minuta[i]=abs(min);
		stepeni[i]=step;
	}
	int k=0;
	for(i=0;i<a;i++) {
		if(sekunda[i]<=30) {
			sekunda[k]=sekunda[i];
			minuta[k]=minuta[i];
			stepeni[k]=stepeni[i];
			k++;
		}
	}
	for(i=0;i<k;i++) {
		printf("%d stepeni %d minuta %d sekundi\n", stepeni[i],minuta[i],sekunda[i]);
	}
	return 0;
}
