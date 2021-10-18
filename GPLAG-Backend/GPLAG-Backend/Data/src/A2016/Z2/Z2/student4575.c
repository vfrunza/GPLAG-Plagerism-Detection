#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int i=0, x, stepeni[499], minute[499], sekunde[499];
	float niz[499];
	printf("Unesite broj uglova: ");
	scanf("%d", &x);
	for(i=0;i<x;i++){
		scanf("%f", &niz[i]);
	}
	for(i=0;i<x;i++){
		stepeni[i]=niz[i]*180/PI;
	}
	for(i=0;i<x;i++){
		minute[i]=niz[i]*10800/PI-stepeni[i]*60;
	}
	for(i=0;i<x;i++){
		sekunde[i]=floor(0.50+(niz[i]*648000.0000/PI-minute[i]*60.0000-stepeni[i]*3600.0000));
	if(stepeni[i]>0.00){
		if(sekunde[i]==60){
			sekunde[i]=0;
			minute[i]=minute[i]+1;
		}
		if(minute[i]==60){
			minute[i]=0;
			stepeni[i]=stepeni[i]+1;
		}
	}
	if(stepeni[i]<0.00){
		if(sekunde[i]==-60){
			sekunde[i]=0;
			minute[i]=minute[i]-1;
		}
		if(minute[i]==-60){
			minute[i]=0;
			stepeni[i]=stepeni[i]-1;
		}
		minute[i]=-minute[i];
		sekunde[i]=-sekunde[i];
	}
	}
	printf("Uglovi su:\n");
	for(i=0;i<x;i++){
		if(sekunde[i]<=30.00 && sekunde[i]>=-30.00){
			printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], minute[i], sekunde[i]);
		}
	}
	return 0;
}
