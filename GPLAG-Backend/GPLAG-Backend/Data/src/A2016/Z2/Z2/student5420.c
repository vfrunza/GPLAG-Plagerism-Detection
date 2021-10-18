#include <stdio.h>
#define PI 3.1415926

int main() {
	int BE,i,j,step=0,min=0,sek=0;
	double niz[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &BE);
	printf("Uglovi su: \n");
	for(i=0; i<BE; i++){
		scanf("%lf", &niz[i]);
	}
	for(i=0; i<BE; i++){
		step=(int)(niz[i]*180/PI);
		if(step>=0){
		min=(int)(((niz[i]*180/PI)-step)*60);
		sek=(int)(((((niz[i]*180/PI)-step)*60)-min)*60+0.5);
		}
		if(step<0){
		min=(int)(((niz[i]*180/PI)*(-1)-step*(-1))*60);
		sek=(int)(((((niz[i]*180/PI)*(-1)-step*(-1))*60)-min)*60+0.5);	
		}
	if(sek>=60){
		min++;
		sek-=60;
	}
	if(min>=60){
		step++;
		min-=60;
	}
	if(sek>30){
		for(j=i; j<BE-1; j++){
			niz[j]=niz[j+1];
		}
			BE--;
			i--; 
			continue;
		}
		printf("%d stepeni %d minuta %d sekundi\n", step,min,sek);
	}
	return 0;
}
