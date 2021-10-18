#include <stdio.h>
#include <math.h>
#define pi 3.1415926
int main() {
	double niz[500],stepen,minuta,sekunda;
	int STEPEN,MINUTA,SEKUNDA,ugl,i;
	printf ("Unesite broj uglova: ");
	scanf ("%d",&ugl);
	for (i=0;i<ugl;i++){
	    scanf ("%lf",&niz[i]);
	}
	printf ("Uglovi su: ");
	for (i=0;i<ugl;i++){
	    stepen=niz[i]*180/pi;
	    STEPEN=(int)stepen;
	    minuta=stepen-STEPEN;
	    minuta=minuta*60;
	    MINUTA=(int)minuta;
	    sekunda=minuta-MINUTA;
	    sekunda=sekunda*60;
	    SEKUNDA=round(sekunda);
	    if (SEKUNDA==60){SEKUNDA=0; MINUTA=MINUTA+1;}
	    if (SEKUNDA==-60){SEKUNDA=0; MINUTA=MINUTA-1;}
	    if (MINUTA==60){MINUTA=0; STEPEN=STEPEN+1;}
	    if (MINUTA==-60){MINUTA=0; STEPEN=STEPEN-1;}
	    MINUTA=fabs(MINUTA);
	    SEKUNDA=fabs(SEKUNDA);
	    if(SEKUNDA<=30){
	    printf ("\n%d stepeni %d minuta %d sekundi",STEPEN,MINUTA,SEKUNDA);
	    }
	}
	return 0;
}
