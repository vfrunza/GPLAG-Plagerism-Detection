#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592653589793238462643383279502884

int main() {
	double x1, x2, x3, y1, y2, y3, P, a, b, c, max, ugao, minute, sekunde;
	int najveci, nista=1;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	P=0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	c=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	
	max=a;
	najveci=1;
	if (b>max){
		max=b;
		najveci=2;
	}
	if (c>max){
		max=c;
		najveci=3;
	}
	
	if (fabs(P-0)<EPSILON){
		printf("Linija\n");
		nista=0;
	}
	
	else if (fabs(a-b)<EPSILON && fabs(b-c)<EPSILON){
		printf("Jednakostranicni\n");
		nista=0;
	}
	else {
		if ((najveci==1 && fabs(max-sqrt(pow(b,2)+pow(c,2)))<EPSILON)
			|| (najveci==2 && fabs(max-sqrt(pow(a,2)+pow(c,2)))<EPSILON)
			|| (najveci==3 && fabs(max-sqrt(pow(a,2)+pow(b,2)))<EPSILON)){
					printf("Pravougli\n");
		}
	
		if (fabs(a-b)<EPSILON || fabs(a-c)<EPSILON || fabs(b-c)<EPSILON){
			printf("Jednakokraki\n");
			nista=0;
		}
	}
	
	if (nista==1){
		printf("Raznostranicni\n");
	}
	
	if (najveci==1){
		ugao=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c))*180/PI;
	}
	else if (najveci==2){
		ugao=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c))*180/PI;
	}
	else{
		ugao=acos((pow(b,2)+pow(a,2)-pow(c,2))/(2*b*a))*180/PI;
	}
	
	minute=60*(ugao-(int)ugao);
	sekunde=60*(minute-(int)minute);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)ugao, (int)minute, (int)sekunde);
	return 0;
}
