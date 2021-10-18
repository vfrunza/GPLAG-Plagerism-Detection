#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define pi 3.141592
#include <stdlib.h>

int main() {
	
	double x1,y1,x2,y2,x3,y3,alfa,beta,gama,a,b,c,P,stepen,minuta,sekunda;
	
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	
	a=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	b=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	c=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	
	alfa=acos((b*b+c*c-a*a)/(2*b*c))*(180/pi);
	beta=acos((a*a+c*c-b*b)/(2*a*c))*(180/pi);
	gama=acos((a*a+b*b-c*c)/(2*a*b))*(180/pi);
	
	
	P=fabs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2);

	if ((P-0)<epsilon){
		printf ("Linija");
	} else{
	
	
		if (fabs(alfa-beta)<=epsilon && fabs(beta-gama)<=epsilon && fabs(alfa-gama)<=epsilon){
			printf ("Jednakostranicni");
	}
		 if (fabs(alfa-90)<=epsilon || fabs(beta-90)<=epsilon || fabs(gama-90)<=epsilon){
			printf ("Pravougli\n");
	}
		 if ((fabs(a-b)<epsilon && fabs(a-c)>epsilon) || (fabs(a-c)<epsilon && fabs(a-b)>epsilon) || (fabs(b-c)<epsilon && fabs(b-a)>epsilon)){
		printf ("Jednakokraki");
	}  if (fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon){
		printf ("Raznostranicni");
	}
	}
	
	if (a>b && a>c){
	
	stepen=(int) alfa;
	alfa=alfa-stepen;
	minuta= (int)(alfa*60);
	alfa=alfa*60;
	alfa=alfa-(int)(alfa);
	sekunda=(int)(alfa*60);
	
	printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen, minuta, sekunda);
	} else if (b>a && b>c){
	
	stepen=(int) beta;
	beta=beta-stepen;
	minuta=(int)(beta*60);
	beta=beta*60;
	beta=beta-(int)(beta);
	sekunda=(int)(beta*60);
	
	printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen, minuta, sekunda);
	} else {
		stepen=(int) gama;
		gama=gama-stepen;
		minuta= (int)(gama*60);
		gama=gama*60;
		gama=gama-(int)(gama);
		sekunda=(int)(gama*60);
	
	printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepen, minuta, sekunda);
	}
	
	return 0;
}
