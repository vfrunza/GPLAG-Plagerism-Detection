#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265358979323846
int main() {
	double x1, y1, x2, y2, x3, y3, P, a, b, c, alfa, beta, gama, min1, min2, min3, sek1, sek2, sek3;
	int  ugao1, ugao2, ugao3, minuta1, minuta2, minuta3, sekunda1, sekunda2, sekunda3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	P=(0.5)*(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	
	if(P==0) {
		printf("Linija\n");
	} else {
    if ((fabs(a*a-b*b-c*c)<EPSILON) || (fabs(b*b-a*a-c*c)<EPSILON) || (fabs(c*c-a*a-b*b)<EPSILON)) {
		printf("Pravougli\n");
	}  if ((fabs(a-b)<EPSILON) && (fabs(a-c)<EPSILON) && (fabs(b-c)<EPSILON)) {
		printf("Jednakostranicni\n");
	} if ((fabs(a-b)>EPSILON) && (fabs(a-c)>EPSILON) && (fabs(b-c)>EPSILON)) {
		printf("Raznostranicni\n");
	}
	// if (((fabs(a-b)<EPSILON) && (fabs(a-c)<EPSILON) && (fabs(b-c)>EPSILON)) || ((fabs(a-b)<EPSILON) && (fabs(b-c)<EPSILON) && (fabs(a-c)>EPSILON)) || ((fabs(a-c)<EPSILON) && (fabs(b-c)<EPSILON) && (fabs(a-b)>EPSILON))){
		if( (a==b && b!=c) || (a==c && b!=c) || (c==b && b!=c) ||
		printf("Jednakokraki\n");
	}
	}
	alfa=acos((b*b+c*c-a*a)/(2*b*c))*(180/PI);
	beta=acos((a*a+c*c-b*b)/(2*a*c))*(180/PI);
	gama=acos((b*b+a*a-c*c)/(2*b*a))*(180/PI);	
	
	ugao1=alfa/1;
	ugao2=beta/1;
	ugao3=gama/1;
	
	min1=(alfa-ugao1)*60;
	min2=(beta-ugao2)*60;
	min3=(gama-ugao3)*60;
	
	minuta1=min1/1;
	minuta2=min2/1;
	minuta3=min3/1;
	
	sek1=(min1-minuta1)*60;
	sek2=(min2-minuta2)*60;
	sek3=(min3-minuta3)*60;
	
	sekunda1=sek1/1;
	sekunda2=sek2/1;
	sekunda3=sek3/1;
	
	if(alfa>beta && alfa>gama) {
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao1, minuta1, sekunda1);
	} else if(beta>alfa && beta>gama) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao2, minuta2, sekunda2);
	} else if(gama>alfa && gama>beta) {
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ugao3, minuta3, sekunda3);
	}
	
	
	return 0;
}
