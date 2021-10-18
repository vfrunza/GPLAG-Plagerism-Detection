#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	double x1,x2,x3,y1,y2,y3;
	double a,b,c;
	double A,B,C,stepeni,minute,sekunde;
	double cosA,cosB,cosC,max,min;
	double PI=atan(1)*4;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	
	cosA=(b*b+c*c-a*a)/(2*b*c);
	cosB=(c*c+a*a-b*b)/(2*c*a);
	cosC=(a*a+b*b-c*c)/(2*a*b);
	
	A=acos(cosA)*(180./PI);
	B=acos(cosB)*(180./PI);
	C=acos(cosC)*(180./PI);
	
	max=A;
	min=A;
	if(B>max) max=B;
	if(C>max) max=C;
	if(B<min) min=B;
	if(C<min) min=C;
	
	stepeni=(int) max;
	max-=stepeni;
	max*=60;
	minute=(int) max;
	max-=minute;
	max*=60;
	sekunde= floor (max);
	
	
	if (fabs(A)<EPSILON || fabs(B)<EPSILON || fabs(C)<EPSILON) printf("Linija\n");
	else if (fabs(A-60)<EPSILON && fabs(B-60)<EPSILON && fabs (C-60)<EPSILON) printf("Jednakostranicni\n");
	else if (fabs(A-90)<EPSILON || fabs(B-90)<EPSILON || fabs(C-90)<EPSILON){ 
	printf("Pravougli\n");
	if (fabs(A-45)<EPSILON || fabs(B-45)<EPSILON || fabs(C-45)<EPSILON) printf("Jednakokraki\n");
		else printf("Raznostranicni\n");
	}
	else if (fabs(A-B)<EPSILON || fabs(A-C)<EPSILON || fabs(B-C)<EPSILON) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepeni, minute, sekunde);
	
	return 0;
}
