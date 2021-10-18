#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
float stepenio,minuteo,sekundeo;
double niz[499]={0};
int i=0,n,stepeni,minute,sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++) { scanf("%lf",&niz[i]); }; 
	printf("Uglovi su: ");
	for(i=0;i<n;i++) {
	stepenio=niz[i]*180/PI;
	stepeni=(int)stepenio;
	minuteo=stepenio-stepeni;
	minuteo=minuteo*60;
	minute=(int)minuteo;
	sekundeo=minuteo-minute;
	sekundeo=sekundeo*60;
	sekunde=round(sekundeo);
	if(sekunde==-60) {sekunde=0; minute=minute-1; }
	if(minute==-60) {minute=0; stepeni=stepeni-1; }
	if(sekunde==60) {sekunde=0; minute=minute+1; }
	if(minute==60) {minute=0; stepeni=stepeni+1; }
	minute=fabs(minute);
	sekunde=fabs(sekunde);
	if(fabs(sekunde)<31) 
	printf("\n%d stepeni %d minuta %d sekundi",stepeni,minute,sekunde);
	}
return 0;
}
