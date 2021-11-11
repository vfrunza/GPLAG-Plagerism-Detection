#include <stdio.h>
#include <math.h>
#define E 0.0001
#define pi 3.1415926

int main() {
	double x1, y1, x2, y2, x3, y3, a, b, c,
		   arad, brad, grad, alfa, beta, gama;
	int deg, min, sec;
	printf ("Unesite koordinate tacke t1: "); 
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	

	arad=acos((a*a-b*b-c*c)/(-2*b*c));
	brad=acos((b*b-c*c-a*a)/(-2*c*a));
	grad=acos((c*c-a*a-b*b)/(-2*a*b));
	
	alfa=arad*(180/pi);
	beta=brad*(180/pi);
	gama=grad*(180/pi);
	

	if (fabs(180-alfa)<=E || fabs(180-beta)<=E || fabs(180-gama)<=E) printf ("Linija");
	
	else if (fabs(90-alfa)<=E || fabs(90-beta)<=E || fabs(90-gama)<=E) {
		printf ("Pravougli");
		if (fabs(a-b)<=E || fabs(a-c)<=E || fabs(b-c)<=E) printf ("\nJednakokraki");
		else if (a!=b && a!=c && b!=c) printf ("\nRaznostranicni"); }

	else if (fabs(a-b)<=E && fabs(a-c)<=E) printf ("Jednakostranicni");
	else if (fabs(a-b)<=E || fabs(a-c)<=E || fabs(b-c)<=E) printf ("Jednakokraki");
	else if (a!=b && a!=c && b!=c) printf ("Raznostranicni");
	
	if (alfa>beta && alfa>gama) {
		deg = (int) alfa;
		min = (int) ((alfa-deg)*60);
		sec = (int) ((((alfa-deg)*60)-min)*60);
		printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", deg, min, sec);
	}
	
	else if (beta>alfa && beta>gama) {
		deg = (int) beta;
		min = (int) ((beta-deg)*60);
		sec = (int) ((((beta-deg)*60)-min)*60);
		printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", deg, min, sec);
	}

	else if (gama>alfa && gama>beta) {
		deg = (int) gama;
		min = (int) ((gama-deg)*60);
		sec = (int) ((((gama-deg)*60)-min)*60);
		printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", deg, min, sec);
	}
	
	return 0;
}
