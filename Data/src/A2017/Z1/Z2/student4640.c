#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159

int main() {
	int linija=0, pravougli=0,jednakostranicni=0;
	double x1,y1,x2,y2,x3,y3,a,b,c,alfa,beta,gama,stepenip,minutep,sekundep,stepeni,minute,sekunde,max;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	
	a=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	b=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	c=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	
	
	if (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) + sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2)) - sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)) <= EPSILON* (fabs(sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) + sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2))) + fabs(sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1))))){
	printf ("Linija\n");
	linija=1;
	}
	else {
	 if (fabs(c*c - a*a - b*b)<EPSILON || fabs(b*b - a*a - c*c)<EPSILON || fabs(a*a - b*b - c*c)<EPSILON) { printf("Pravougli\n");
	 pravougli=1; }
	 if (fabs(a-b)<EPSILON && fabs(b-c)<EPSILON && fabs(a-c)<EPSILON) {
		printf ("Jednakostranicni\n");
		jednakostranicni=1; 
		}
	 else if ((fabs(a-b)<EPSILON && b!=c) || (fabs(b-c)<EPSILON && b!=a) || (fabs(a-c)<EPSILON && c!=b)) 
		printf ("Jednakokraki\n");
		
			
	else if (a!=b && a!=c && b!=c) 
		printf ("Raznostranicni\n");
		
		}
		
		if (linija) printf ("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		else if (pravougli) printf ("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		else if (jednakostranicni) printf ("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		else {
		alfa=acos((b*b + c*c - a*a)/(2*b*c));
		beta=acos((a*a + c*c - b*b)/(2*a*c));
		gama=acos((a*a + b*b - c*c)/(2*a*b));
    	max=alfa;
		if(beta>max) max=beta;
	    else if(gama>max) max=gama;
	    
	    stepenip=(max*180)/PI;
	  	stepeni=(int)stepenip;
		minutep=(stepenip-stepeni)*60;
	    minute=(int)minutep;
	    sekundep=(minutep-minute)*60;
	    sekunde=(int)sekundep;
	    
		
printf ("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepeni,minute,sekunde);
		}
		
return 0;
}
