#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define EPSILON 0.0001
int main() {
	double x1, y1, x2, y2, x3, y3, a, b, c, A, B, C, R, R1;
	int step, min, sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	c=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	a=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	b=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	
	A=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c)) * 180/PI;
	B=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c)) * 180/PI;
	C=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b)) * 180/PI;

	if (A>B && A>C){R=A;} 
	else if (B>A && B>C){R=B;}
	else if(C>A && C>B) {R=C;}
	
	R1 = R;
	
	step= (int)R;
	R-=step;
	R*=60;
	min= (int)R;
	R-=min;
	R*=60;
	sec=(int)R;
	
	R = R1;
	
	if ((fabs(A)<=EPSILON)||(fabs(B)<=EPSILON)||(fabs(C)<=EPSILON))
	printf("Linija\n");
	else if (fabs(R-90)<=EPSILON){
	printf("Pravougli\n");
		if (((fabs (A-B)<=EPSILON)&&(fabs(A-C)>EPSILON)) || ((fabs(A-C)<=EPSILON)&&(fabs(A-B)>EPSILON)) || ((fabs(B-C)<=EPSILON)&&(fabs(B-A)>EPSILON)))
	printf("Jednakokraki\n");}
	else if (fabs(R-60)<=EPSILON)
	printf("Jednakostranicni\n");
	else if (((fabs(A-B)<=EPSILON)&& (fabs(A-C)>EPSILON)) || ((fabs(A-C)<=EPSILON) && (fabs(A-B)>EPSILON)) || ((fabs(B-C)<=EPSILON)&&(fabs(B-A)>EPSILON)))
	printf("Jednakokraki\n");
	if (fabs(A-B)>EPSILON && (fabs(A-C)>EPSILON) && (fabs (B-C)>EPSILON))
	printf("Raznostranicni\n");
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sec);
	return 0;
}
