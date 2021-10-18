#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define pi 3.1415926535

int main() {
	double x1, x2, x3, y1, y2, y3, d1=0, d2=0, d3=0, alfa=0, minute=0, sekunde=0,
	stepenip=0, minutep=0, sekundep=0;
	
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf%lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf%lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf%lf", &x3, &y3);
	d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	d3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	if (d1>=d2 && d1>=d3) alfa =acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3))*(180./pi);
	else if (d2>d1 && d2>d3) alfa=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3))*(180./pi);
	else if (d3>d1 && d3>d2) alfa=acos((d1*d1+d2*d2-d3*d3)/(2*d2*d1))*(180./pi);
	stepenip=(int)alfa;
    minute=fabs((alfa-stepenip)*60);
    minutep=(int)minute;
    sekunde=fabs((minute-minutep)*60);
    sekundep=(int)(sekunde);
    
    if(stepenip<0) { 
    
    if (sekundep>=60 || sekundep<=-60) {minutep++; sekundep=sekundep-60; }
    if (minutep>=60 || minutep<=-60)  {stepenip--; minutep=minutep-60;}
        
    }
        
    if (sekundep>=60 || sekundep<=-60) {minutep++; sekundep=sekundep-60; }
    if (minutep>=60 || minutep<=-60)  {stepenip++; minutep=minutep-60;}

	
	if (fabs (((x2-x1)/(x3-x1))-((y2-y1)/(y3-y1))) < epsilon || (fabs(y1-y2)<epsilon && fabs(y2-y3)<epsilon) || (fabs(x1-x2)<epsilon && fabs(x2-x3)<epsilon) ) { 
		printf ("Linija");
		printf ("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
	
	else if (fabs(d1-d2)<epsilon && fabs(d1-d3)<epsilon && fabs(d2-d3)<epsilon) {
		printf ("Jednakostranicni");
		printf ("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}	
	
	else if (fabs((d3*d3)-(d2*d2+d1*d1))<epsilon || fabs((d2*d2)-(d1*d1+d3*d3))<epsilon || fabs((d1*d1)-(d2*d2+d3*d3))<epsilon ) {
		if (fabs(d2-d1)<epsilon || fabs(d1-d3)<epsilon || fabs(d2-d3)<epsilon) {
				printf ("Pravougli");
		        printf ("\nJednakokraki");
		        printf ("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		}
	 else if (fabs(d1-d2)>epsilon && fabs(d1-d3)>epsilon && fabs(d2-d3)>epsilon) {
	 		printf ("Pravougli");
		    printf ("\nRaznostranicni");
		    printf ("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	 }
	
		
	}
	
		
		else if (fabs(d2-d1)<epsilon || fabs(d1-d3)<epsilon || fabs(d2-d3)<epsilon) {
		printf ("Jednakokraki");
		printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepenip, minutep, sekundep);
		}
	
	
		
		else if (fabs(d1-d2)>epsilon && fabs(d1-d3)>epsilon && fabs(d2-d3)>epsilon) {
		printf ("Raznostranicni");
		printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepenip, minutep, sekundep);
	
		}
			

	
	
	return 0;
}
