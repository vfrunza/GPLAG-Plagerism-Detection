#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	
	int brojUglova, i, stepen[500], minuta[500], sekunde[500], j;
	double ugao[500], ukupnoSekundi[500];
	
	do {
	printf("Unesite broj uglova: ");
	scanf("%d", &brojUglova);
	
	} while(brojUglova < 1 && brojUglova > 500 );
	

	
	for(i = 0; i < brojUglova; i++) {
		
		scanf("%lf", &ugao[i]);
		
		ukupnoSekundi[i] = (int)(((ugao[i] * (180 / PI)) * 3600) + 0.5);
	
		stepen[i] = ukupnoSekundi[i] / 3600;
		minuta[i] = (ukupnoSekundi[i] - stepen[i] * 3600) / 60;
		sekunde[i] = ukupnoSekundi[i] - stepen[i] * 3600 - minuta[i] * 60;
		
		if(sekunde[i] >= 60) { minuta[i]++; sekunde[i] -= 60; }
		if(minuta[i] >= 60) { stepen[i]++; minuta[i] -= 60; }
		sekunde[i] = sekunde[i] % 60;
		
		if(sekunde[i] > 30 || sekunde[i] < - 30) {
			for(j = i; j < brojUglova; j++) {
				
				ugao[j] = ugao[j + 1];
			}
			brojUglova--;
			i--; 
		}
		
	}
		printf("Uglovi su:\n");
	for(i = 0; i < brojUglova; i++) {
		
		if(ugao[i] < 0) {
			
			minuta[i] = abs(minuta[i]);
			sekunde[i] = abs(sekunde[i]);
			sekunde[i]++;	
			}
		
		printf("%d stepeni %d minuta %d sekundi\n", stepen[i], minuta[i], sekunde[i]);
	}
	
	return 0;
}
