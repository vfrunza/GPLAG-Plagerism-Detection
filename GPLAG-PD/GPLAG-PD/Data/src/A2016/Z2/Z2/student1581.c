#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define MAX 500
int main() {
	/*	printf("Zadaća 2, Zadatak 2");*/
	
	int n,i,j,k;
	double a[MAX];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%lf\n",&a[i]);
	}

	printf("Uglovi su:");
	
	for(j=0; j<n; j++){
		double ukupno_sekundi;
		int stepeni,minuta,sekundi;
		ukupno_sekundi=(a[j]*180/PI)*3600;
		ukupno_sekundi=(int)(ukupno_sekundi+0.5);
		stepeni=ukupno_sekundi/3600;
		minuta=abs((ukupno_sekundi-stepeni*3600)/60);
		sekundi=abs(ukupno_sekundi-stepeni*3600-minuta*60);
		
		if(sekundi>=60){
			minuta++;
			sekundi=sekundi-60;
		}
		
		if(minuta>=60){
			stepeni++;
			minuta=minuta-60;
		}
		
		if(sekundi>30){
			for(k=j; k<n-1; k++){
				a[k]=a[k+1];
			}
			n--;
			j--;
			
		}
		
		
		else{
			printf("\n%d stepeni %d minuta %d sekundi", stepeni,minuta,sekundi);
		}
	}
	
	
	return 0;
}

