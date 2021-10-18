#include <stdio.h>
#include <math.h>
#define pi 3.141592
#define e 0.000001

int main() {
	
	double a1, b1, a2, b2, a3, b3, a, b, c, s, p;
	int A, B, C, stepen, minuta, sekunda;
	printf("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &a1, &b1);
	printf("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &a2, &b2);
	printf("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &a3, &b3);
	
	a=sqrt(pow(a1-a2,2)+pow(b1-b2,2));
	b=sqrt(pow(a2-a3,2)+pow(b2-b3,2));
	c=sqrt(pow(a1-a3,2)+pow(b1-b3,2));
	
	A=acos((b*b+c*c-a*a)/2*b*c)*(180/pi);
	B=acos((a*a+c*c-b*b)/2*a*c)*(180/pi);
	C=acos((b*b+a*a-c*c)/2*b*a)*(180/pi);
	
	s=(a+b+c)/2;
	p=sqrt(s*(s-a)*(s-b)*(s-c));
	
	if(fabs(p)<e)
	{
		printf("Linija");
	}
	
	else if(fabs(a-b)<e && fabs(a-c)<e && fabs(c-b)<e){
		
		
		printf("Jednakostranicni");
	}
	
	
	
	else if(fabs(a-b)>e && fabs(a-c)>e && fabs(c-b)>e){
		
		if( fabs((a*a)-(b*b)-(c*c))<e || fabs((b*b)-(a*a)-(c*c))<e || fabs((c*c)-(b*b)-(a*a))<e )
		{
		printf("Pravougli\n");
		}
		printf("Raznostranicni");
	}
	
	
	else if( fabs(a-b)<e || fabs(b-c)<e || fabs(a-c)<e){
		
		if( fabs((a*a)-(b*b)-(c*c))<e || fabs((b*b)-(a*a)-(c*c))<e || fabs((c*c)-(b*b)-(a*a))<e )
		{
		printf("Pravougli\n");
		}
		
		printf("Jednakokraki");
	}	
	
	if(a>=b && a>=c){
		stepen=A;
		stepen=stepen*90;
		minuta=stepen;
		minuta=minuta*90;
		
	}
	
	return 0;
}