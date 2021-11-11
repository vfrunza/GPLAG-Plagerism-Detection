#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define vel 500

int main() {
	int i,j,n, stepeni=0, sekunde=0, minute=0, ukupnosek=0;
	double uglovi [vel];
	
	printf ("Unesite broj uglova: ");
	scanf ("%d", &n);
	
	if  (n<1 || n>500) {
		printf ("Uneseni ugao veci je od 500.");
		return 0;}
		
	for (i=0; i<n; i++) {
		scanf("%lf", &uglovi[i]);
	}
	
	for (i=0; i<n; i++){
		
		if (uglovi[i]>0) {
			ukupnosek=((uglovi[i]*(180/PI)*3600)+0.5);
		}
		else {
			ukupnosek=((uglovi[i]*(180/PI)*3600)-0.5);
		}
		
		stepeni=ukupnosek/3600;
		minute=(fabs((ukupnosek-stepeni*3600)/60));
		sekunde=(fabs(ukupnosek-stepeni*3600-minute*60));
		
		if (sekunde>30) {
			for (j=i; j<n-1; j++)
			uglovi[j]=uglovi[j+1];
		
		i--;
		n--;
		}	
	}
		if (n>0) {{
			printf ("Uglovi su: \n");
			}
		for ( i=0; i<n; i++) {
			if (uglovi[i]>0) {
				ukupnosek=((uglovi[i]*(180/PI)*3600)+0.5);
			}
			else {ukupnosek=((uglovi[i]*(180/PI)*3600)-0.5);
				
			}
			stepeni=ukupnosek/3600;
			minute=(fabs((ukupnosek-stepeni*3600)/60));
			sekunde=(fabs(ukupnosek-stepeni*3600-minute*60));
			printf ("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);	
			}}
		
	return 0;
}


