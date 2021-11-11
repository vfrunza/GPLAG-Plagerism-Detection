#include <stdio.h>
#define PI 3.1415926

int main() {
	double niz[500];
	int n,i;
	int step, min, sec;
	double ukupno_sec;
	int a=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		a=0;
		if(niz[i]<0) {niz[i]*=-1; a=1;}
		ukupno_sec=niz[i]*180/PI*3600;
		step=(int)(ukupno_sec/3600);
		ukupno_sec=ukupno_sec-step*3600;
		min=(int)(ukupno_sec/60);
		ukupno_sec=ukupno_sec-min*60;
		if(ukupno_sec-(int)ukupno_sec<0.5)
			sec=(int)ukupno_sec;
		else sec=(int)ukupno_sec+1;
		if(sec==60){
			sec=0;
			min++;
			if(min==60){
				min=0;
				step++;
			}
		}
		if(sec>30) continue;
		if(a==1) printf("%d stepeni %d minuta %d sekundi\n", -step, min, sec);
		else printf("%d stepeni %d minuta %d sekundi\n", step, min, sec);
	}
	
	return 0;
}
