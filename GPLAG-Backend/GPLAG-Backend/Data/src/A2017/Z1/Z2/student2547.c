#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	int sekunde,minute,stepeni;
	double x1,y1,x2,y2,x3,y3,a,b,c,alfa,beta,gama,najveci,se;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	alfa=((a*a+b*b-c*c)/(2*a*b));
	beta=((b*b+c*c-a*a)/(2*b*c));
	gama=((c*c+a*a-b*b)/(2*c*a));
	alfa=acos(alfa);
	beta=acos(beta);
	gama=acos(gama);
	if(alfa>beta && alfa>gama)
	{
		najveci=alfa;
	}
	else if(beta>alfa && beta>gama)
	{
		najveci=beta;
	}
	else if(gama>alfa && gama>beta)
	{
		najveci=gama;
	}
	se=(najveci*180/PI)*3600;
	stepeni=se/3600;
	minute=(se-stepeni*3600)/60;
	sekunde=se-stepeni*3600-minute*60;
	sekunde=abs(sekunde);
	minute=abs(minute);
	if(stepeni==90)
	{
		printf("Pravougli\n");
	}
	if(stepeni==60)
	{
		printf("Jednakostranicni\n");
	}
	else if(stepeni==180)
	{
		printf("Linija\n");
	}
	else if(((a-b)==0 && a!=c) || ((a-c)==0 && a!=b) || ((b-c)==0 && a!=c))
	{
		printf("Jednakokraki\n");
	}
	else if(a!=b && a!=c && b!=c)
	{
		printf("Raznostranicni\n");
	}
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	return 0;
}
