#include <stdio.h>
#define PI 3.1415926

int main() {
	
	float uglovi[500], rad=180/PI,  ukupno_sekundi;
	int stepeni, minute, sekunde;
	int n, i, j;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		scanf("%f", &uglovi[i]);
	}
	
	for(i=0; i<n; i++) {
		if(uglovi[i]<0) ukupno_sekundi=((uglovi[i]*rad)*3600) - 0.5;
		else {
		ukupno_sekundi=((uglovi[i]*rad)*3600)+ 0.5;
		}
		sekunde=(int)ukupno_sekundi % 60;
		minute=((int)ukupno_sekundi/60) % 60;
		stepeni=ukupno_sekundi/3600;
		if(sekunde>30 || sekunde<(-30)) {
			for(j=i; j<n; j++) {
				uglovi[j]=uglovi[j+1];
			}
			n--;
			i--;
		}
	}
	
	printf("Uglovi su:\n");
	for(i=0; i<n; i++) {
		if(uglovi[i]<0) ukupno_sekundi=((uglovi[i]*rad)*3600) - 0.5;
		else {
		ukupno_sekundi=((uglovi[i]*rad)*3600)+ 0.5;
		}
		sekunde=(int)ukupno_sekundi%60;
		if(sekunde<0) sekunde=-sekunde;
		minute=((int)ukupno_sekundi/60)%60;
		if(minute<0) minute=-minute;
		stepeni=ukupno_sekundi/3600;
		printf("%d stepeni %d minuta %d sekundi\n", (int)stepeni, (int)minute, (int)sekunde);
	}
	
	
	return 0;
}
