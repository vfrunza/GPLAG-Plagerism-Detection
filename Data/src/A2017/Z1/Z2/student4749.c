#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define EPSILON 0.00001

int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, alfa, beta, gama, ugaomax;
	int stepen, min, sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	alfa=acos(((c*c)-(a*a)-(b*b))/((-2)*a*b));
	beta=acos(((a*a)-(b*b)-(c*c))/((-2)*c*b));
	gama=acos(((b*b)-(a*a)-(c*c))/((-2)*a*c));
	if(alfa>beta && alfa>gama){
		ugaomax=alfa;
	} else if(beta>alfa && beta>gama){
		ugaomax=beta;
	} else {
		ugaomax=gama;
	}
	ugaomax=ugaomax*180/PI;
	stepen=ugaomax;
	min=(ugaomax-stepen)*60;
	sec=(((ugaomax-stepen)*60)-min)*60;
	if(stepen==0 || stepen==180){
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.", stepen, min, sec);
	} else if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON){
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	} else if((fabs(a-b)>EPSILON && fabs(a-c)>EPSILON && fabs(b-c)<EPSILON) || (fabs(b-a)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)<EPSILON) || (fabs(c-a)>EPSILON && fabs(c-b)>EPSILON && fabs(a-b)<EPSILON)){
		if(stepen==90){
			printf("Pravougli\n");
		}
		printf("Jednakokraki\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, min, sec);
	} else if(fabs(a-b)>EPSILON && fabs(a-c)>EPSILON && fabs(b-c)>EPSILON){
		if(stepen==90){
			printf("Pravougli\n");
			printf("Raznostranicni\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, min, sec);
		} else {
			printf("Raznostranicni\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, min, sec);
		}
	}
	return 0;
}