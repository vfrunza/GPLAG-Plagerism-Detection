#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 0.0001 /*mjera tacnosti/tolerancije*/
#define EL pow(10,-15)
#define PI 3.141592653

int main()
{

	double x1,x2,x3;
	double y1,y2,y3;
	double a,b,c;
	double E1,E2,E3;
	double m; /* najveca stranica*/
	double alfa, p=180.0/PI, int_A,int_minA,int_secA,fract_A,fract_minA,min_A;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);

	a=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	b=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	c=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	E1=fabs(a-b); /* a=b */
	E2=fabs(a-c); /* a=c */
	E3=fabs(b-c); /* b=c */
	m=(a>b)?((a>c)?a:c):((b>c)?b:c);


	/* Kolinearnost tacka - LINIJA */
	if ((a+c)-b<EL) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}

	/* Dvije jednake stranice - JEDNAKOKRAKI*/
	else if((E1<E && E2>E && E3>E) || (E2<E && E1>E && E3>E) || (E3<E && E1>E && E2>E)) {
		if(fabs(m-c)<E)
			alfa=acos((a*a+b*b-m*m)/(2*a*b))*p;
		else if(fabs(m-a)<E)
			alfa=acos((b*b+c*c-m*m)/(2*b*c))*p;
		else
			alfa=acos((a*a+c*c-m*m)/(2*a*c))*p;

		fract_A=modf(alfa,&int_A);
		min_A=fract_A*60;
		fract_minA=modf(min_A,&int_minA);
		int_secA=60*fract_minA;

		if((int)int_A==90)
			printf("Pravougli\n");

		printf("Jednakokraki\n");
		printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",floor(int_A),floor(int_minA),floor(int_secA));
	}

	/* Sve jednake stranice - JEDNAKOSTRANICNI */
	else if(E1<E && E2<E && E3<E) {
		alfa=acos(1/2.)*p;
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima %g stepeni, 0 minuta i 0 sekundi.",alfa);
	}

	/* Sve razlicite stranice - RAZNOSTRANICNI */
	else if(E1>E && E2>E && E3>E) {
		if(fabs(m-c)<E)
			alfa=acos((a*a+b*b-m*m)/(2*a*b))*p;
		else if(fabs(m-a)<E)
			alfa=acos((b*b+c*c-m*m)/(2*b*c))*p;
		else
			alfa=acos((a*a+c*c-m*m)/(2*a*c))*p;

		fract_A=modf(alfa,&int_A);
		min_A=fract_A*60;
		fract_minA=modf(min_A,&int_minA);
		int_secA=60*fract_minA;

		if((int)int_A==90)
			printf("Pravougli\n");

		printf("Raznostranicni\n");
		printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",floor(int_A),floor(int_minA),floor(int_secA));
	}

	return 0;
}
