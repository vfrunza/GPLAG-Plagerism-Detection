#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>
int main() {
	int n,i,ST,MIN,SEK,j;
	double N[500],UK;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {scanf("%lf", &N[i]); }
			printf("Uglovi su: \n");
	for(i=0; i<n; i++) { UK=(N[i]/PI)*180;
	ST=(int)UK;
	UK=fabs(UK)-abs(ST);
	UK=UK*60;
	MIN=(int)UK;
	MIN=abs(MIN);
	if (MIN)
	UK=UK-MIN;
	UK=UK*60;
	SEK=(int)(UK+0.5);
	SEK=abs(SEK);
	if (ST>0 && (MIN == 59 && SEK >=59.5)) {ST=ST+1; MIN =0; SEK=0;}
	else if (ST<0 && (MIN == 59 && SEK >=59.5)) {ST=ST-1; MIN=0; SEK=0;}
	else if (SEK==60 && MIN<59) {MIN=MIN+1; SEK=0;}
	if (SEK>30) {
	for (j=i; j<n-1; j++) {
			N[j]=N[j+1]; }
			n--;
			i--;
		}
		if (SEK<=30)
		printf("%d stepeni %d minuta %d sekundi\n", ST, MIN, SEK);
		else continue;
	}
	return 0;
}
