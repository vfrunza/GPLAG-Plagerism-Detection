#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.14159265359
int main() {
	double a,x1,y1,x2,y2,x3,y3,b,c,P,alfa,beta,gama,minuta1,minuta2,minuta3;
	int alfa1,beta1,gama1,M1,M2,M3,sek1,sek2,sek3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	P=fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
	
	if(fabs(a*a-b*b-c*c)<eps|| fabs(b*b-a*a-c*c)<eps || fabs(c*c-a*a-b*b)<eps)
		printf("Pravougli\n");
	if(fabs(P)<eps)
		printf("Linija\n");
	else if((fabs(a-b)<eps) && (fabs(b-c)<eps))
	printf("Jednakostranicni\n");
	else if(((fabs(a-c)<eps) || (fabs(b-c)<eps) || (fabs(a-b)<eps)))
	printf("Jednakokraki\n");
	else  
	printf("Raznostranicni\n");
	
	
   alfa=(acos((b*b+c*c-a*a)/(2*c*b)))*180/PI+eps;
   beta=(acos((a*a+c*c-b*b)/(2*a*c)))*180/PI+eps;
   gama=(acos((a*a+b*b-c*c)/(2*a*b)))*180/PI+eps;
   alfa1=(int)alfa;
   beta1=(int)beta;
   gama1=(int)gama;
   minuta1=(alfa-alfa1)*60;
   minuta2=(beta-beta1)*60;
   minuta3=(gama-gama1)*60;
   M1=(int)minuta1;
   M2=(int)minuta2;
   M3=(int)minuta3;
  sek1=(minuta1-M1)*60;
  sek2=(minuta2-M2)*60;
  sek3=(minuta3-M3)*60;
if((alfa>beta) && (alfa>gama))
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", alfa1,M1,sek1);
if((beta>alfa) && (beta>gama))
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", beta1,M2,sek2);

if((gama>alfa) && (gama>beta))
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", gama1,M3,sek3);

	return 0;
}
