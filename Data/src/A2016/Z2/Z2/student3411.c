#include <stdio.h>
#define PI 3.1415926
#include <math.h>
#include <stdlib.h>

int main() {
	int x, i, j, stepeni, minute, sekunde, br=0, b[500]={0}, c[500]={0}, d[500]={0};
	double a[500]={0}, stepenif, minutef, sekundef, ugao; 
	printf("Unesite broj uglova: ");
	scanf("%d", &x);
	for(i=0; i<x; i++){
		scanf("%lf", &a[i]);}
	for(i=0; i<x; i++){
		ugao=a[i]*180/PI;
		stepeni=ugao;
		stepenif=ugao;
		minutef=(fabs(stepenif)-abs(stepeni))*60;
		minute=minutef;
		sekundef=(minutef-minute)*60;
		sekundef=sekundef+0.5;
		sekunde=sekundef;
		if(sekunde==60) {minute++; sekunde=0;}
		if(minute==60 && stepeni>=0) {stepeni++; minute=0;}
		if(minute==60 && stepeni<=0) {stepeni--; minute=0;}
			b[br]=stepeni; 
			c[br]=minute;
			d[br]=sekunde; 
			br++;
	}
	for(i=0; i<br; i++){
		if(d[i]>30){
			for(j=i; j<(br-1); j++){
				b[j]=b[j+1];
				c[j]=c[j+1];
				d[j]=d[j+1];
			}
			br--;
			i--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0; i<br; i++){
		printf("%d stepeni ", b[i]);
		printf("%d minuta ", c[i]);
		printf("%d sekundi ", d[i]);
		printf("\n");
	}
	return 0;
}
