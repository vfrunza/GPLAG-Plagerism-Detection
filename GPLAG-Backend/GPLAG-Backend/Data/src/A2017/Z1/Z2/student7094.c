#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.141592

int main() {
	double a,b,c,x3,y3,x1,y1,x2,y2;
	double alfa, beta, gama;
	double x=0,min=0,sec=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	a=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	b=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	c=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	
		alfa=alfa*(180/PI);
		beta=beta*(180/PI);
		gama=gama*(180/PI);
		
	if (fabs(alfa-180)<=eps || fabs(beta-180)<=eps || fabs(gama-180)<=eps || fabs(alfa)<=eps || fabs(beta)<=eps || fabs(gama)<=eps)
	printf("Linija\n");
		
	else
	{
	    if ((fabs(alfa-90)<=eps) || (fabs(beta-90)<=eps) || (fabs(gama-90)<=eps))
		printf ("Pravougli\n");
		if (fabs(alfa-beta)<=eps && fabs(alfa-gama)<=eps)
		printf ("Jednakostranicni\n");
		else if (fabs(alfa-beta)<=eps || fabs(alfa-gama)<=eps || fabs(gama-beta)<=eps)
		printf ("Jednakokraki\n");
		else printf ("Raznostranicni\n");}
		
	


		
	if (alfa>beta && alfa>gama){
	x=(alfa-(int)alfa)*60;
	alfa=(int)alfa;
	min=(int)x;
	x=x-(int)x;
	sec=(int)(x*60);
	printf ("Najveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", alfa,min,sec);
	} 
	
	else if(beta>alfa && beta>gama){
		x=(beta-(int)beta)*60;
		beta=(int)beta;
		min=(int)x;
		x=x-(int)x;
		sec=(int)(x*60);
		printf ("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", beta,min,sec);
	}
	
	else if(gama>alfa && gama>beta){
		x=(gama-(int)gama)*60;
		gama=(int)gama;
		min=(int)x;
		x=x-(int)x;
		sec=(int)(x*60);
		printf ("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", gama,min,sec);
	}
	
	return 0;
}
