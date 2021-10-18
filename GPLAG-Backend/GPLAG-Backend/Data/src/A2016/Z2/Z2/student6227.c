#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	
	int a, st=0, min=0, sec=0, i, uksek;
	double uksec=0,niz[500];
	
	printf ("Unesite broj uglova: ");
	scanf ("%d", &a);
	while (a>500){
		printf("Pogresan unos! ");
		printf ("Unesite broj uglova: ");
		scanf ("%d", &a);
	}
	
	for (i=0;i<a;i++){
		scanf ("%lf", &niz[i]);
	}
	printf ("Uglovi su: \n");
	
	for (i=0;i<a;i++){
		uksec=(niz[i]*180/PI)*3600;
		if(uksec<0) uksek=uksec-0.5;
		else uksek=(int)(uksec+0.5);
		st=uksek/3600;
		min=(uksek-st*3600)/60;
		sec=uksek-st*3600-min*60;
		
		if(sec<0) sec=abs(sec);
		if(min<0) min=abs(min);
		
		
		if (sec>=60) {min++; sec-=60;}
		if (min>=60) {st++; min-=60;}
		if (sec>30 || sec<-30){continue;}
		
		printf ("%d stepeni %d minuta %d sekundi\n", st, min, sec);
	}
	
	
	return 0;	
}
