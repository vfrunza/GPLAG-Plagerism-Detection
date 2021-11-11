#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define max 500
int main() {
	double niz[max], stpn, min, min1, sec, sec1, secT, check;
	int i, n, stpn1, min2, sec2;
	
	/* unos broja uglova */
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
	}
	
	printf("Uglovi su: ");
	/* pretvaranje iz radijana u stepene */
	for(i=0; i<n; i++) {
		check=niz[i];
		niz[i]=fabs(niz[i]);
		stpn=niz[i]*180/PI;
		stpn1=(int)stpn;
		min=fabs(stpn-stpn1);
		min1=min*60;
		min2=(int)min1;
		sec=fabs(min1-min2);
		sec1=sec*60;
		secT=sec1+0.5;
		sec2=(int)secT;
		if(sec2>=60) { sec2=0; min2++; }
		if(min2>=60) { min2=0; stpn1++; }
	/* ispis */
		if(check>=0 && sec2<=30) printf("\n%d stepeni %d minuta %d sekundi", stpn1, min2, sec2);
		if(check<0 && sec2<=30) printf("\n-%d stepeni %d minuta %d sekundi", stpn1, min2, sec2);
	}
	return 0;
}