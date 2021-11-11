#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double niz[500],stepeni,minute,sekunde;
	int br_uglova,i,j,cijeli_stepeni,cijele_minute,cijele_sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d",&br_uglova);
	for(i=0;i<br_uglova;i++) {
		scanf("%lf",&niz[i]);
	}
	for(i=0;i<br_uglova;i++) {
		stepeni=fabs(niz[i]*180/PI);
		cijeli_stepeni=(int)stepeni;
		minute=(stepeni-cijeli_stepeni)*60;
		cijele_minute=(int)minute;
		sekunde=(minute-cijele_minute)*60;
		cijele_sekunde=(int)(sekunde+0.5);
		if(cijele_sekunde==60) {
			cijele_minute+=1;
			cijele_sekunde=0;
			if(cijele_minute==60) {
				cijeli_stepeni+=1;
				cijele_minute=0;
			}
		}
		if(cijele_sekunde>30) {
			for(j=i;j<br_uglova-1;j++) {
				niz[j]=niz[j+1];
			}
			br_uglova--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<br_uglova;i++) {
		stepeni=fabs(niz[i]*180/PI);
		cijeli_stepeni=(int)stepeni;
		minute=(stepeni-cijeli_stepeni)*60;
		cijele_minute=(int)minute;
		sekunde=(minute-cijele_minute)*60;
		cijele_sekunde=(int)(sekunde+0.5);
		if(cijele_sekunde==60) {
			cijele_minute+=1;
			cijele_sekunde=0;
			if(cijele_minute==60) {
				cijeli_stepeni+=1;
				cijele_minute=0;
			}
		}
		if(niz[i]<0)
			printf("-%d stepeni %d minuta %d sekundi\n",cijeli_stepeni,cijele_minute,cijele_sekunde);
		else
			printf("%d stepeni %d minuta %d sekundi\n",cijeli_stepeni,cijele_minute,cijele_sekunde);
	}
	return 0;
}
