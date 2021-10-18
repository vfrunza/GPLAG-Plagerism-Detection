#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define Br 500

int main() {
	double niz[Br]={0};
	int n, i, step, min, sec;
	double x, y, z;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	printf("Uglovi su: ");
	
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]); 
	x=180/PI*fabs(niz[i]);
	step=x;
	z=(x-step)*60;
	min=z;
	y=(z-min)*60;
	sec=(int)(y+0.5);
	if(niz[i]<0) 
		step=0-step;
	if(sec>=60) {
		min++;
		sec-=60;
	}
	if(min>=60) {
		if(niz[i]<0) step--;
		else step++;
		min-=60;
	}
	if(sec<=30) 
	printf("\n%d stepeni %d minuta %d sekundi", step, min, sec);
	else {
		i--;
		n--;
	}
	}
	return 0;
}