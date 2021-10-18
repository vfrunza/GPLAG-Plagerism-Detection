#include <stdio.h>
#include <math.h>
#define ep 0.0001
#define PI (4. * atan (1.))
int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,P,s;
	double alfa, beta, gama, stepeni, minute, sekunde;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	s = (a+b+c)/2.0;
    P = sqrt (s*(s-a)*(s-b)*(s-c));
    if (P < ep) {
    printf("Linija\n");
    printf ("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    return 1;
    }
    alfa=acos((b*b+c*c-a*a)/(2.0*b*c));
    beta=acos((c*c+a*a-b*b)/(2.0*a*c));
    gama=acos((b*b+a*a-c*c)/(2.0*b*a));
    if ((fabs(alfa-PI/2.0) < ep) || (fabs(beta-PI/2.0) < ep) || (fabs(gama-PI/2.0) < ep)) 
    	printf ("Pravougli\n");
    if (fabs(a-b) < ep && fabs(a-c) < ep && fabs(b-c) < ep ) {
    	printf ("Jednakostranicni\n");
    	
    	}
    else if (fabs(a-b) < ep || fabs(a-c) < ep || fabs(b-c) < ep)
    printf ("Jednakokraki\n");
    else printf ("Raznostranicni\n");
    if (alfa > beta && alfa > gama) {
    	stepeni = alfa * 180.0/PI;
    	minute = (stepeni-(int)stepeni)*60.0;    	
        sekunde = (minute-(int)minute)*60.0;
        stepeni = (int)stepeni;
        minute  = (int)minute;
        sekunde = (int)sekunde;
    }
    if (beta > alfa && beta > gama) {
    	stepeni = beta * 180.0/PI;
    	minute = (stepeni-(int)stepeni)*60.0;    	
        sekunde = (minute-(int)minute)*60.0;
        stepeni = (int)stepeni;
        minute  = (int)minute;
        sekunde = (int)sekunde;
    }
    if (gama > beta && alfa < gama) {
    	stepeni = gama * 180.0/PI;
    	minute = (stepeni-(int)stepeni)*60.0;    	
        sekunde = (minute-(int)minute)*60.0;
        stepeni = (int)stepeni;
        minute  = (int)minute;
        sekunde = (int)sekunde; 
    }
        printf ("Najveci ugao ima %.0f stepeni, %.0f minuta i %0.f sekundi.",stepeni,minute,sekunde);
    
	return 0;
}
