#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define epsilon 0.0000000000000000000000001
int main() {
	int n=-1,i;
	double nizic[500],temp;
	double nizA[500], nizB[500]={0}, nizC[500];
	double s,m;
	printf("Unesite broj uglova: ");
	do {
		scanf("%d", &n);
	
	}while(n>500 || n<=0);
	for(i=0;i<n;i++) {
		scanf("%lf", &nizic[i]);
		
		temp = nizic[i]*180/PI;
		nizA[i] = (int) temp;
		nizC[i] = (int) (0.5+(temp - (int) temp)*3600);
		while(nizC[i]>=60) {
			nizC[i]-=60;
			nizB[i]++;
		}
		while(nizB[i]>=60) {
			nizB[i]-=60;
			nizA[i]++;
		}
		if(nizic[i]<0) {
			
				nizC[i]--;
			while(nizC[i]<=-60) {
			nizC[i]+=60;
			nizB[i]--;
		}
		while(nizB[i]<=-60) {
			nizB[i]+=60;
			nizA[i]--;
		}
			if(nizic[i]+3.1415926<epsilon){
			
			nizC[i]++;
		}
		if(nizic[i]+3.15<epsilon){
			nizC[i]--;
		}
	}

}
printf("Uglovi su: \n");
    for(i=0;i<n;i++) {
    	
    if(nizC[i]>30 || nizC[i] < -30) continue;
    s = abs(nizB[i]);
    m = abs(nizC[i]);
    	printf("%.0f stepeni %.0f minuta %.0f sekundi\n", nizA[i], s, m);
    }
	
	return 0;
}
