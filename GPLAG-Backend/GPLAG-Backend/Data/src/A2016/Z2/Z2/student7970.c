#include <stdio.h>
#define BROJ_EL 500
#define PI 3.1415926

int main() {
	int n,i,j;
	float uglovi[BROJ_EL];
	float ukupno_sekundi;
	int stepeni, minute, sekunde;
	
	
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	    
	for(i=0; i<n; i++){
		scanf("%f\n",&uglovi[i]);
	}
	
    printf("Uglovi su:\n");
	
	for(i=0; i<n; i++){
		ukupno_sekundi=((uglovi[i]*180)/PI)*60*60;
		ukupno_sekundi=(int)(ukupno_sekundi+0.5);
		stepeni=ukupno_sekundi/3600;
		minute=(ukupno_sekundi-stepeni*3600)/60;
		sekunde=ukupno_sekundi-stepeni*3600-minute*60;
		
		if(sekunde>=60){
			minute=minute+1;
			sekunde=sekunde-60;
		}
		if(minute>=60){
			stepeni=stepeni+1;
			minute=minute-60;
		}
		
		if(sekunde>30) {
		for(j=i; j<n-1; j++){
			uglovi[j]=uglovi[j+1];
		}
		n--;
		i--;
		}
	}
		for(i=0; i<n; i++){
		ukupno_sekundi=((uglovi[i]*180)/PI)*60*60;
		ukupno_sekundi=(int)(ukupno_sekundi+0.5);
		stepeni=ukupno_sekundi/3600;
		minute=(ukupno_sekundi-stepeni*3600)/60;
		sekunde=ukupno_sekundi-stepeni*3600-minute*60;
		
		if(sekunde>=60){
			minute=minute+1;
			sekunde=sekunde-60;
		}
		if(minute>=60){
			stepeni=stepeni+1;
			minute=minute-60;
		}
		if(uglovi[i]<0){
			minute=-minute;
			sekunde=-sekunde;
			printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde+1);
		} else
		printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
	}
	return 0;
}
