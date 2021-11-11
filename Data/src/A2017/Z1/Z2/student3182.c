#include <stdio.h>
#define EPSILON 0.0001
#define PI 3.14159
#include <math.h>

int main() {
    
	double a, b, c, P, x1, x2, x3, y1, y2, y3,alfa, beta, gama, min1, min2, min3 ;
	int alfa1, beta1, gama1, min11, min22, min33, sek1, sek2, sek3;
		
    printf ("Unesite koordinate tacke t1: "); scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: "); scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: "); scanf ("%lf %lf", &x3, &y3);
	
	a = sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) );
	b = sqrt( (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2) );
	c = sqrt( (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3) );
	
	P = (0.5)*fabs( x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2) );
	
	if (P==0) {
	printf ("Linija\n");
	} 
    else
	{
	if (  (fabs(a*a-b*b-c*c)<EPSILON) || (fabs(b*b-c*c-a*a)<EPSILON) || (fabs(c*c-a*a-b*b)<EPSILON)  ) {
    printf ("Pravougli\n");  }	
	
    if ( (fabs(a-b)<EPSILON) && (fabs(b-c)<EPSILON )) {
    printf ("Jednakostranicni\n"); }
    
    if (     ((fabs(a-c)<EPSILON) && (fabs(b-c)>EPSILON) && (fabs(b-a)>EPSILON)) || ((fabs(a-b)<EPSILON) && (fabs(b-c)>EPSILON) && (fabs(a-c)>EPSILON)) || ((fabs(b-c)<EPSILON) && (fabs(a-c)>EPSILON) && (fabs(b-a)>EPSILON)) )  { 
    printf ("Jednakokraki\n");  } 

    if ( (fabs(a-b)>=EPSILON) && (fabs(b-c)>=EPSILON) ) {
    printf ("Raznostranicni\n"); }
	} 
	
	alfa=(acos((c*c+a*a-b*b)/(2*c*a))*180/PI);
	beta=(acos((a*a+b*b-c*c)/(2*a*b))*180/PI);
	gama=(acos((b*b+c*c-a*a)/(2*b*c))*180/PI);
	
	alfa1=alfa/1;
	beta1=beta/1;
	gama1=gama/1;
	
	min1=(alfa-alfa1)*60;
	min2=(beta-beta1)*60;
	min3=(gama-gama1)*60;
	
	min11=min1/1;
	min22=min2/1;
	min33=min3/1;
	
	sek1=(min1-min11)*60;
	sek2=(min2-min22)*60;
	sek3=(min3-min33)*60;
	
	if ((alfa>beta) && (alfa>gama))
	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", alfa1, min11, sek1);
	
	if ((beta>alfa) && (beta>gama))
	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", beta1, min22, sek2);
	
	if ((gama>alfa) && (gama>beta))
	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", gama1, min33, sek3);

    return 0;
}

