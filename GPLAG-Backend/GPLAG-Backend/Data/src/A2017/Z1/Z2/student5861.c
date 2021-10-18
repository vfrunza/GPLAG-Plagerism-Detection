#include <stdio.h>
#include <math.h>
#define PI 3.141592
#define EPS 0.0001

int main() {
	double x1, x2, y1, y2, x3, y3, najugao, alpha, beta, gama, u1, u2, u3;
	
	double j=180.0/PI;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	u1=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	u2=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	u3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	
	alpha=acos((u1*u1+u2*u2-u3*u3)/(2*u1*u2))*j;
	beta=acos((u1*u1-u2*u2+u3*u3)/(2*u1*u3))*j;
	gama=180.0-alpha-beta;
	
	if(beta>gama && beta>alpha)
	{
		najugao=beta;
	}else if(alpha > beta && alpha>gama)
	{
		najugao=alpha;
	}else if(gama>alpha && gama>beta)
	{
		najugao=gama;
	}
	
	int s=najugao*60*60;
	int stepeni= s/(60*60);
	int minute=(s/60) % 60;
	int sekunde=s % 60;
	
	if((najugao+EPS)>=90 && (najugao-EPS)<=90)
	
		printf("Pravougli\n");
	
	
	
	if(stepeni==180)
	{
		printf("Linija\n");
	}
	
	 else if(u1<=(u2+EPS) && u1>=(u2-EPS) && u2<=(u3+EPS) && u2>=(u3-EPS))
	{
		printf("Jednakostranicni\n");
		
	}
	else if((u1>=(u2+EPS)|| u1<=(u2-EPS)) && (u2>=(u3+EPS)||u2<=(u3-EPS)) && (u1>=(u3+EPS)||u1<=(u3-EPS)))
	{
		printf("Raznostranicni\n");
	}
	else
	{
		printf("Jednakokraki\n");
		
	}
	
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);

	return 0;
}
