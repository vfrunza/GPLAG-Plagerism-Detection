#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define EPSILON 0.0001

int main() {
	
	/*inicijalizacija*/
	double a,b,c;
	double x1, x2, y1, y2, x3, y3;
	double alfa, beta, gama, najveci_ugao;
	int stepen, minuta, sekunda;
	
	/*unosi koordinate tacaka*/
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	/*racunanje udaljenosti izmedju tacaka*/
	a=sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	b=sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
	c=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	
	/*racunanje uglova*/
	alfa=acos((b*b + c*c - a*a)/(2*b*c)) * 180.0 / PI;
	beta=acos((a*a + c*c - b*b)/(2*a*c)) * 180.0 / PI;
	gama=acos((a*a + b*b - c*c)/(2*a*b)) * 180.0 / PI;
	
	/*uslovi trouglova*/
	if((fabs(alfa-90.0)<EPSILON || fabs(beta-90.0)<EPSILON || fabs(gama-90.0)<EPSILON))
	{
	    printf("Pravougli\n");
	}
	
	if(fabs(alfa-180.0)<EPSILON || fabs(beta-180.0)<EPSILON || fabs(gama-180.0)<EPSILON)
	{
	    printf("Linija\n");
	}
	
	else if (fabs(a-b)<EPSILON && fabs(a-c)<EPSILON && fabs(b-c)<EPSILON) 
	{
	 printf("Jednakostranicni\n");   
	}
	
	else if(fabs(a-b)<EPSILON || fabs(a-c)<EPSILON || fabs(b-c)<EPSILON)
	{
	    printf("Jednakokraki\n");
	}
	
	else 
	{
	    printf("Raznostranicni\n");
	}
	
	if(alfa>beta && alfa>gama)
	{
	    najveci_ugao=alfa;
	}
	 
	if(beta>alfa && beta>gama)
	{
	    najveci_ugao=beta;
	}
	
	if(gama>alfa && gama>beta)
	{
	    najveci_ugao=gama;
	}
	
	stepen = (int)najveci_ugao;
	minuta = (int)((najveci_ugao - stepen)*60);
	sekunda = (int)((najveci_ugao - stepen - minuta/60.0)*3600);
	
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen, minuta, sekunda);
	
	
	
	
	return 0;
}
