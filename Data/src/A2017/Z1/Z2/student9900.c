#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	int s,m,sec;
	double x1,x2,x3,y1,y2,y3,a,b,c,alfa,beta,gama;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3, &y3);
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	
	if(fabs((a*a+b*b)-c*c)<EPSILON)
	printf("Pravougli\n");
	if(fabs((x1*y2+y1*x3+x2*y3)-y1*x2-x1*y3-y2*x3)<EPSILON)
	printf("Linija\n");
	else if((fabs(a-b)<EPSILON) && fabs(a-c)>EPSILON)
	printf("Jednakokraki\n");
	else if((fabs(a-b)<EPSILON) && fabs(a-c)<EPSILON && fabs(b-c)<EPSILON)
	printf("Jednakostranicni\n");
	
	
	
	if((fabs(a-b)>EPSILON) && fabs(a-c)>EPSILON && fabs(b-c)>EPSILON)
	printf("Raznostranicni\n");
	
	gama=acos((c*c-a*a-b*b)/(-2*a*b));
	beta=acos((b*b-c*c-a*a)/(-2*a*c));
	alfa=acos((a*a-c*c-b*b)/(-2*c*b));
	
	if(alfa>beta && alfa>gama){
		alfa=(alfa*180)/(4*atan(1));
		s=(int)(alfa);
		m=(int)((alfa-s)*3600)/60;
		sec=(int)((alfa-s)*3600)%60;
	}
	else if(beta>alfa && beta>gama){
		beta=(beta*180)/(4*atan(1));
		s=(int)(beta);
		m=(int)((beta-s)*3600)/60;
		sec=(int)((beta-s)*3600)%60;
	}
	else{
		gama=(gama*180)/(4*atan(1));
		s=(int)(gama);
		m=(int)((gama-s)*3600)/60;
		sec=(int)((gama-s)*3600)%60;
	}
	if(fabs((x1*y2+y1*x3+x2*y3)-y1*x2-x1*y3-y2*x3)<EPSILON)
	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	else	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",s,m,sec);

	
	return 0;
}
	