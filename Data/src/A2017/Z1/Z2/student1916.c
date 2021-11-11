#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.141592653589

int main() {
	/* Unos koordinata*/
	double x1, y1, x2, y2, x3, y3, u, s;
	s=180./PI;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	/* Izracunati stranice */
	double a, b, c;
	a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	c=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	/* Ispisati ako nije trougao */
	if(fabs(a-b-c)<E || fabs(b-c-a)<E || fabs(c-a-b)<E) printf("Linija\n");
	/* Ispisati vrstu trougla */
	else if(fabs(a-b)<E && fabs(b-c)<E) printf("Jednakostranicni\n");
	else if((fabs(a-b)<E && fabs(a-c)>E) || (fabs(b-a)<E && fabs(a-c)>E) || (fabs(c-a)<E && fabs(c-b)>E)){
		if(fabs(a*a-2*b*b)<E || fabs(b*b-2*a*a)<E || fabs(c*c-2*b*b)<E) printf("Pravougli\n");
		printf("Jednakokraki\n");
	}
	else{
		if(fabs(a*a-b*b*-c*c)<E || fabs(b*b-a*a-c*c)<E || fabs(c*c-a*a-b*b)<E) printf("Pravougli\n");
		printf("Raznostranicni\n");
	}
	/* Racunanje ugla pomocu kosinusne teoreme */
	if(a>=b && a>=c ) u=acos((b*b+c*c-a*a)/(2*b*c))*s;
	else if(b>=a && b>=c) u=acos((a*a+c*c-b*b)/(2*a*c))*s;
	else u=acos((a*a+b*b-c*c)/(2*a*b))*s;
	double su, mu, secu; /* Stepeni, minute i sekunde ugla */
	su=(int)u;
	mu=(u-(int)u)*60;
	secu=(mu-(int)mu)*60;
	mu=(int)mu;
	secu=(int)secu;
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", su, mu, secu);
	return 0;
}
