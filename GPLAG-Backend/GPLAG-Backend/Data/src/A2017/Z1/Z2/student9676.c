#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.141592

int main() {
	
	double x1,x2,x3,y1,y2,y3;
	double a,b,c;
	double alfa,beta,gama;
	double najveci;
	int stepen,min,sec;
	
	
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf",&x1,&y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf",&x2,&y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf",&x3,&y3);
	
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

  	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((c*c+a*a-b*b)/(2*c*a));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	
	if(alfa>beta && alfa>gama) najveci=alfa;
	else if(beta>alfa && beta>gama) najveci=beta;
	else najveci=gama;
	
	najveci*=180/PI;
	stepen=(int)najveci;
	
	najveci-=stepen;
	najveci*=60;
	
	min=(int)najveci;
	najveci-=min;
	
	najveci*=60;
	sec=(int)najveci;
	if(stepen==180&&min==0&&sec==0){
		printf("Linija\n");
	}
	else if(fabs(a-b)<eps && (fabs(b-c)<eps) && (fabs(a-c)<eps)) {
	    printf("Jednakostranicni\n");
	}
	
	else if(fabs(a-b)<eps && fabs(b-c)>eps && fabs(a*a+b*b-c*c)<eps) {
        printf("Pravougli\n");
	    printf("Jednakokraki");
	}
	
	else if(fabs(a-b)<eps && fabs(b-c)>eps && fabs(a*a-b*b-c*c)<eps) {
	    printf("Pravougli\n");
	    printf("Jednakokraki");
	}
	else if(fabs(a-b)<eps && fabs(b-c)>eps && fabs(b*b-a*a+c*c)<eps) {
	    printf("Pravougli\n");
	    printf("Jednakokraki");
	}
	else if(fabs(a-c)<eps && fabs(c-b)>eps && fabs(a*a+b*b-c*c)<eps) {
	    printf("Pravougli\n");
	    printf("Jednakokraki");
	}
	else if(fabs(a-c)<eps && fabs(c-b)>eps && fabs(a*a-b*b+c*c)<eps) {
	    printf("Pravougli\n");
	    printf("Jednakokraki");
	}
	else if(fabs(a-c)<eps && fabs(c-b)>eps && fabs(b*b-a*a+c*c)<eps) {
	    printf("Jednakokraki\n");
	    printf("Pravougli");
	}
	else if(fabs(b-c)<eps && fabs(b-a)>eps && fabs(a*a+b*b-c*c)<eps) {
	    printf("Pravougli\n");
	    printf("Jednakokraki");
	}
	else if(fabs(b-c)<eps && fabs(b-a)>eps && fabs(a*a-b*b+c*c)<eps){
	    printf("Pravougli\n");
	    printf("Jednakokraki");
	}
	else if(fabs(b-c)<eps && fabs(b-a)>eps && fabs(b*b-a*a+c*c)<eps) {
	    printf("Pravougli\n");
	    printf("Jednakokraki");
	}
	
	else if((x1==x2 && x1==x3 && x2==x3) || (y1==y2 && y2==y3 && y1==y3)) { printf("Linija\n");}

	else if(fabs(a-b)<eps && fabs(b-c)>eps) { printf("Jednakokraki"); }
	else if(fabs(c-b)<eps && fabs(b-a)>eps) { printf("Jednakokraki"); }
	else if(fabs(a-c)<eps && fabs(c-b)>eps) { printf("Jednakokraki"); }
	
	else if(fabs(a*a+b*b-c*c)<eps) { printf("Pravougli\n"); printf("Raznostranicni"); }
	else if(fabs(a*a-b*b-c*c)<eps) { printf("Pravougli\n"); printf("Raznostranicni"); }
	else if(fabs(b*b-a*a+c*c)<eps) { printf("Pravougli\n"); printf("Raznostranicni"); }
	
	else printf("Raznostranicni");
	

	
    alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((c*c+a*a-b*b)/(2*c*a));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	
	if(alfa>beta && alfa>gama) najveci=alfa;
	else if(beta>alfa && beta>gama) najveci=beta;
	else najveci=gama;
	
	najveci*=180/PI;
	stepen=(int)najveci;
	
	najveci-=stepen;
	najveci*=60;
	
	min=(int)najveci;
	najveci-=min;
	
	najveci*=60;
	sec=(int)najveci;
	
   printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen, min, sec); 
	
	
	return 0;
}