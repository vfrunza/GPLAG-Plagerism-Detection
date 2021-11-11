#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double radugl[500]={0};
	int i, j, n, step, min, sec, stepost, uksec;
	printf("Unesite broj uglova: "); scanf("%d", &n);
	/*Unos clanova*/
	for (i=0; i<n; i++){
		scanf("%lf", &radugl[i]);
	}
	/*Izbacivanje uglova ciji broj sekundi prelazi 30*/
	for (i=0; i<n; i++){
			uksec=round(radugl[i]*(180/PI)*3600);
			step=uksec/3600; stepost=uksec%3600;
			min=abs(stepost/60);
			sec=abs(stepost%60);
			
			if (sec>30){
				for (j=i; j<n-1; j++){
					radugl[j]=radugl[j+1];
				}
				i--; n--;
			}
	}
	/*Ispis ostalih uglova uz ocuvan redoslijed*/
	printf("Uglovi su:\n");
	for (i=0; i<n; i++){
			uksec=round(radugl[i]*(180/PI)*3600);
			step=uksec/3600; stepost=uksec%3600;
			min=abs(stepost/60);
			sec=abs(stepost%60);
			printf("%d stepeni %d minuta %d sekundi\n", step, min, sec);
	}
	return 0;
}