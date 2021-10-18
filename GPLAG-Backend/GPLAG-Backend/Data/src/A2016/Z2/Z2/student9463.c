#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n, i, k, j;
	double uglovi[500],stepeni, minute, sekunde, stepeni1, minute1, sekunde1;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for (i=0; i<n; i++){
		scanf("%lf", &uglovi[i]);
	}
	for(j=0; j<n; j++){
		stepeni=uglovi[j]*(180/PI);
		minute=fabs((double)(stepeni-(int)stepeni)*60);
		sekunde=fabs((double)(minute-(int)minute)*60);
		stepeni1=(int)stepeni;
		minute1=(int)minute;
		sekunde1=(int)(sekunde+0.5);
		if(sekunde1>=60){minute1++; sekunde1=sekunde1-60;}
		if(minute1>=60){
			if (stepeni1<0){
				stepeni1--;
				minute1=minute1-60;
			}
			else{
			(stepeni1)++; 
			minute1=minute1-60;
			}
		}
		
		if (fabs(sekunde1)>30){
			for (k=j; k<n-1; k++){
				uglovi[k]=uglovi[k+1];
			}
			n--;
			j--;
		}
	}
	printf("Uglovi su:\n");
	for (i=0; i<n; i++){
		stepeni=uglovi[i]*(180/PI);
		minute=fabs((double)(stepeni-(int)stepeni)*60);
		sekunde=fabs((double)(minute-(int)minute)*60);
		stepeni1=(int)stepeni;
		minute1=(int)minute;
		sekunde1=(int)(sekunde+0.5);
		if(sekunde1>=60){minute1++; sekunde1=sekunde1-60;}
		if(minute1>=60){
			if(stepeni1<0){
				stepeni1--;
				minute1=minute1-60;
			}
			else{
			stepeni1++; 
			minute1=minute1-60;}
		}
		printf("%.lf stepeni %.lf minuta %.lf sekundi\n", stepeni1, minute1, sekunde1);
	}
	return 0;
}
