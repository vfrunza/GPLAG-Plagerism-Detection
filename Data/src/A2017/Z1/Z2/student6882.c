#include <stdio.h>
#include <math.h>

const double eps=0.0001;
const double pi=3.1415926535897932384626433;

int main() {
	double x1, x2, y1, y2, x3, y3, a, b, c, U, m, najduza;
	int stepeni, minute, sekunde;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf", &x3, &y3);
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	if (fabs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2)<eps) {
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
		return 1;
	}
	if (fabs(a-b)>eps && fabs(b-c)>eps) {
		if (fabs(c*c-a*a-b*b)<eps || fabs(a*a-b*b-c*c)<eps || fabs(b*b-a*a-c*c)<eps) {
			printf("Pravougli\n");
			if(a>b && a>c) najduza=a;
			else if(c>b && c>a) najduza=c;
			else najduza=b;
		}
		printf("Raznostranicni\n");
		if(a>b && a>c) najduza=a;
		else if(b>a && b>c) najduza=b;
		else najduza=c;
	}
	else if (fabs(a-b)<eps && fabs(a-c)<eps) { 
		printf("Jednakostranicni\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	else {
		if (fabs(c*c-a*a-b*b)<eps || fabs(a*a-b*b-c*c)<eps || fabs(b*b-a*a-c*c)<eps) {
			printf("Pravougli\n");
			if(a>b && a>c) najduza=a;
			else if(c>b && c>a) najduza=c;
			else najduza=b;
		}
		if ((fabs(a-b)<eps || fabs(a-c)<eps || fabs(b-c)>eps) && (fabs(a-b)>eps || fabs(a-c)>eps || fabs(b-c)>eps)) {
			printf("Jednakokraki\n");
			if(fabs(a-b)<eps && a>c)  najduza=a;
			else if(fabs(a-b)<eps && a<c) najduza=c;
			if(fabs(a-c)<eps && b>c)  najduza=b;
			else if(fabs(a-c)<eps && b<c) najduza=c;
			if(fabs(b-c)<eps && a>c)  najduza=a;
			else if(fabs(b-c)<eps && a<c) najduza=c;
		}
	}
	if(fabs(najduza-a)<eps) U=acos((b*b+c*c-a*a)/(2*b*c));
	else if(fabs(najduza-b)<eps) U=acos((a*a+c*c-b*b)/(2*a*c));
	else U=acos((a*a+b*b-c*c)/(2*a*b));
	U*=(180/pi);
	stepeni=(int)U;
	m=(U-stepeni)*60;
	minute=(int)m;
	sekunde=(m-minute)*60;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", stepeni, minute, sekunde);
	return 0;
}
