#include <stdio.h>
#include <math.h>

#define E .0001
#define PI 3.1415926535

/* define max */
double max(double x, double y) {
	return (x > y ? x:y);
}

/* equal */
int equal(double a, double b) {
	return (fabs(a-b) < E);
}

/* square the num */
double sqr(double x) { return (x*x); }

/* distance between points without sqrt for precision */
double dist(double x_1, double y_1, double x_2, double y_2) {
	return (sqr(x_2 - x_1)+sqr(y_2 - y_1));
}

/* if square */
int _square(double a, double b, double c) {
	return (fabs(a-(b+c)) < E || fabs(b-(a+c)) < E || fabs(c-(a+b)) < E);
}

/* angle between pages */
double angle(double a, double b, double c) {
	return (fabs(acos((a+b-c)/(2*sqrt(a*b)))*180.0/PI));
}

int main() {
	/* initial */
	double ang = .0, P, x1, y1, x2, y2, x3, y3, d_AB, d_AC, d_BC;
	int h, m, s;
	
	printf("Unesite koordinate tacke t1: "); scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: "); scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: "); scanf("%lf %lf", &x3, &y3);
	
	/* checking */
	P = fabs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;
	d_AB = dist(x1, y1, x2, y2);
	d_AC = dist(x1, y1, x3, y3);
	d_BC = dist(x2, y2, x3, y3);
	ang =  max(max(angle(d_AB,d_AC,d_BC),angle(d_BC,d_AB,d_AC)),angle(d_BC,d_AC,d_AB));
	
	if(P < E) {
		printf("Linija\n");
		ang = 180.0;
	}
	else {
		if(equal(d_AB, d_AC) && equal(d_AB, d_BC) && equal(d_BC, d_AC)) {
			printf("Jednakostranicni\n"); 
			ang = 60.0;
		}
		else if(equal(d_AB, d_AC) || equal(d_AB, d_BC) || equal(d_AC, d_BC)) {
			if(_square(d_AB, d_AC, d_BC)) {
				printf("Pravougli\nJednakokraki\n");
				ang = 90.0;
			}
			else {
				printf("Jednakokraki\n");
			}
		}
		else if(_square(d_AB, d_AC, d_BC)) {
			printf("Pravougli\n");
			ang = 90.0;
		}
	}
	
	if(!equal(d_AB, d_AC) && !equal(d_AB, d_BC) && !equal(d_BC, d_AC)) 
		printf("Raznostranicni\n");
	
	/* angle convert */
	h = trunc(ang);
	m = trunc((ang - h)*60);
	s = trunc((ang - h - m/60)*3600);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", h, m, s%60);
	return 0;
}