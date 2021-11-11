#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int brojUglova,i;
	double stepeni,minute,sekunde;
	double uglovi[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&brojUglova);
	if(brojUglova>500) brojUglova=500;
	for(i=0;i<brojUglova;i++){
		scanf("%lf",&uglovi[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<brojUglova;i++){
		stepeni=(int)(fabs((uglovi[i]*180/PI)));
		minute=(int)(fabs(((fabs(uglovi[i]*180/PI)-stepeni)*60)));
		sekunde=(int)(((fabs(uglovi[i]*180/PI)-stepeni)*60-minute)*60+0.5);
		if(sekunde>=60){
			minute++;
			sekunde=(int)(sekunde)%60;
		}
		if(minute>=60){
			stepeni++;
			minute=(int)(minute)%60;
		}
		if(uglovi[i]<0) stepeni*=-1;
		if(sekunde<=30) printf("%g stepeni %g minuta %g sekundi\n",stepeni,minute,sekunde);
		
		}
	return 0;	
}
