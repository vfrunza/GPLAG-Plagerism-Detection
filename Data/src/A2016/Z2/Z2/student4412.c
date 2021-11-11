#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	float niz[500];
	int n, i, j,a,b;
	float x;
	x=180/PI;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%f", &niz[i]);
	}
	for(i=0; i<n; i++){
		int step, min, sek;
		float y, z;
		y=niz[i]*x;
		step=(int)y;
		z=(y-step)*60;
		min=(int)z;
		sek=round((z-min)*60.); 
		if(sek==60) {
		
			sek=0;
			min+=1;
			if(min==60){
				
				step+=1;
				min=0;
				
			}
		}
		if(sek==-60) {
		
			sek=0;
			min-=1;
			if(min==-60){
				
				step-=1;
				min=0;
				
			}
		}
		if(sek>30 || sek<-30){
			for(j=i; j<n; j++){
				niz[j]=niz[j+1];
			}
			i--;
			n--;
		}
	}

	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		int step, min, sek;
		float y, z;
		y=niz[i]*x;
		step=(int)y;
		z=(y-step)*60;
		min=(int)z;
		sek=round((z-min)*60.);
		if(sek==60) {
		
			sek=0;
			min+=1;
			if(min==60){
				
				step+=1;
				min=0;
				
			}
		}
		if(sek==-60) {
		
			sek=0;
			min-=1;
			if(min==-60){
				
				step-=1;
				min=0;
				
			}
		}
		a=abs(round(min));
		b=abs(sek);
		printf("%d stepeni %d minuta %d sekundi\n", step, a, b);
	}
	return 0;
}
