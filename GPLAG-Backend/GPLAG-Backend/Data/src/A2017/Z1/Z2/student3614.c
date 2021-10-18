#include <stdio.h>
#include <math.h>
#define PI 3.141592
#define EPSILON 0.0001


int main() {
	int stepen,minuta,sekunda;
	double x1,y1,x2,y2,x3,y3,a,b,c,alfa,beta,gama,maxugao,dsec,dmin;
	printf("Unesite koordinate tacke t1: ");
	scanf ("%lf%lf", &x1,&y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf%lf",&x2,&y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf%lf",&x3,&y3);
	
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		
	alfa = (acos( (b*b+c*c-a*a) / (2*b*c) ))*180/PI; 
    beta = (acos( (c*c+a*a-b*b) / (2*c*a) ))*180/PI; 
    gama = (acos( (a*a+b*b-c*c) / (2*a*b) ))*180/PI;
  
        if (alfa>beta)	{ 
    	if (alfa>gama) {
    		maxugao=alfa;
    	}
    	else {
    		maxugao=gama;
    	}
    }
    else {
    	if (beta>gama) {
    		maxugao=beta;
    	}
    	else {
    		maxugao=gama;
    	}
    }
   		
   		stepen = (int)maxugao;
   	    dmin=(maxugao-(int)maxugao)*60;
   	    minuta=(int)dmin;
   	   	dsec=(dmin-(int)minuta)*60;
   	   	sekunda=(int)dsec;
   	   	
   	   if (fabs(a-(c+b))<EPSILON || fabs(b-(c+a))<EPSILON || fabs(c-(a+b))<EPSILON)
	
	{ printf ("Linija"); } 
	else{
	
		if ( fabs (stepen-90)<EPSILON) { 
    		printf ("Pravougli"); 
    		if (fabs(a-b)<EPSILON || fabs(b-c)<EPSILON || fabs(a-c)<EPSILON ) {
    			printf ("\nJednakokraki"); 
    		}
    		else {
    			printf ("\nRaznostranicni");
    		} 
    		
    	}
    		else {
    			if (fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON) {
    				printf ("Raznostranicni");
    			} else {
    				if (fabs(a-b)<EPSILON && fabs(b-c)<EPSILON && fabs(a-c)<EPSILON) {
    					printf ("Jednakostranicni");
    				}
    				else {
    					printf ("Jednakokraki");
    				}
    			}
    			
    			
    		
	}
	
	}
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
		
	return 0;
}
