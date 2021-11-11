#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#include <math.h>

int main() {
	double niz[500], st1, min1, sec1;
	int i, stepeni[500], minuta[500], a, sekundi[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&a);
	
	
	for(i=0;i<a;i++){
		scanf("%lf", &niz[i]);
		stepeni[i]=niz[i]*180/PI;
		st1=fabs(niz[i]*180./PI) - abs(stepeni[i]);
		minuta[i]=st1*60;
		min1=st1*60. - minuta[i];
		sec1=min1*60.;
		sekundi[i]=min1*60;
		if(sec1-abs(sekundi[i])+0.5>=1){
				sekundi[i]++;
		}	
		if(sekundi[i]+0.05>=60){
			sekundi[i]=0;
			minuta[i]++;
		}
		if(minuta[i]+0.05>=60){
			minuta[i]=0;
			if(stepeni[i]<0)
				stepeni[i]--;
			else
				stepeni[i]++;
		}
		
		
		if(abs(sekundi[i])>30)
			niz[i]=(-1);
		
		
	}
	printf("Uglovi su: \n");
	for(i=0;i<a;i++){
		if(niz[i]!=(-1)){
			printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], minuta[i], sekundi[i]);
			
		}
	
	}
	return 0;
}
