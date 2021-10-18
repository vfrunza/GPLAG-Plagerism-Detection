#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001


int main() {
	
	double t1_x, t1_y;
	double t2_x, t2_y;
	double t3_x, t3_y;
	double PI = 4*atan(1);
	double v = 180/PI;
	double pomocna = 0;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &t1_x, &t1_y);
	
	printf("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &t2_x, &t2_y);
	
	printf("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &t3_x, &t3_y);
	
	double a = sqrt(pow((t1_x-t2_x),2)+pow((t1_y-t2_y),2));
	double b = sqrt(pow((t2_x-t3_x),2)+pow((t2_y-t3_y),2));
	double c = sqrt(pow((t3_x-t1_x),2)+pow((t3_y-t1_y),2));
	
	double s = (a+b+c)/2;
	double P = sqrt(s*(s-a)*(s-b)*(s-c));
	
	int linija = 0;
	if (fabs(P-0)<EPSILON)
		{
			printf("Linija\n");
			linija = 1;
		}
	
	int jednakostranicni = 0;
	if (fabs(a-b)<EPSILON && fabs(b-c)<EPSILON && fabs(c-a)<EPSILON && linija!=1)
		{
			printf("Jednakostranicni\n");
			jednakostranicni = 1;
		}
		
		
	int pravougli = 0;
	if (fabs(c*c-a*a-b*b)<EPSILON || fabs(a*a-b*b-c*c)<EPSILON || fabs(b*b-a*a-c*c)<EPSILON)
		{
			printf("Pravougli\n");
			pravougli = 1;
		}
		
	int jednakokraki = 0;
	if (fabs(a-b)<EPSILON && jednakostranicni!=1 && linija!=1)
		jednakokraki = 1;
		
	if (fabs(b-c)<EPSILON && jednakostranicni!=1 && linija!=1)
		jednakokraki = 1;
		
	if (fabs(a-b)<EPSILON && jednakostranicni!=1 && linija!=1)
		jednakokraki = 1;
		
		
	if (jednakokraki == 1)
		printf("Jednakokraki\n");
		
	
	int raznostranicni = 0;
	if (linija!=1 && jednakostranicni!=1 && jednakokraki!=1)
		{
			printf("Raznostranicni\n");
			raznostranicni = 1;
		}
		
		
	int stepeni = 0;
	int minute = 0;
	int sekunde = 0;
	
	if (linija == 1)
		stepeni = 180;
		
	if (jednakostranicni == 1)
		stepeni = 60;
		
	if (jednakokraki == 1)
		{
			pomocna = (a*a-b*b-c*c)/(-2*b*c);
			double alfa = acos(pomocna)*v;
			
			pomocna = (b*b-c*c-a*a)/(-2*c*a);
			double beta = acos(pomocna)*v;
			
			double gama = 180-alfa-beta;
			
			double ugao = alfa;
			if (beta > alfa)
				ugao = beta;
				
			if (ugao < gama)
				ugao = gama;
			
			
			stepeni = ugao;
			pomocna = (ugao - stepeni)*60;
			minute = pomocna;
			sekunde = (pomocna-minute)*60;
		}
		
		
	if (raznostranicni == 1)
		{
			pomocna = (a*a-b*b-c*c)/(-2*b*c);
			double alfa = acos(pomocna)*v;
			
			pomocna = (b*b-c*c-a*a)/(-2*c*a);
			double beta = acos(pomocna)*v;
			
			double gama = 180-alfa-beta;
			
			double ugao = alfa;
			if (beta > alfa)
				ugao = beta;
				
			if (ugao < gama)
				ugao = gama;
			
			
			stepeni = ugao;
			pomocna = (ugao - stepeni)*60;
			minute = pomocna;
			sekunde = (pomocna-minute)*60;
		}
		
	if (pravougli == 1)
		{
			stepeni = 90;
			minute = 0;
			sekunde = 0;
		}
		
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni,minute,sekunde);
	
		
	
	
	
	
	
	
	return 0;
}
