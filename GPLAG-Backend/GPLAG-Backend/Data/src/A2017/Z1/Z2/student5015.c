#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define EPSILON 0.0001
int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, a_b, temp, A, B, C;
	int T=0, Ust, Um, Us;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	a=sqrt(fabs((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	b=sqrt(fabs((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)));
	c=sqrt(fabs((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)));
	if ((a>c||fabs(a-c)<EPSILON)&&(a>b||fabs(a-b)<EPSILON)) {
		temp=c;
		c=a;
		a=temp;
	}
	if ((b>a||fabs(a-b)<EPSILON)&&((b>c)||fabs(b-c)<EPSILON)) {
		temp=c;
		c=b;
		b=temp;
	}
	a_b=sqrt(a*a+b*b);
	if (((a+b)<c)||fabs((a+b)-c)<EPSILON) {
		printf ("Linija\n");
	}
	else if ((fabs(a-b)<EPSILON) && (fabs(a-c)<EPSILON)) {
		printf ("Jednakostranicni\n");
	}
	else if (fabs(a_b-c)<EPSILON) {
		printf ("Pravougli\n");
		T=1;
		if ((fabs(a-b)<EPSILON) && (fabs(a-c)>EPSILON) || (fabs(a-c)<EPSILON) && (fabs(a-b)>EPSILON) || (fabs(b-c)<EPSILON) && (fabs(a-b)>EPSILON)) {
			printf ("Jednakokraki\n");
		}
		if ((fabs(a-b)>EPSILON) && (fabs(a-c)>EPSILON) && (fabs(b-c)>EPSILON)) {
			printf ("Raznostranicni\n");
		}
	}
	else if ((fabs(a-b)>EPSILON) && (fabs(a-c)>EPSILON) && (fabs(b-c)>EPSILON)) {
		printf ("Raznostranicni\n");
	}
	else if ((fabs(a-b)<EPSILON) && (fabs(a-c)>EPSILON) || (fabs(a-c)<EPSILON) && (fabs(a-b)>EPSILON) || (fabs(b-c)<EPSILON) && (fabs(a-b)>EPSILON)) {
		printf ("Jednakokraki\n");
	}
	if (T==1) {
		printf ("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	}
	else {
		C=acos((a*a+b*b-c*c)/(a*b*2.))*180/PI;
		Ust=(int)(C);
		Um=(int)((C-Ust)*60);
		Us=(int)((((C-Ust)*60)-Um)*60); 
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", Ust, Um, Us);
	}
	return 0;
}
