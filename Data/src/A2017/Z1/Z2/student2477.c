#include <stdio.h>
#include <math.h>
#define E 0.0001
#define pi 3.14159265

int main()
{
	double o, u, q, x1, y1, x2, y2, x3, y3, a=0, b=0, c=0, ugao1, ugao2, ugao3, p, s, sin1, sin2, sin3, stepen1, stepen2, stepen3, minuta1= 0.0, minuta2=0.0, minuta3=0.0, sekunda1=0.0, sekunda2=0.0, sekunda3=0.0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	a = sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
	b = sqrt( pow(x3-x1,2) + pow(y3-y1,2) );
	c = sqrt( pow(x2-x3,2) + pow(y2-y3,2) );

	s = (a+b+c)/2;
	p = sqrt(s*(s-a)*(s-b)*(s-c));
	sin1 = (2*p)/(a*b);
	sin2 = (2*p)/(b*c);
	sin3 = (2*p)/(a*c);

	ugao1 = asin(sin1)* 180/pi;
	ugao2 = asin(sin2)* 180/pi;
	ugao3 = asin(sin3)* 180/pi;

	o = ugao1;
	u = ugao2;
	q = ugao3;

	stepen1 = (int) ugao1;
	ugao1 -= stepen1;
	ugao1 *= 60;
	minuta1 = (int)ugao1;
	ugao1-=minuta1;
	ugao1 *=60;
	sekunda1 = (int) ugao1;

	while (minuta1 > 60) {
		minuta1 -=60;
		stepen1++;
	}
	while (sekunda1 > 60) {
		sekunda1 -= 60;
		minuta1++;
	}

	stepen2 = (int) ugao2;
	ugao2 -= stepen2;
	ugao2 *= 60;
	minuta2 = (int)ugao2;
	ugao2-=minuta2;
	ugao2 *=60;
	sekunda2 = (int) ugao2;

	while (minuta2 > 60) {
		minuta2 -=60;
		stepen2++;
	}
	while (sekunda1 > 60) {
		sekunda1 -= 60;
		minuta1++;
	}

	stepen3 = (int) ugao3;
	ugao3 -= stepen3;
	ugao3 *= 60;
	minuta3 = (int)ugao3;
	ugao3-=minuta3;
	ugao3 *=60;
	sekunda3 = (int) ugao3;

	while (minuta3 > 60) {
		minuta2-=60;
		stepen2++;
	}
	while (sekunda3 > 60) {
		sekunda3 -= 60;
		minuta3++;
	}

	if ( (stepen1 ==90) && (stepen2==90) && (stepen3==90) )
		printf("Pravougli\n");

	if ( o-u<E || o-p<E || u-p<E)
		printf("Jednakokraki\n");

	if ( (stepen1 ==60) && (stepen2==60) && (stepen3==60) ) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen1, minuta1, sekunda1);
	} else if ( stepen1 != stepen2 && stepen2 != stepen3 )
		printf("Raznostranicni\n");

	if (stepen1>stepen2 && stepen1>stepen3)
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen1, minuta1, sekunda1);
	else if (stepen2>stepen1 && stepen2>stepen3)
		printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen2, minuta2, sekunda2);
	else if (stepen3>stepen1 && stepen3>stepen2)
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen3, minuta3, sekunda3);
	if ((stepen1==0 && minuta1==0 && sekunda1==0) )
		printf ("Linija\n");

	return 0;

}