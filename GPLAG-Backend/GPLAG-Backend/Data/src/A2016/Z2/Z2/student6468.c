#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	float niz[500];
	int counter, total, i;
	int stepeni[500], minute[500], sekunde[500];
	int stepeniTmp[500], minuteTmp[500], sekundeTmp[500];
	printf("Unesite broj uglova: ");
	scanf("%i", &counter);
	for(i=0; i<counter; i++){
		scanf("%f", &niz[i]);
	}
	for(i=0; i<counter; i++){
		total = (int)round(niz[i] * 360 * 60 * 60 / (2*PI));
		sekunde[i] = total % 60;
		minute[i] = (total / 60) % 60;
		stepeni[i] = total / (60 * 60);
		if(sekunde[i]<0) sekunde[i]*=-1;
		if(minute[i]<0) minute[i]*=-1;
	}
	
	total=0;
	for(i=0; i<counter; i++){
		if(sekunde[i]<=30){
			stepeniTmp[total]=stepeni[i];
			minuteTmp[total]=minute[i];
			sekundeTmp[total]=sekunde[i];
			total++;
		}
	}
	printf("Uglovi su:\n");
	for(i=0; i<total; i++)
		printf("%i stepeni %i minuta %i sekundi\n", stepeniTmp[i], minuteTmp[i], sekundeTmp[i]);
		return 0;
}
