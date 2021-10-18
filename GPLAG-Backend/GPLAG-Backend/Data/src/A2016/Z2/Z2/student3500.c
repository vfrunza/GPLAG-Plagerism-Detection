#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926


int main() {
	int n, i, j;
	float niz[500];
	int step, min, sek;
	do{
		printf("Unesite broj uglova: ");
	    scanf("%d", &n);
	}while((n<0)||(n>500));
	
	for(i=0;i<n;i++){
		scanf("%f", &niz[i]);
	}
	for(i=0;i<n;i++){
		
		if(((((int)(niz[i]*(180/PI)*60*60)%3600)%60)>30)||((((int)(niz[i]*(180/PI)*60*60)%3600)%60)<-30)){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			
			
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		step=(int)(niz[i]*180/PI);
		min=((int)(niz[i]*(180/PI)*60))%60;
		if(niz[i]>0) sek=((int)((niz[i]*(180/PI)*3600)+0.5))%60;
		else sek=((int)((niz[i]*(180/PI)*3600)-0.5))%60;
		printf("%d stepeni %d minuta %d sekundi\n", step, abs(min), abs(sek));
	}
	
	return 0;
}
