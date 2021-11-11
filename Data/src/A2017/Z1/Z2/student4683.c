#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define EPSILON 0.0001

int main() {
	float x1, x2, x3, y1, y2, y3, P, d1, d2, d3, a, b, c, ugao, min, step, sek, r, m, najduzastr;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%f %f", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%f %f", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%f %f", &x3, &y3);
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	P=(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2);
	d1=c*c-a*a-b*b;
	d2=a*a-b*b-c*c;
	d3=b*b-c*c-a*a;
	
	if(fabs(P)<EPSILON) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
		return 1;
	}
	if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON) {
			if(fabs(d1)<EPSILON || fabs(d2)<EPSILON || fabs(d3)<EPSILON) {
				printf("Pravougli\n");
				if(a>b && a>c) najduzastr=a;
				else if (c>b && c>a) najduzastr=c;
				else najduzastr=b; }
				printf("Raznostranicni\n");
				if(a>b && a>c) najduzastr=a;
				else if(b>a && b>c) najduzastr=b;
				else najduzastr=c; }
				
	else if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 1;
	}
	else { if(fabs(d1)<EPSILON || fabs(d2)<EPSILON || fabs(d3)<EPSILON) {
		printf("Pravougli\n");
		if (a>b && a>c) najduzastr=a;
		else if(c>b && c>a) najduzastr=c;
		else najduzastr=b;
	}
	if ((fabs(a-b)<EPSILON || fabs(a-c)<EPSILON || fabs(b-c)<EPSILON) && (fabs(a-b)>EPSILON || fabs(a-c)>EPSILON || fabs(b-c)>EPSILON)) {
		printf("Jednakokraki\n");
		if(fabs(a-b)<EPSILON && a>c) najduzastr=a;
		else if(fabs(a-b)<EPSILON && a<c) najduzastr=c;
		if(fabs(a-c)<EPSILON && b>c) najduzastr=b;
		else if (fabs(a-c)<EPSILON && b<c) najduzastr=c;
		if (fabs(b-c)<EPSILON && a>c) najduzastr=a;
		else if(fabs(b-c)<EPSILON && a<c) najduzastr=c;
		}
		}
	if(fabs(najduzastr-a)<EPSILON) 
	ugao=acos((b*b+c*c-a*a)/(2*b*c));
	else if (fabs(najduzastr-b)<EPSILON)
	ugao=acos((a*a+c*c-b*b)/(2*a*c));
	else ugao=acos((a*a+b*b-c*c)/(2*a*b));
	ugao*=(180/PI);
	step=(int)ugao;
	r=(ugao-step)*60;
	min=(int)r;
	m=(r-min)*60;
	sek=(int)m;
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", step, min, sek);
	return 0;
	} 

	
