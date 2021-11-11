#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159

int main() {
	double x1, y1, x2, y2, x3, y3, P, a, b, c, alfa, beta, gama, najveci, min, sec;
	int stepeni, minute, sekunde;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: "); 
	scanf ("%lf %lf", &x3, &y3);
	P=0.5*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	if (P<EPSILON) { printf ("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
	else{
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	if (alfa>gama && alfa>beta) { najveci=alfa; }
	else if (beta>alfa && beta>gama) { najveci=beta; }
	else { najveci=gama; }
	najveci=(najveci*180)/PI; 
	min=(najveci-(int)najveci)*60;
	sec=(min-(int)min)*60; 
	stepeni=(int) najveci; 
	minute=(int) min;
	sekunde=(int) sec;
	if (fabs(a-sqrt(b*b+c*c))<EPSILON || fabs(b-sqrt(a*a+c*c))<EPSILON || fabs(c-sqrt(a*a+b*b))<EPSILON) { printf ("Pravougli\n"); }
 	if (fabs(a-b)<EPSILON && fabs(a-c)<EPSILON) { printf ("Jednakostranicni\n"); }
 	else if ((fabs(a-b)<EPSILON && a!=c) || (fabs(a-c)<EPSILON && a!=b) || (fabs(b-c)<EPSILON && b!=a) || (fabs(b-a)<EPSILON && b!=c) || (fabs(c-a)<EPSILON && c!=b) || (fabs(c-b)<EPSILON && c!=a)) { printf ("Jednakokraki\n"); }
    if (fabs(a-b)>EPSILON && fabs(a-c)>EPSILON && fabs(c-b)>EPSILON) { printf ("Raznostranicni\n"); }
	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",  stepeni, minute, sekunde);}
	return 0;
}
