#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {
	int n;
	int sat[510], min[510], sek[510], i;
	double g;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	if(n>500 || n<1)return 0;

	for(i=0;i<n;i++){
		scanf("%lf", &g);
		if(g>=0){
			g=g*180/PI;
			sat[i]=g;
			g=(g-sat[i])*60;
			min[i]=g;
			g=(g-min[i])*60+ 0.5;
			sek[i]=g;
			if(sek[i]==60){
				sek[i]=0;
				min[i]++;
			}
			if(min[i]==60){
				min[i]=0;
				sat[i]++;
			}
			if(sek[i]>30){
				n--;
				i--;
			}
		} else {
			g=g*180/PI;
			sat[i]=g;
			g=(g-sat[i])*60;
			min[i]=g;
			g=(g-min[i])*60- 0.5;
			sek[i]=g;
			if(sek[i]==-60){
				sek[i]=0;
				min[i]--;
			}
			if(min[i]==-60){
				min[i]=0;
				sat[i]--;
			}
			if(sek[i]<-30){
				n--;
				i--;
			}
		}
	}
	printf("Uglovi su:");
	for(i=0;i<n;i++){
		if(sat[i]>=0)printf("\n%d stepeni %d minuta %d sekundi", sat[i], min[i], sek[i]); else {
			printf("\n%d stepeni %d minuta %d sekundi", sat[i], -min[i], -sek[i]);
		}
	}
	return 0;
}
