#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS  0.0001
#define PI  3.14159



int main() {
	double t1x, t1y, t2x, t2y, t3x, t3y, a, b, c, P;
	int sek, min, step; 
	int k, l, z;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &t1x, &t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &t2x, &t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &t3x, &t3y);
	
	k = 10;
	l = 10;
	z = 10;
	
	P =  0.5 * fabs( t1x * (t2y - t3y) + t2x * (t3y - t1y) + t3x * (t1y - t2y) );

	a = sqrt ( (t2x-t1x)*(t2x-t1x) + (t2y-t1y)*(t2y-t1y) );

	b = sqrt ( (t3x-t2x)*(t3x-t2x) + (t3y-t2y)*(t3y-t2y) );

	c = sqrt ( (t3x-t1x)*(t3x-t1x) + (t3y-t1y)*(t3y-t1y) );


	if( fabs(P-0)<EPS ) {
		printf("Linija\n");
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", 180, 0, 0);
		l = 1;
	} else if (fabs(a-b)<EPS && fabs(b-c)<EPS) {
		printf ("Jednakostranicni\n");
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", 60, 0, 0);
		l = 1;
	} else if (fabs(a*a+b*b - c*c) < EPS) {
		
		printf ("Pravougli\n");
		k = 1;
		
	} else if (fabs(a*a+c*c - b*b) < EPS) {
		
		printf ("Pravougli\n"); 
		k = 1;
		
	} else if (fabs(b*b+c*c -a*a) < EPS) {
		
		printf ("Pravougli\n");
		k = 1;
	}

   
   
    if ( fabs(P-0)>EPS && fabs(a-b)>EPS && fabs(b-c)>EPS && fabs(a-c)>EPS) {
		
		printf ("Raznostranicni\n"); 
		
		} else if ((l == 10) && fabs(P-0)>EPS && fabs(a-b)<EPS) {
		
		printf("Jednakokraki\n"); 
		
	} else if ((l == 10) && fabs(P-0)>EPS && fabs(c-b)<EPS) {
		
		printf("Jednakokraki\n"); 
		
	} else if ((l == 10) && fabs(P-0)>EPS && fabs(c-a)<EPS) {
		printf("Jednakokraki\n"); 
	}
	
	
 if ((k == 10) && (l == 10)) {
 	    if (c>=a && c>=b) {
 	    	sek = asin(2*P/(a*b)) * (180/PI) * 3600;
 	    	if (c*c>(a*a+b*b)){
 	    		z = 1;
 	    	}
		} else if  (a>=b && a>=c) {
			
			sek = asin(2*P/(b*c)) * (180/PI) * 3600;
				if (a*a>(b*b+c*c)){
 	    		z = 1;
 	    	}
		} else if  (b>=a && b>=c) {
			sek = asin(2*P/(a*c)) * (180/PI) * 3600;
				if (b*b>(a*a+c*c)){
 	    		z = 1;
 	    	}
		}
		
	    min = sek/60;
	    sek = sek - 60*min;
	    step = min/60;
	    min = min - 60*step;
	    
	    if (z == 1)
	    {
	    	step = 179 - step;
	    	min = 59 - min;
	    	sek = 60 - sek -1;
	    	
	    }
     	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", step, min, sek);

 }
 
 if (k == 1) {
  	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", 90, 0, 0);
 }
	
	
	
	return 0;
}

