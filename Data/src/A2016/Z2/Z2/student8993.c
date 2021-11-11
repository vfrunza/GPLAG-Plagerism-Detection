#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
int br_uglova=0,i=0,j=0,stepeni[500],minute[500],sekunde[500];
double x=0;
printf("Unesite broj uglova: ");
scanf("%d",&br_uglova);
if(br_uglova<0 || br_uglova>500) return 0;
for(i=0;i<br_uglova;i++) {
	int a=0;
	scanf("%lf",&x);
	x*=180/PI;
	if(x<0) {a=1; x*=-1; }
	stepeni[i]=(int)x;
	x=x-(int)x;
	minute[i]=(int)(x*60);
	x*=60;
	x=x-(int)x;
	sekunde[i]=(int)round(x*60);
	if(sekunde[i]==60) {
		minute[i]++;
		sekunde[i]=0;
	}
	if(minute[i]==60) {
		stepeni[i]++;
		minute[i]=0;
	}
	if(a==1) stepeni[i]*=-1;
}
for( i=0;i<br_uglova;i++) 
if(sekunde[i]>30) {
	for(j=i;j<br_uglova-1;j++) {
		stepeni[j]=stepeni[j+1];
		minute[j]=minute[j+1];
		sekunde[j]=sekunde[j+1];
	}
	br_uglova--;
	i--;
}
printf("Uglovi su: ");
for(i=0; i<br_uglova; i++) 
printf("\n%d stepeni %d minuta %d sekundi",stepeni[i],minute[i],sekunde[i]);
return 0; }