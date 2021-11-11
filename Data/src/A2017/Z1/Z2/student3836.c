#include <stdio.h>
#include <math.h>
#define PI 3.14
#define epsilon  0.0001

int main() {
	double x1,y1,x2,y2,x3,y3;
	double a,b,c,A,B,C,max;
		int Uksec,istina=1;
     int sec,min,step;
printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);

	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);

	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
			c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	A=acos((b*b+c*c-a*a)/(2*b*c));
		B=acos((c*c+a*a-b*b)/(2*c*a));
			C=acos((a*a+b*b-c*c)/(2*a*b));
				
 
	if (fabs((a*a+b*b)-c*c)<epsilon  || fabs((a*a+c*c)-b*b)<epsilon  || fabs((b*b+c*c)-a*a)<epsilon) {
		printf("Pravougli \n");                                         
	}
	if (fabs(a-b)<epsilon &&  fabs(b-c)<epsilon){
		printf("Jednakostranicni \n");                                                     
	}
	if (fabs((a+b)-c)<epsilon || fabs((a+c)-b)<epsilon || fabs((b+c)-a)<epsilon ){
		istina=0;
		printf("Linija \n");}
	if (((fabs(a-b)<epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon ) || (fabs(a-c)<epsilon && fabs(a-b)>epsilon && fabs(c-b)>epsilon) || (fabs(c-b)<epsilon && fabs(b-a)>epsilon && fabs(c-a)>epsilon)) && (istina==1))   {
		printf ("Jednakokraki \n");
	}
	if (fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon){
		printf("Raznostranicni \n");
	}
	
	
	if (A>B && A>C) {
		max=A;
	}
	if (B>A && B>C){
		max=B;
	}
	if(C>A && C>B) {
		max=C;
	}
	Uksec =  (max * 360 * 60 * 60 / (2 * M_PI));
 sec = Uksec % 60;
 min = (Uksec / 60) % 60;
 step = Uksec / (60 * 60);
 	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",step,min,sec);
	return 0;                       
}