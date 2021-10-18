#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
    double radijani[500];
    int br_uglova,i,j,stepeni,minute,sekunde;
    printf("Unesite broj uglova: ");
    scanf("%d", &br_uglova);
    for(i=0;i<br_uglova;i++)  scanf("%lf", &radijani[i]);
    printf("Uglovi su: \n");
    for(i=0;i<br_uglova;i++){
    	radijani[i]*=(180./PI);
    	stepeni=(int)radijani[i];
    	minute=(int)((fabs(radijani[i])-fabs(stepeni))*60.);
    	sekunde=(int)(((fabs(radijani[i])-fabs(stepeni))*60.-minute)*60.+0.5);
    	if(sekunde>=60){ sekunde-=60; minute++;}
    	if(minute>=60) {minute-=60; if(stepeni<0) stepeni--; else stepeni++;}
    	if(sekunde>30){
    		for(j=i;j<br_uglova-1;j++) radijani[j]=radijani[j+1];
    		br_uglova--;
    		i--;
    	}
    	else{
    	    if(radijani[i]<0 && stepeni==0) printf("-%d stepeni %d minuta %d sekundi\n", stepeni,minute,sekunde);
    		else printf("%d stepeni %d minuta %d sekundi\n", stepeni,minute,sekunde);
    	}
    }
	return 0;
}
