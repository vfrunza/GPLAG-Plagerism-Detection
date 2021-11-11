#include <stdio.h>
#define EPSILON 0.0001
#include <math.h>


int main() {
	
	double x1,x2,x3,y1,y2,y3,a,b,c,alfa,beta,gama,pi,ugao=0;
	
	int stepen, minute, sekunde, razmak=0;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	 
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	 
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((c*c+a*a-b*b)/(2*c*a));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	 
	pi=acos(-1);
	 
	ugao=alfa;
	if(ugao<beta) ugao=beta;
	if(ugao<gama) ugao=gama;
	ugao=(ugao*180)/pi;
	 
	 
	if(fabs(c*c-a*a-b*b)<EPSILON || fabs(a*a-b*b-c*c)<EPSILON || fabs(b*b-a*a-c*c)<EPSILON){
		printf("Pravougli");
	 	razmak++;
	}
	
	if((fabs(b-c)<EPSILON && fabs(a-b)>EPSILON && fabs(a-c)>EPSILON) || (fabs(a-b)<EPSILON && fabs(c-a)>EPSILON && fabs(c-b)>EPSILON) || (fabs(a-c)<EPSILON && fabs(a-b)>EPSILON && fabs(c-b)>EPSILON)){
	 	if(razmak==1) printf("\n");
	 	if(fabs(ugao-180)>EPSILON)
	 	printf("Jednakokraki");
	}
	 
	else if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON && fabs(b-c)<EPSILON) {
	 	printf("Jednakostranicni");
	}
	 
	else if(fabs(a-b)>EPSILON && fabs(a-c)>EPSILON && fabs(b-c)>EPSILON) {
	 	if(razmak==1) printf("\n");
	 	printf("Raznostranicni");
	}
	 
	 stepen=ugao;
	 minute=((ugao-stepen)*60);
	 sekunde=((ugao-stepen)*60-minute)*60;
    if(fabs(ugao-180)<EPSILON){ printf("Linija");
	 	
	}
	   printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen,minute,sekunde);
	  
	 

	 return 0;
}
