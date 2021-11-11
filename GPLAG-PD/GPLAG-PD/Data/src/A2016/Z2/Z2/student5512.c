#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#include <math.h>
int n=0,i,j,step,sec,min;
double niz[500],rad,min1 ;

int main() {
		printf ("Unesite broj uglova: ");
		scanf ("%d", &n);
	do{	
	scanf ("%lf", &niz[i]);
	i++;}
	while (i<n);
	printf ("Uglovi su: \n");
	for (j=0; j<n; j++){
		step=niz[j]*(180./PI);
		rad=niz[j]*(180./PI);
		min1=fabs((rad-step)*60);
	    min=fabs((rad-step)*60);
		sec=(min1-min)*60+0.5;
		if (sec==60 && min>=59){
			sec=0;
			min=0;
			if (step<0)
				step--;
			if (step>0)
				step++;}
		if (sec==60){
			sec=0;
			min++;}		
		if (sec>30 && sec<60){
			for (i=j; i<n; i++)
				niz[i]=niz[i+1];
				n--;
				j--;
				continue;}
		printf ("%d stepeni %d minuta %d sekundi\n", step,min,sec);}	
			
		
	return 0;}

