#include <stdio.h>
#include <math.h>
#define eps 0.0001

int main() {
	
	double x1, y1, x2, y2, x3, y3, d1, d2, d3, alfa, beta, gama,s ,m, st;   /*s-sekunda, m-minuta, st-stepen*/
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	d1=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
	d2=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	d3=sqrt(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
	alfa=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
	beta=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
	gama=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
	
	
	if(alfa>beta && alfa>gama) {
		alfa=alfa*180/(3.141592);
		st=(int)alfa;
		alfa=alfa-st;
		alfa=alfa*60;
		m=(int)alfa;
		alfa=alfa-m;
		alfa=alfa*60;
		s=(int)alfa;

	} else if (beta>alfa && beta>gama) {
		
	    beta=beta*180/(3.141592);
		st=(int)beta;
		beta=beta-st;
		beta=beta*60;
		m=(int)beta;
		beta=beta-m;
		beta=beta*60;
		s=(int)beta;
		
		
	} else if (gama>alfa && gama>beta) {
		
		gama=gama*180/(3.141592);
		st=(int)gama;
		gama=gama-st;
		gama=gama*60;
		m=(int)gama;
		gama=gama-m;
		gama=gama*60;
		s=(int)gama;
	}
	
	
	
	if(st==90 && m==0 && s==0) printf("Pravougli\n");
	
	if (st==180 && m==0 && s==0) printf("Linija\n");
	
	
	else if(fabs(d1-d2)<eps && fabs(d2-d3)<eps) printf("Jednakostranicni\n");
	else if(fabs(d1-d2)<eps && fabs(d2-d3)>eps) printf("Jednakokraki\n");
    else if(fabs(d1-d2)>eps && fabs(d2-d3)>eps) printf("Raznostranicni\n");
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",st, m, s);
	
	
	return 0;
}
