#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	
	int n, i, j;
	double minute, sekunde;
	double ugao[500];
	double sek[500];
	int min[500];
	
	do{
		
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
	
		
	}while(n <= 0 || n > 500);
	
	for (i = 1; i <= n; i++){
		
		scanf("%lf", &ugao[i]);
		
	}
	
	printf("Uglovi su:\n");
	
	for (i = 1; i <= n; i++){
		
		ugao[i] = ugao[i]*180/PI;
		
		minute = (fabs(ugao[i]) - abs((int) ugao[i])) * 60;
		
		sekunde = (fabs(minute) - abs((int) minute)) * 60;
		
		sekunde = (int)(sekunde  + 0.5);
			
	
		if (sekunde == 60){
			
			minute++;
			sekunde = 0;
			
		}
		
		sek[i] = sekunde;
		
		if ((int)minute == 60){
		
			if (ugao[i] > 0){
				ugao[i]++;
				minute = 0;
			}
			else if (ugao[i] < 0){
					
				ugao[i]--;
				minute = 0;
			}
		}
		
		
		min[i] = minute;
		
	}
	
	for (i = 1; i <= n; i++){
		
		if (fabs(sek[i]) > 30){
			
			for (j = i; j <= n - 1; j++){ //Izbacivanje
				
				ugao[j] = ugao[j + 1];
				min[j] = min[j + 1];
				sek[j] = sek[j + 1];
				
			}
			
			n--;
			i--;
		}
		
	}
	
	for (i = 1; i <= n; i++){
		
		printf("%d stepeni %d minuta %g sekundi\n", (int)ugao[i], (int) min[i], sek[i]); //Printanje neizbacenih
		
	}
	
	return 0;
}
