#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001
#define PI 3.14159

int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,alfa,beta,gama,alfa1,beta1,gama1,max,sat,minuta,sekunda;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	if (fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))<EPSILON) { printf("Linija\n"); printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi."); return 0;}
    if (fabs(c*c-b*b-a*a)<EPSILON || fabs(b*b-c*c-a*a)<EPSILON || fabs(a*a-b*b-c*c)<EPSILON) printf("Pravougli\n");
	if (fabs(a-b)<EPSILON && fabs(a-c)<EPSILON) printf("Jednakostranicni\n");
	else if (fabs(a-b)<EPSILON || fabs(a-c)<EPSILON || fabs(b-c)<EPSILON) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	alfa = acos((a*a+b*b-c*c)/(2*a*b));
	beta = acos((a*a+c*c-b*b)/(2*a*c));
	gama = acos((b*b+c*c-a*a)/(2*b*c));
	alfa1 = alfa*(180/PI);
	beta1 = beta*(180/PI);
	gama1 = gama*(180/PI);
	
	if( (alfa1>beta1 || fabs(alfa1-beta1)<EPSILON) && (alfa1>gama1 || fabs(alfa1-gama1)<EPSILON))
        max = alfa1;

    if( (beta1>alfa1 || fabs(beta1-alfa1)<EPSILON) && (beta1>gama1 || fabs(beta1-gama1)<EPSILON))
        max = beta1;

    if( (gama1>alfa1 || fabs(gama1-alfa1)<EPSILON) && (gama1>beta1 || fabs(gama1-beta1)<EPSILON))
        max = gama1;
   sat = (int)(max);
   minuta = (int)((max - sat)*60);
   sekunda = (int)((((max-sat)*60)-minuta)*60);
    
   printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", sat,minuta,sekunda);
	return 0;
}
