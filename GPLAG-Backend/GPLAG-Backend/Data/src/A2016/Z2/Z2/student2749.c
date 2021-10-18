#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926
#define epsilon 0.001
int main() {
	int n,i,j;
	float uglovi[1000],stepeni[1000],minute[1000],sekunde[1000];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i = 0; i < n; i++){
	scanf("%f",&uglovi[i]);
	stepeni[i] = (uglovi[i]*180.00)/pi;
	minute[i] = stepeni[i] - (int)stepeni[i];
	minute[i] *= 60;
	sekunde[i] = minute[i] - (int)minute[i];
	sekunde[i] *= 60;
	if((int)minute[i] >= 60){
		stepeni[i] = stepeni[i] + 1;
		minute[i] -= 60;
	}
	if((int)sekunde[i] >= 60){
		minute[i] = minute[i] + 1;
		sekunde[i] -= 60;
	}
	}
	for(i = 0;i < n; i++){
		if(abs(sekunde[i]) > 30){
			for(j = i; j < n-1; j++){
				stepeni[j] = stepeni[j+1];
				minute[j] = minute[j+1];
				sekunde[j] = sekunde[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i = 0; i < n; i++){
		printf("%d stepeni %d minuta %d sekundi\n",(int)stepeni[i],abs((int)minute[i]),abs((int)round(sekunde[i])));
	}
	return 0;
}
