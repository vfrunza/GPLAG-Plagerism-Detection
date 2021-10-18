#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265

int main() {
	double x1, y1, x2, y2, x3, y3, a, b, c, P;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	P=(1./2)*(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
	
	if(fabs(P)<EPSILON) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
	else if (fabs(a-b)<EPSILON && fabs(b-c)<EPSILON) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}
	else if (fabs(c*c-a*a-b*b)<EPSILON || fabs(b*b-a*a-c*c)<EPSILON || fabs(a*a-b*b-c*c)<EPSILON) {
		printf("Pravougli\n");
		if(fabs(a-b)<EPSILON || fabs(b-c)<EPSILON || fabs(c-a)<EPSILON) {
			printf("Jednakokraki\n");
		}
		else {
			printf("Raznostranicni\n");
		}
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	}
	else {
		double alfa, beta, gama, max, step, mint, sek;
		if (fabs(a-b)<EPSILON || fabs(b-c)<EPSILON || fabs(a-c)<EPSILON) {
			printf("Jednakokraki\n");
		}
		else {
			printf("Raznostranicni\n");
		}
		alfa=acos((b*b+c*c-a*a)/(2*b*c))*180/PI;
		beta=acos((c*c+a*a-b*b)/(2*c*a))*180/PI;
		gama=acos((a*a+b*b-c*c)/(2*a*b))*180/PI;
		max=alfa;
		if (beta>max) {
			max=beta;
		}
		if (gama>max) {
			max=gama;
		}
		step=(int)max;
		max-=step;
		max*=60;
		mint=(int)max;
		max-=mint;
		max*=60;
		sek=floor(max);
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", step, mint, sek);
	}
	
	return 0;
}