#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001


int main() {
	int pom,s,h,m;
	double x1,x2,x3,y1,y2,y3,max,pom1,a,b,c,alfa,beta,gama;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); /*printf("%f\n\n",c);*/
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)); /*printf("%f\n\n",b);*/
	a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)); /*printf("%f\n\n",a);*/
	alfa=acos((b*b+c*c-a*a)/(2*b*c))*180/(4*atan(1)); /*printf("%f\n\n",alfa);*/ 
	/*r=(b*b+c*c-a*a)/(2*b*c); printf("%f\n\n", r);*/
	beta=acos((a*a+c*c-b*b)/(2*a*c))*180/(4*atan(1)); /*printf("%f\n\n",beta);*/
	gama=180-alfa-beta;   /*printf("%f\n\n",c);*/
	
	/* Testiranje, prvo deklarisat r */
	/*r=alfa+beta+gama;*/
    /*printf("%f\n\n\n",r);*/ 
	
	
	max=alfa;
	if(beta>max) max=beta;
	if(gama>max) max=gama;
	
	 
	pom=max;
	h=pom;
	pom1=(max-pom)*60;
	pom=pom1;
	m=pom;
	s=(pom1-pom)*60;
	
	if((fabs(x1 - x2) < EPSILON && fabs(x2 - x3) < EPSILON)|| (fabs(y1 - y2) < EPSILON && fabs(y2 - y3) < EPSILON) || fabs(alfa - 180) < EPSILON || fabs(beta - 180) < EPSILON || fabs(gama-180) < EPSILON) printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	else
	{
		if((fabs(alfa - 90) < EPSILON || fabs(beta - 90) < EPSILON || fabs(gama - 90) < EPSILON ) && ((fabs(c-b) < EPSILON || fabs(b-a) < EPSILON || fabs(a-c) < EPSILON))) printf("Pravougli\nJednakokraki\n");
		else if ((fabs(alfa - 90) < EPSILON || fabs(beta - 90) < EPSILON || fabs(gama - 90) < EPSILON)) printf("Pravougli\nRaznostranicni\n");
		else if(fabs(alfa - 90) < EPSILON || fabs(beta - 90) < EPSILON || fabs(gama - 90) < EPSILON) printf("Pravougli\n");
		else if((fabs(c -b) < EPSILON && fabs(b - a) < EPSILON)|| ((fabs(alfa - 60) < EPSILON && fabs(beta - 60) < EPSILON) || (fabs(alfa - 60) < EPSILON && fabs(gama - 60) < EPSILON) || (fabs(beta - 60) < EPSILON && fabs(gama - 60) < EPSILON) || (fabs(h - 60) < EPSILON && fabs(s - 0) < EPSILON && fabs(m - 0) < EPSILON))) printf("Jednakostranicni\n");
		else if(fabs(c - b) < EPSILON || fabs(b - a) < EPSILON || fabs(a - c) < EPSILON) printf("Jednakokraki\n");
		else printf("Raznostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", h,m,s);
	}
	
	return 0;
}
