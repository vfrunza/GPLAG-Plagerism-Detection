#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001
#define PI 3.1415926

int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, P=0, alfa, beta, gama, x, y, z;
	double radalfa, radbeta, radgama, stalfa, stbeta, stgama, min1, min2, min3, minuta1, minuta2, minuta3, sek1, sek2, sek3, sekunda1, sekunda2, sekunda3;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	a= sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	b= sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	c= sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	P= (fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))/2;
	x= (pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c);
	y= (pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c);
	z= (pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b);
	radalfa= acos (x);
	radbeta= acos (y);
	radgama= acos (z);
	alfa=(radalfa*180)/PI;
	beta=(radbeta*180)/PI;
	gama=(radgama*180)/PI;
	stalfa=(int) alfa;
	stbeta=(int) beta;
	stgama=(int) gama;
	min1=(alfa-stalfa)*60;
	minuta1=(int) min1;
	min2=(beta-stbeta)*60;
	minuta2=(int) min2;
	min3=(gama-stgama)*60;
	minuta3=(int) min3;
	sek1=(min1-minuta1)*60;
	sekunda1=(int) sek1;
	sek2=(min2-minuta2)*60;
	sekunda2=(int) sek2;
	sek3=(min3-minuta3)*60;
	sekunda3=(int) sek3;
	
	if (stalfa==90 || stbeta==90 || stgama==90) {
		printf ("Pravougli\n");
	} 
	if (fabs(P)<EPSILON) {
		printf ("Linija");
		printf ("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	} else if ((a-b)<EPSILON && (b-c)<EPSILON && (c-a)<EPSILON) {
		printf ("Jednakostranicni");
		printf ("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	} else if (fabs(b-c)<=EPSILON || fabs(a-b)<=EPSILON || fabs(a-c)<=EPSILON)  {
		printf ("Jednakokraki");
		if (alfa>beta && alfa>gama) {
			printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stalfa, minuta1, sekunda1);
		} else if (beta>alfa && beta>gama) {
			printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stbeta, minuta2, sekunda2);
		} else if(gama>alfa && gama>beta) {
			printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stgama, minuta3, sekunda3);
		}
	} else if (a!=b && b!=c) {
		printf ("Raznostranicni");
		if (alfa>beta && alfa>gama) {
			printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stalfa, minuta1, sekunda1);
		} else if (beta>alfa && beta>gama) {
			printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stbeta, minuta2, sekunda2);
		} else if(gama>alfa && gama>beta) {
			printf ("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stgama, minuta3, sekunda3);
		}
	} 
	
	return 0;
}
