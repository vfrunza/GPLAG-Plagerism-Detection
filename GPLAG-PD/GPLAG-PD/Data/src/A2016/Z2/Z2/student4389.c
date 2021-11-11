#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int i, n, j, stepen, minuta, sekunda; 
	double a[500], niz[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su:\n");
	for(i=0; i<n; i++){
		a[i] = niz[i] * 180 / PI;
		stepen = (int)(a[i]);
		minuta = (int)((a[i] - stepen) * 60);
		if((((a[i] - stepen) * 60 - minuta) * 60) < 0){
			sekunda = (int)(((a[i] - stepen) * 60 - minuta) * 60 - 0.5);
		}else{
			sekunda = (int)(((a[i] - stepen) * 60 - minuta) * 60 + 0.5);
		}
		sekunda = abs(sekunda);
		minuta = abs(minuta);
		if(sekunda == 60){
			minuta++;
			sekunda = 0;
		}
		if(minuta == 60){
			if(stepen<0){
				stepen--;	
			}
			if(stepen>0){
				stepen++;
			}
			minuta = 0;
		}
		if(sekunda<= 30){
			printf("%d stepeni %d minuta %d sekundi\n", stepen, minuta, sekunda);
		}
		if(sekunda>30){
			for(j=0; j<n-1; j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	return 0;
}