#include <stdio.h>
#include <time.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_UGLOVA 500

int main() {
	
	int a, b, br;
	int sek[BROJ_UGLOVA], step[BROJ_UGLOVA], min[BROJ_UGLOVA];
	double dja[BROJ_UGLOVA]={0}, niz[BROJ_UGLOVA];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &br);
	
	
	for(a=0; a<br; a++) {
		
	scanf("%lf", &niz[a]);
	
	niz[a]=niz[a]*180/PI;
	if(niz[a]<0) {dja[a]=1; niz[a]=-niz[a];}
	step[a]=floor(niz[a]);
	min[a]=floor((niz[a]-step[a])*60);
	sek[a]=floor(((niz[a]-step[a])*60-min[a])*60+0.5);
	
	
	if(sek[a]==60) {
		min[a]++;
		sek[a]=0;
	}
	
	if(min[a]==60) {
		step[a]++;
		min[a]=0;
	}}
	
	for(a=0;a<br;a++){
		if(sek[a]>30){
			for(b=a;b<br;b++){
				step[b]=step[b+1];
				min[b]=min[b+1];
				sek[b]=sek[b+1];
			}
			a--;
			br--;
		}
	}
	
printf("Uglovi su: \n");
	for(a=0;a<br;a++){
		if(dja[a]==1) printf("-");

	printf("%d stepeni %d minuta %d sekundi\n", step[a], min[a], sek[a]);
	
	}
	return 0;
}
