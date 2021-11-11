#include <stdio.h>
#include <stdlib.h>
#define BR_EL 500 
#define PI 3.1415926
#define fabs 0.5

int main() {
/*printf("Zadaća 2, Zadatak 2");*/
int i, br_el,j;
double niz[BR_EL];
int minute,stepen,sekunde;
printf("Unesite broj uglova: ");
scanf("%d", &br_el);
for(i=0;i<br_el;i++){
	scanf("%lf", &niz[i]);
}
printf("Uglovi su: ");
for(i=0;i<br_el;i++){
/*linija 22-28 - pretvaranje radijana u sekunde, uz detaljno zaokruzivanje */
	niz[i]*=180./PI;
    stepen = (int)(niz[i]);
    niz[i]-=stepen;
    if(niz[i]<0){ niz[i]*=-1;}
    sekunde=(int)(abs(niz[i]*3600+fabs));
    minute=sekunde/60;
    sekunde=sekunde-minute*60;
/*	printf("\n%d %d %d", minute, sekunde,stepen);*/
/* ukoliko minute prekorace svoju maksimalnu velicinu, negativni unos stepena */
    if (minute ==60){ 
	minute=0;
	if (stepen<0) stepen--; else stepen++;}
	if(sekunde <= 30)printf("\n%d stepeni %d minuta %d sekundi", stepen,minute,sekunde); 
	/* izbacivanje iz niza( uz ocuvanje redoslijeda) */
	else if(sekunde>30) {
	     for(j=0;j<br_el-1;j++) {
		 niz[j]=niz[j+1];
	}
	br_el--;
	i--;
	}
}
	return 0;
}
