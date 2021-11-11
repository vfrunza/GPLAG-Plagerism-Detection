#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159226
#define ep 0.00000000000000000000000000000001
int main() {
	int br_uglova, i;
	int stepen[500], minuta[500]={0}, sekunda[500];
	double rad_ugao[500], sek;
	printf("Unesite broj uglova: ");
	scanf("%d", &br_uglova);
	for(i=0; i<br_uglova; i++)
		scanf("%lf", &rad_ugao[i]);

	for(i=0; i<br_uglova; i++){
		sek = rad_ugao[i]*180/pi;
		
		stepen[i] = (rad_ugao[i]*180/pi);
		sekunda[i] = (0.5+(sek - (int)sek)*3600);
		
		while(sekunda[i]>=60){
			sekunda[i]-=60;
		    minuta[i]++;
		}
		while(minuta[i]>=60){
			minuta[i]-=60;
			stepen[i]++;
		}
		if(rad_ugao[i]<0) {
			sekunda[i]--;
			while(sekunda[i]<=-60){
				minuta[i]--;
				sekunda[i]+=60;
			}
			while(minuta[i]<=-60){
				stepen[i]--;
				minuta[i]+=60;
			}
		}
     	if(rad_ugao[i]+pi<ep)
     		sekunda[i]++;
     	if(rad_ugao[i]+3.15<ep)
     		sekunda[i]--;
	}
	printf("Uglovi su:\n");
	for(i=0; i<br_uglova; i++) {
		if(sekunda[i] > 30 || sekunda[i] < -30) continue;
		minuta[i] = abs(minuta[i]);
		sekunda[i] = abs(sekunda[i]);
		printf("%d stepeni %d minuta %d sekundi\n", stepen[i], minuta[i], sekunda[i]);
	}
	return 0;
}
