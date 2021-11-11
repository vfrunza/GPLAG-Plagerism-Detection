#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 0.0001
#define PI 3.1415926535
int main() {
	
	double x1,y1,x2,y2,x3,y3,a,b,c,step,min,sec,alfa,beta,gama;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
    a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    b=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
    c=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
    
    alfa=acos((b*b+c*c-a*a)/(2*b*c));
    beta=acos((a*a+c*c-b*b)/(2*a*c));
    gama=acos((a*a+b*b-c*c)/(2*a*b));
    
    
    if(alfa>beta && alfa>gama) {
    	
    	alfa=alfa*(180/PI);
    	step=(int)alfa;
    	alfa=alfa-step;
    	alfa=alfa*60;
    	min=(int)alfa;
    	alfa=alfa-min;
    	alfa=alfa*60;
    	sec=(int)alfa;
    	
    } else if(beta>alfa && beta>gama) {
    	
    	beta=beta*(180/PI);
    	step=(int)beta;
    	beta=beta-step;
    	beta=beta*60;
    	min=(int)beta;
    	beta=beta-min;
    	beta=beta*60;
    	sec=(int)beta;
    	
    } else if(gama>alfa && gama>beta) {
    	
    	gama=gama*(180/PI);
    	step=(int)gama;
    	gama=gama-step;
    	gama=gama*60;
    	min=(int)gama;
    	gama=gama-min;
    	gama=gama*60;
    	sec=(int)gama;
    }
	 
	 
	if(step==90 && min==0 && sec==0) {
		printf("Pravougli\n");
	}
	
	
	if(step==180 && min==0 && sec==0) {
		printf("Linija\n");
	}
	else if(fabs(a-b)<eps  &&  fabs(b-c)<eps) {
		printf("Jednakostranicni\n");
	} else if(fabs(a-b)<eps && fabs(b-c)>eps) {
		printf("Jednakokraki\n");
	} else if(fabs(a-b)>eps && fabs(b-c)>eps) {
		printf("Raznostranicni\n");
	} 
	
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",step,min,sec);
	return 0;
}
