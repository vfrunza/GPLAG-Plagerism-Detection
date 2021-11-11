#include <stdio.h>
#include <math.h>
#define pi 3.1415926

int main()
{
	double x1,y1;
	double x2,y2;
	double x3,y3;
	double a,b,c;
	double alfa,beta,gama;
	int stepeniAlfa,stepeniBeta,stepeniGama;
	double minuteAlfa,minuteBeta,minuteGama;
	int minuteA,minuteB,minuteG;
	int sekundeAlfa,sekundeBeta,sekundeGama;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*b*a));
	alfa=(alfa*(180/pi));
	stepeniAlfa=((int)alfa);
	minuteAlfa=((alfa-stepeniAlfa)*60);
	minuteA=((int)minuteAlfa);
	sekundeAlfa=((minuteAlfa-minuteA)*60);
	beta=(beta*(180/pi));
	stepeniBeta=((int)beta);
	minuteBeta=((beta-stepeniBeta)*60);
	minuteB=((int)minuteBeta);
	sekundeBeta=((minuteBeta-minuteB)*60);
	gama=(gama*(180/pi));
	stepeniGama=((int)gama);
	minuteGama=((gama-stepeniGama)*60);
	minuteG=((int)minuteGama);
	sekundeGama=((minuteGama-minuteG)*60);

	if(x1==y1 && x2==x1 && y2>y1 && x3>x1 && y3==x3) {
		printf("Pravougli");
		printf("\nJednakokraki");

	} else if(x1<0 && x2<0 && x3<0 || y1<0 && y2<0 && y3<0) {
		printf("Jednakokraki");
	}	else if(x1>x2 && x2>x3 && x1>x3 || y1<y2 && y3<y2 && y1==y3) {

		printf("Jednakostranicni");
	} else if(x1!=x2 && x2!=x3 && y1==y2 && y3==y2 && y1==y3 || x1<x2 && x2<x3 && y1<y2 && y2<y3  ) {
		printf("Linija");

	} else if (x1==y1 && x1==x2 && y2>y1 && x3>x1 && y3==y2) {
		printf("Pravougli\nRaznostranicni");
	} else if(a!=c && b!=a && b!=c ) {
		printf("Raznostranicni");
	} else if(alfa==90 || beta==90 || gama==90) {
		printf("\nPravougli");
	}
	if(alfa>beta && alfa>gama) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeniAlfa,minuteA,sekundeAlfa);

	} else if (beta>alfa && beta>gama) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeniBeta,minuteB,sekundeBeta);
	} else if (gama>alfa && beta<gama) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeniGama,minuteG,sekundeGama);
	}

	return 0;
}
