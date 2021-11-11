#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14

int main() {
	float x1,y1,x2,y2,x3,y3;
	double a,b,c,A,B,C,max;
	int Ukupno_sekundi,istinitost = 1,sec,min,stepen;
	printf("Unesite koordinate tacke t1 : ");
	scanf("%f %f", &x1,&y1);
	printf("Unesite koordinate tacke t2 : ");
	scanf("%f %f", &x2,&y2);
	printf("Unesite koordinate tacke t3 : ");
	scanf("%f %f", &x3,&y3);
	a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	b=sqrt(pow(x3-x2,2)+pow (y3-y2,2));
	c=sqrt(pow(x3-x1,2)+pow (y3-y1,2));
	A=acos((pow(b,2)+ pow(c,2)-pow(a,2))/(2*b*c));
	B=acos((pow(c,2)+ pow(a,2)-pow(b,2))/(2*a*c));
	C=acos((pow(a,2)+ pow(b,2)-pow(c,2))/(2*a*b));
	if(fabs((a*a+b*b)-c*c) < epsilon
	|| fabs((a*a+c*c)-b*b) < epsilon
	|| fabs((b*b+c*c)-a*a) < epsilon)
	{
		printf("Pravougli trougao \n"); 
		
	}
	
	if(fabs(a-b)<epsilon && fabs(b-c)<epsilon)
	{
		printf("Jednakostranicni trougao \n");
	}
	if(fabs((a+b)-c)< epsilon 
	|| fabs((a+c)-b)< epsilon
	|| fabs((b+c)-a)< epsilon)
	{
		istinitost = 0;
		printf("Linija \n");
	}
	if ((((fabs(a-b)<epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon)
	||  fabs(a-c)<epsilon && fabs(a-b)>epsilon && fabs(c-b)>epsilon)
	||  fabs(c-b)<epsilon && fabs(b-a)>epsilon && fabs(c-a)>epsilon)
	&& (istinitost=1)) 
	{
		printf("Jednakokraki trougao \n");
	}
	if (fabs(a-b)>epsilon && fabs(c-a)>epsilon && fabs(b-c)>epsilon)
	{
		printf("Raznostranicni trougao \n");
	}
	
	if(A>B && A>C)
	{
		max=A;
	}
	if(B>A && B>C)
	{
		max=B;
	}
	if(C>A && C>B)
	{
		max=C;
	}
	Ukupno_sekundi=(max * 360 * 60 * 60/(2*PI));
	sec=Ukupno_sekundi % 60;
	min=(Ukupno_sekundi/60)% 60;
	stepen = Ukupno_sekundi/(60*60);
	printf("Najveci ugao ima %d stepeni %d minuta %d sekundi.",stepen,min,sec);
	
	
	
	return 0;
}
