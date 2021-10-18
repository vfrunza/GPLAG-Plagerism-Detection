#include <stdio.h>
#define PI 3.1415926
int main() {
	double niz[500];
	int n,i,stepen,minute,sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		niz[i]*=180./PI;
		stepen=(int)(niz[i]);
		niz[i]-=stepen;
		if (stepen<0) niz[i]*=(-1);
		niz[i]*=60;
		minute=(int)(niz[i]);
		niz[i]-=minute;
		niz[i]*=60;
		sekunde=(int)(niz[i]+0.5);
		if(stepen > 0 && sekunde>=60) {minute++; sekunde-=60;}
		if (stepen >0 && minute>=60) {stepen++; minute-=60;}
		if (stepen <0 && sekunde >=60) {minute++; sekunde-=60;}
		if(stepen <0 && minute >=60) {stepen--;minute-=60;}
				if (sekunde>30 )  continue;

				printf("%d stepeni %d minuta %d sekundi \n",stepen,minute,sekunde);
	}

	return 0;
}
