#include <stdio.h>
#include<math.h>
#define PI 3.1415926
#define BROJ 500

int main() {
	int i,brugl=0,dgr=0,min=0,sec=0;
	double niz[BROJ],usec=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &brugl);
	printf("Uglovi su: ");
	for(i=0;i<brugl;i++){
		scanf("%lf", &niz[i]);
		usec=(niz[i]*180./PI)*3600.;
		if(usec>=0){usec+=0.5;} else usec-=0.5;
		dgr=usec/3600;
		min=(usec-dgr*3600)/60;
		sec=usec-dgr*3600-min*60;
		dgr=(int)dgr;
		min=(int)min;
		sec=(int)sec;
		min=fabs((int)min);
		sec=fabs((int)sec);
		if(sec>=60){ min++;	sec=sec-60;}
		if(min>=60){ dgr++;	min=min-60;	}
			
			
		if(sec>30)continue;	
		if(sec<-30)continue;
		printf("\n%d stepeni %d minuta %d sekundi", dgr,min,sec);
		
	}
	
	return 0;
}
