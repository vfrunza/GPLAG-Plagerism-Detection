#include <stdio.h>
#include<math.h>
#define EPSILON 0.0001


int main() {
	double x1,x2,x3,y1,y2,y3,a,b,c,ugao;
	int A=0,B=0,stepen,min,sek;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	b=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	c=sqrt(pow(x1-x3,2)+pow(y1-y3,2));

if(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))<EPSILON)
{
	printf("Linija\n");
	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	return 0;
}
	if(a<c && b<c)
	if(fabs(c*c-b*b-a*a)<EPSILON)
	{
		printf("Pravougli\n");
		A=1;
	}
	else if(a<b && c<b)
	if(fabs(b*b-a*a-c*c)<EPSILON)
	{
		printf("Pravougli\n");
		
	A=1;
	}
	else if(b<a &&c<a)
	if(fabs(a*a-b*b-c*c)<EPSILON)
	{
		printf("Pravougli\n");
		A=1;
	}
	if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON && fabs(c-a)<EPSILON)
	{
		printf("Jednakostranicni\n");
		B=1;
		
	}
	
	else if((fabs(a-b)<EPSILON &&fabs(a-c)>=EPSILON)||(fabs(a-c)<EPSILON &&fabs(a-b)>=EPSILON)||(fabs(b-c)<EPSILON &&fabs(b-a)>=EPSILON))
	{
		printf("Jednakokraki\n");
	}
	else if((a!=b) && (b!=c) && (c!=a))
	printf("Raznostranicni\n");

	if(A==1)
	printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	
	else if(B==1)
	printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
	
	else
	{if(a<c && b<c)
	ugao=acos((a*a+b*b-c*c)/(2*a*b));
	else if(a<b && c<b)
	ugao=acos((a*a+c*c-b*b)/(2*a*c));
	else
	ugao=acos((b*b+c*c-a*a)/(2*b*c));
	ugao*=180/3.14159265359;
	stepen=(int)ugao;
	min=(int)((ugao-stepen)*60);
	sek=(int)((((ugao-stepen)*60)-min)*60);
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",stepen,min,sek);
	}
	

	return 0;
}

