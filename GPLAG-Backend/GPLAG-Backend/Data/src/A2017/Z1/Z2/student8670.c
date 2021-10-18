#include <stdio.h>
#include <math.h>

int main() {
	
	double eps=0.00001,PI=3.14159265359;
	double x1,x2,x3,y1,y2,y3;
	double a,b,c;
	double alfa,beta,gama;
	double max;
	int stepeni,minute,sekunde;
	int jednakostranicni=0;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	
	
	a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	b=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	c=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	
	alfa=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	beta=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	gama=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
	alfa=alfa*180/PI;
	beta=beta*180/PI;
	gama=gama*180/PI;
	max=beta;
	if(alfa>max) max=alfa;
	if(gama>max) max=gama;
	

	
	max=max+eps;
	if((fabs(x1-x2)<eps && fabs(x1-x3)<eps)||(fabs(y1-y2)<eps && fabs(y1-y3)<eps)||fabs(max-180)<eps) printf("Linija\n");
	else{ if(fabs(a-b)<eps && fabs(a-c)<eps && fabs(b-c)<eps){printf("Jednakostranicni\n");jednakostranicni=1;}
	if(fabs(max-90.0)<eps) printf("Pravougli\n");
	if((fabs(a-b)<eps || fabs(a-c)<eps || fabs(b-c)<eps)&&jednakostranicni==0) printf("Jednakokraki\n");
	if(fabs(a-b)>=eps && fabs(a-c)>=eps && fabs(b-c)>=eps) printf("Raznostranicni\n");}
	
	
	stepeni=(int)max;
	max=max-stepeni;
	max*=60;
	minute=(int)max;
	max=max-minute;
	max*=60;
	sekunde=(int)max;

	
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	return 0;
}
