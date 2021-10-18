#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592

int main() {
	double x1, y1, x2, y2, x3, y3, a, b, c, alfa, beta, gama, ugao, m;
	int ukupno, sekunde, minute, stepeni;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	a=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	c=sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	alfa=acos((b*b + c*c - a*a)/(2*b*c));
	beta=acos((a*a + c*c - b*b)/(2*a*c));
	gama=acos((a*a + b*b - c*c)/(2*b*a));
	if(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))>(-EPSILON) && fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))<EPSILON){
		printf("Linija\n");
		goto uglovi;
	} 
	if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON && fabs(b-c)<EPSILON){
		printf("Jednakostranicni\n");
	} else
	if(fabs(alfa-(PI/2))<EPSILON || fabs(beta-(PI/2))<EPSILON || fabs(gama-(PI/2))<EPSILON){
		printf("Pravougli\n");
	} 
	if((fabs(a-b)<EPSILON || fabs(b-c)<EPSILON || fabs(a-c)<EPSILON) && (fabs(a-b)>EPSILON || fabs(b-c)>EPSILON || fabs(a-c)>EPSILON)){
		printf("Jednakokraki\n");
	} 
	if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON) {
		printf("Raznostranicni\n");
	}
	/* Uglovi */
	uglovi:
	if(alfa>=beta && alfa>=gama){
		ugao=alfa;
	} else if(beta>=alfa && beta>=gama){
		ugao=beta;
	} else {
		ugao=gama;
	}
	m=(ugao*180)/PI;
	ukupno=(int)(m*60*60);
	sekunde=ukupno%60;
	minute=(ukupno/60)%60;
	stepeni=ukupno/(60*60);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	return 0;
}
