#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14159265359

int main()
{
	double x1, x2, x3, y1, y2, y3, a, b, c, alfa, beta, gama, mina, minb, ming;
	int  alfa1, beta1, gama1, mina1, minb2, ming3, seca, secb, secg;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));

	alfa=(acos((b*b+c*c-a*a)/(2*b*c))*180/PI);
	beta=(acos((c*c+a*a-b*b)/(2*c*a))*180/PI);
	gama=(acos((a*a+b*b-c*c)/(2*a*b))*180/PI);

	alfa1=(alfa/1)+epsilon;
	beta1=(beta/1)+epsilon;
	gama1=(gama/1)+epsilon;

	mina=(alfa-alfa1)*60;
	minb=(beta-beta1)*60;
	ming=(gama-gama1)*60;

	mina1=mina/1;
	minb2=minb/1;
	ming3=ming/1;

	seca=(mina-mina1)*60;
	secb=(minb-minb2)*60;
	secg=(ming-ming3)*60;


	if((alfa1==90) || (beta1==90) || (gama1==90))
		printf("Pravougli\n");

	if((alfa1==180) || (beta1==180) || (gama1==180)) {
		printf("Linija\n");

	} else if(fabs(a-b)<=epsilon && fabs (b-c)<=epsilon && (c-a)<=epsilon) {
		printf("Jednakostranicni");
	} else if (fabs(a-b)<=epsilon || fabs(c-a)<=epsilon) {
		printf("Jednakokraki");
	}
	if (fabs(a-b)>=epsilon &&fabs(b-c)>=epsilon) {
		printf("Raznostranicni");
	}
	if ((alfa>beta) && (alfa>gama)) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", alfa1, mina1, seca);
	} else if ((beta>alfa) && (beta>gama)) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", beta1, minb2, secb);
	} else if ((gama>beta) && (gama>alfa)) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", gama1, ming3, secg);
	}
	return 0;
}