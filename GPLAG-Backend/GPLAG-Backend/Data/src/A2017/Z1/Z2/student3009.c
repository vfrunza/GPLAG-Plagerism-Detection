#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define STEPENI 57.295779513
#define E 0.0001
int main()
{
	double x1,y1,x2,y2,x3,y3,d12,d23,d13,a,b,c,a1,b1,c1;
	int s,min,sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	d12=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d23=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	d13=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	if (fabs((d12+d23)-d13)<E || fabs((d23+d13)-d12)<E || fabs((d12+d13)-d23)<E) {
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	} else {
		if(fabs((d23*d23+d13*d13)-(d12*d12))<E||(fabs((d12*d12+d13*d13)-(d23*d23))<E||fabs((d12*d12+d23*d23)-(d13*d13))<E)) {
			printf("Pravougli\n");}
		if (fabs(d12-d23)>E && fabs(d12-d23)>E && fabs(d12-d13)>E) printf("Raznostranicni\n");
		else if (fabs(d12-d13)<E && fabs(d12-d23)<E && fabs(d23-d13)<E) printf("Jednakostranicni\n");
		else if (fabs(d12-d23)<E && fabs(d12-d13)>E) printf("Jednakokraki\n");
		else if (fabs(d23-d13)<E && fabs(d23-d12)>E) printf("Jednakokraki\n");
		else if (fabs(d12-d13)<E && fabs(d12-d23)>E) printf("Jednakokraki\n");
	


		a=(d23*d23+d13*d13-d12*d12)/(2.*d23*d13);
		b=(d12*d12+d13*d13-d23*d23)/(2.*d12*d13);
		c=(d12*d12+d23*d23-d13*d13)/(2.*d12*d23);
		a1=acos(a)*STEPENI;
		b1=acos(b)*STEPENI;
		c1=acos(c)*STEPENI;
		if(fabs((d23*d23+d13*d13)-(d12*d12))<E||(fabs((d12*d12+d13*d13)-(d23*d23))<E||fabs((d12*d12+d23*d23)-(d13*d13))<E)) {
			printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");}
			else
			{
		if (a1>=b1 && a1>=c1) {
			s=a1;
			min=(a1-s)*60;
			sec=((a1-s)*60-min)*60;
		} else if(b1>=a1 && b1>=c1) {
			s=b1;
			min=(b1-s)*60;
			sec=((b1-s)*60-min)*60;
		} else if (c1>=b1 && c1>=a1) {
			s=c1;
			min=(c1-s)*60;
			sec=((c1-s)*60-min)*60;
		}

		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",s,min,sec);
	}
	}
	return 0;
	
}
