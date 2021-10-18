#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.1415926

int main() {
	double x1,x2,x3,y1,y2,y3;
	double a,b,c;
	double alfa,beta,gama;
	double P,s;
	double max;
	double x,stepeni,minute,sekunde;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	b=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	c=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	alfa=acos((a*a+b*b-c*c)/(2*a*b));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((b*b+c*c-a*a)/(2*b*c));
	s=(a+b+c)/2;
	P=sqrt(s*(s-a)*(s-b)*(s-c));
	if(P<epsilon)
	printf("Linija");
	if(fabs(a*a-b*b-c*c)<epsilon || fabs(b*b-a*a-c*c)<epsilon || fabs(c*c-a*a-b*b)<epsilon)
	{printf("Pravougli\n");}
	if((a+b>c) && (a+c>b) && (b+c>a)){
	if(fabs(a-b)<epsilon && fabs(a-c)<epsilon)
	printf("Jednakostranicni\n");
	else if(fabs(a-b)<epsilon || fabs(a-c)<epsilon || fabs(a-c)<epsilon)
	printf("Jednakokraki\n");
	else printf("Raznostranicni");
	}
	if(alfa>beta && alfa>gama) max=alfa;
	else if(beta>gama) max=beta;
	else max=gama;
	x=(max*180)/PI;
	stepeni=(int)(x);
	minute=(int)((x-stepeni)*3600)/60;
	sekunde=(int)((x-stepeni)*3600)%60;
	printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",stepeni,minute,sekunde);
	return 0;
}
