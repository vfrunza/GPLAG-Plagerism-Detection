#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int i,brojUglova,j;
	float ugao[500];
	int stepeni[500],minute[500],ukupnesekunde,sekunde[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&brojUglova);
	
	for(i=0;i<brojUglova;i++){
		scanf("%f",&ugao[i]);
		stepeni[i]=0;
		minute[i]=0;
		sekunde[i]=0;
	}
	
	for(i=0;i<brojUglova;i++){
		ukupnesekunde = (int)round(ugao[i]*1296000/(2*PI));
		
		sekunde[i] = ukupnesekunde % 60; 
		sekunde[i] = fabs(sekunde[i]);
		
		minute[i]  = (ukupnesekunde / 60) % 60;
		minute[i] = fabs(minute[i]);
		
		stepeni[i] = ukupnesekunde / (60*60);
	}
	for(i = 0;i<brojUglova;i++){
		if(sekunde[i]>30){
			for(j = i ;j<brojUglova;j++){
				stepeni[j]=stepeni[j+1];
				minute[j] =minute[j+1];
				sekunde[j]=sekunde[j+1];
			}
			brojUglova--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<brojUglova;i++){
		printf("%d stepeni %d minuta %d sekundi\n",stepeni[i],minute[i],sekunde[i]);
	}
	return 0;
}
