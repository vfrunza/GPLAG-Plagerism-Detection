#include <stdio.h>
#include <math.h>
#define Epsilon 0.0001
#define PI 3.1415

int main() {
	double x1=0, x2=0, x3=0, y1=0, y2=0, y3=0, a=0, b=0, c=0, P=0, alfa1=0, beta1=0, gama1=0;
	int stepen=0, minut=0, sekund=0, alfa=0, beta=0, gama=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	
	
	a=sqrt(pow((x2-x3),2)+ pow((y2-y3),2));
	b=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	c=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	
	
	alfa=acos((b*b+c*c-a*a)/(2*b*c))*180/PI;
    beta=acos((a*a+c*c-b*b)/(2*a*c))*180/PI;
	gama=acos((a*a+b*b-c*c)/(2*a*b))*180/PI;
	
	
		P=((1/2)*fabs(x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2)));
	if ((x1==x2 && y1==y2) || (x2==x3 && y2==y3) || (x1==x3 && y1==y3) || alfa==180 || beta==180 || gama==180) {
		printf("Linija");
	    printf ("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	    return 0;
	}
	
	else if (a==b && b==c && a==c)
	{
		if (fabs(a-b)<Epsilon && fabs(b-c)<Epsilon && fabs(a-c)<Epsilon){
		printf("Jednakostranicni");
		printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 0;
		}	
	}
	
	/*c=sqrt(pow(a, 2)+pow(b,2));*/
    else if ((alfa==90 || beta==90 || gama==90) && (a==b || b==c || a==c)) {
	if (fabs((alfa-90)&&(beta-90)&&(gama-90))<Epsilon )
	{
		printf ("Pravougli");
		printf ("\nJednakokraki");
		printf ("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		return 0;
		
	}
     }
	
	
	
	else if (alfa==90 || beta==90 || gama==90)
	{
		if ((alfa-90)<Epsilon && (beta-90)<Epsilon && (gama-90)<Epsilon){
		printf ("Pravougli");
		printf ("\nRaznostranicni");
		printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	}
/*	else if (a==b || b==c || a==c)
	{*/
		else if (fabs(a-b)<Epsilon || fabs(b-c)<Epsilon || fabs(a-c)<Epsilon) {
		
		alfa1=acos((b*b+c*c-a*a)/(2*b*c))*180/PI;
		beta1=acos((a*a+c*c-b*b)/(2*a*c))*180/PI;
	    gama1=acos((a*a+b*b-c*c)/(2*a*b))*180/PI;
	
	stepen=(int)alfa1;
	alfa1=alfa1-stepen;
	alfa1=fabs(alfa1)*60;
	minut=(int)alfa1;
	alfa1=alfa1-minut;
	alfa1=fabs(alfa1)*60;
	sekund=(int)alfa1;

	 
	 printf ("Jednakokraki");
		
	 if (alfa>beta && alfa>gama)
	 {
	 	
	
	printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
	 
		}
	else if (beta>alfa && beta>gama) {
		stepen=(int)beta1;
	beta1=beta1-stepen;
	beta1=fabs(beta1)*60;
	minut=(int)beta1;
	beta1=beta1-minut;
	beta1=fabs(beta1)*60;
	sekund=(int)beta1;
	
	
		printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
		
	}
	else {
		stepen=(int)gama1;
	gama1=gama1-stepen;
	gama1=fabs(gama1)*60;
	minut=(int)gama1;
	gama1=gama1-minut;
	gama1=fabs(gama1)*60;
	sekund=(int)gama1;
	
	printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
	}
		}

	
	
	else if (a!=b && b!=c && a!=c)
	{
		alfa1=acos((a*a+b*b-c*c)/(2*a*b))*180/PI;
		beta1=acos((a*a+c*c-b*b)/(2*a*c))*180/PI;
	    gama1=acos((a*a+b*b-c*c)/(2*a*b))*180/PI;
		
	printf("Raznostranicni");
	
	if (alfa>beta && alfa>gama) {
	stepen=(int)alfa1;
    alfa1=alfa1-stepen;
	alfa1=fabs(alfa1)*60;
	minut=(int)alfa1;
	alfa1=alfa1-minut;
	alfa1=fabs(alfa1)*60;
	sekund=(int)alfa1;
	
	printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
	}
	else if (beta>alfa && beta>gama) {
		
		stepen=(int)beta1;
    beta1=beta1-stepen;
	beta1=fabs(beta1)*60;
	minut=(int)beta1;
	beta1=beta1-minut;
	beta1=fabs(beta1)*60;
	sekund=(int)beta1;

		printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
	}
	else {
		
	stepen=(int)gama1;
    gama1=gama1-stepen;
	gama1=fabs(gama1)*60;
	minut=(int)gama1;
	gama1=gama1-minut;
	gama1=fabs(gama1)*60;
	sekund=(int)gama1;
	
	printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minut, sekund);
	}
	}
	
	return 0;
}
