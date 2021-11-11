#include <stdio.h>
#include<math.h>
#define PI 3.1415926

int main() {
	int n;
	int X;
	int i,j;
	float niz[500];
    int stepeni, minute, sekunde;
	float ukupno_sekundi;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%f", &niz[i]);
	}
	
	printf("Uglovi su: \n");
	
	for(i=0;i<n;i++){
		ukupno_sekundi=(niz[i]/PI)*(180*60*60);
		if((ukupno_sekundi-(int)ukupno_sekundi)>0.5){
			
		X=ukupno_sekundi+1;
	}
		else X=ukupno_sekundi;
		
		stepeni=(X/3600);
		minute=fabs(X%3600)/60;
		
		sekunde=fabs(X%60);
		
		if(sekunde>30){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
		else if(sekunde<=30)
		printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
		/*printf("Uglovi su:\n");*/
	}
	
	return 0;
}
