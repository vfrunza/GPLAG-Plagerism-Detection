#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	
	double t1x, t1y, t2x, t2y, t3x, t3y;
	double strana1, strana2, strana3;
	double a, b, c, max;
	int ukupnosekundi, sec, min, step;
	

	printf("Unesite koordinate tacke t1: ");	
	scanf("%lf %lf", &t1x, &t1y);
	
	printf("Unesite koordinate tacke t2: ");	
	scanf(" %lf %lf", &t2x, &t2y);
	
	printf("Unesite koordinate tacke t3: ");	
	scanf(" %lf %lf", &t3x, &t3y);
	


	strana1 = sqrt(( (t2x-t1x) * (t2x-t1x) ) + (t2y-t1y) * (t2y-t1y)) ;
	strana2 = sqrt(( (t3x-t2x) * (t3x-t2x) ) + (t3y-t2y) * (t3y-t2y)) ;
	strana3 = sqrt(( (t3x-t1x) * (t3x-t1x) ) + (t3y-t1y) * (t3y-t1y)) ;

  
   

	a=acos((strana2*strana2+strana3*strana3-strana1*strana1)/(2*strana2*strana3));
	b=acos((strana3*strana3+strana1*strana1-strana2*strana2)/(2*strana3*strana1));
	c=acos((strana1*strana1+strana2*strana2-strana3*strana3)/(2*strana1*strana2));
    
    
    if (a>b && a>c) max=a;
    else if (b>a && b>c) max=b;
    else max=c;
    
    ukupnosekundi = (max*360*60*60 / (2*M_PI));
    sec = (ukupnosekundi % 60);
    min = (ukupnosekundi/60) % 60;
    step = ukupnosekundi / (60 * 60);
   

    if (step == 0 || step==180) printf ("Linija\n");
    else
    {
    if (step == 90) printf("Pravougli\n");    
    
    if (fabs(strana1 - strana2) <= EPSILON && fabs(strana2 - strana3) <= EPSILON )
    printf("Jednakostranicni\n");
    
    else if (fabs(strana1 - strana2) < EPSILON || fabs(strana1 - strana3) < EPSILON || fabs(strana2 - strana3) < EPSILON) 
    printf("Jednakokraki\n");
    
    else 
    printf("Raznostranicni\n");
    }
    
    
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sec);
    
    
    
    
    
    
    
	return 0;
}
