#include <stdio.h>
#include <math.h>
#define EPS 0.0001
#define PI 3.14159
int main()
{
	double x1,y1,x2,y2,x3,y3;
	double najveca;
	double ugao;
	int st,min,sek;
	double mmin;
	double a,b,c;
	double rad;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3, &y3);

	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));


	if ((fabs(x1*(y2-y3)+x2*(y3-y2)+x3*(y1-y2))/2)<=EPS) {
		printf("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
		return 0;
	}
	if(fabs(a-b)>EPS && fabs(b-c)>EPS) {
		if (fabs(a-b)>EPS && fabs(b-c)>EPS) {
			if (fabs(c*c-a*a-b*b)<EPS || fabs(a*a-b*b-c*c)<EPS || fabs(b*b-a*a-c*c)<EPS) {
				printf("Pravougli\n");
				if (a>b && a>c)
					najveca=a;
				else if (b>c && b>a)
					najveca=b;
				else
					najveca=c;
			}
		}
	}
	if (fabs(a-b)>EPS && fabs(b-c)>EPS) {

		printf("Raznostranicni\n");
		if (a>b && a>c)
			najveca=a;
		else if (b>c && b>a)
			najveca=b;
		else
			najveca=c;
	} else if (fabs(a-b)<EPS && fabs(a-c)<EPS) {
		printf("Jednakostranicni\n");
		if (a>=b && a>=c)
			najveca=a;
		else if (b>=c && b>=a)
			najveca=b;
		else
			najveca=c;

	} else if ((fabs(a-b)<EPS || fabs(a-c)<EPS || fabs(b-c)>EPS) && (fabs(a-b)>EPS || fabs(a-c)>EPS || fabs(b-c)>EPS)) {
			printf("Jednakokraki\n");
			if (a>b && a>c)
				najveca=a;
			else if (b>c && b>a)
				najveca=b;
			else
				najveca=c;
		}

	
	if ((najveca-a)<EPS)
		ugao=acos((b*b+c*c-a*a)/(2*b*c));
	else if ((najveca-b)<EPS)
		ugao=acos((a*a+c*c-b*b)/(2*a*c));
	else if ((najveca-c)<EPS)
		ugao=acos((a*a+b*b-c*c)/(2*a*b));


	rad=180/PI;
	ugao=ugao*rad;
	st=(int)ugao;
	mmin=(ugao-st)*60;
	min=(int)mmin;
	sek=(mmin-min)*60;
	
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",st,min,sek);
	return 0;


}