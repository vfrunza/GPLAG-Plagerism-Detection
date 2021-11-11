#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define e 0.0001
#define pi 4*atan(1)
int main()
{

	double x1, x2, x3, y1, y2, y3, najveci;
	int stepeni, minute, sekunde;
	double a, b, c, ugao1, ugao2, ugao3;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1); 

	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);

	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);


	a = sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
	b = sqrt( pow(x1-x3,2) + pow(y1-y3,2) );
	c = sqrt( pow(x2-x3,2) + pow(y2-y3,2) );

	ugao1 = acos((a*a + b*b - c*c)/(2*a*b) );
	ugao2 = acos((c*c + a*a - b*b)/(2*c*a) );
	ugao3 = acos((b*b + c*c - a*a)/(2*b*c) );

	if( fabs(ugao1-acos(0))<e || fabs(ugao2-acos(0))<e || fabs(ugao3-acos(0))<e) {
		printf("Pravougli\n");
	}

	if(fabs(a+b-c)<e || fabs(a+c-b)<e || fabs(b+c-a)<e) {
		printf("Linija\n");
	} else if(fabs(a-b)<e && fabs(a-c)<e) {
		printf("Jednakostranicni\n");
	} else if(fabs(a-b)<e && fabs(a-c)>e || fabs(a-c)<e && fabs(a-b)>e || fabs(b-c)<e && fabs(b-a)>e) {
		printf("Jednakokraki\n");
	} else if(fabs(a-b)>e && fabs(a-c)>e) {
		printf("Raznostranicni\n");
	}

	najveci=ugao1;
	if( (ugao1-ugao2)>e && (ugao1-ugao3)>e) {
		najveci=ugao1;
	}
	if( (ugao2-ugao1)>e && (ugao2-ugao3)>e) {
		najveci=ugao2;
	}
	if( (ugao3-ugao2)>e && (ugao3-ugao1)>e) {
		najveci=ugao3;
	}

	najveci = (najveci*180)/(pi); /* pretvaramo najveci ugao iz radijana u stepene */

	stepeni = najveci;
	minute = (najveci - stepeni)*60;
	sekunde = ( (najveci - stepeni)*60 - minute)*60 + 0.4; /* +0.4 zbog preciznijeg ispisa sekundi*/
	if(sekunde==60) {
		sekunde=0;
		minute++;
	}
	if(minute==60) {
		minute=0;
		stepeni++;
	}
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	return 0;
}
