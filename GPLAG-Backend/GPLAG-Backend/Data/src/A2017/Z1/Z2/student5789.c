#include <stdio.h>
#include <math.h>
#define n 10e-10
int main() {
	double x1,x2,x3,y1,y2,y3,P,Pp,a,b,c;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	P=0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	if(P<0) P=P*(-1);
	if(P==0)
	{ printf("Linija\n"); 
	  printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi."); }			
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	if(a==b==c) { printf("Jednakostranicni\n");
		 printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi."); return 0;}
	if(a>b&&a>c) Pp=(b*c/2);
	if(b>a&&b>c) Pp=(a*c/2);
	if(c>a&&c>b) Pp=(a*b/2);
	if(Pp-P<0.001) printf("Pravougli\n");
	if(P>0)
	{
if((fabs(a-b)<=n*(fabs(a)+fabs(b))&&(b!=c)&&(a!=c))||(fabs(b-c)<=n*(fabs(b)+fabs(c))&&(b!=a)&&(c!=a))||(fabs(a-c)<=n*(fabs(a)+fabs(c))&&(a!=b)&&(c!=b)))
{
	int stepeni1,minute1,sekundi1;
	double najveci1,min1;
	printf("Jednakokraki\n");
	if(a>b&&a>c) najveci1=((b*b+c*c-a*a)/(2*b*c));
	if(b>a&&b>c) najveci1=((a*a+c*c-b*b)/(2*a*c));
	if(c>a&&c>b) najveci1=((a*a+b*b-c*c)/(2*a*b));
	najveci1=acos(najveci1)*(180/3.14159);
	stepeni1=(int)najveci1;
	min1=(najveci1-stepeni1)*60;
	minute1=(int)min1;
	sekundi1=(min1-minute1)*60;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni1,minute1,sekundi1);
	return 0;
}	

	}
	double najveci=0,min,sek;
	int stepeni,minute,sekundi;
	if(P>0)
	{
	if(a!=b&&a!=c) 
	{
	printf("Raznostranicni\n");
	if(a>b&&a>c) najveci=((b*b+c*c-a*a)/(2*b*c));
	if(b>a&&b>c) najveci=((a*a+c*c-b*b)/(2*a*c));
	if(c>a&&c>b) najveci=((a*a+b*b-c*c)/(2*a*b));
	najveci=acos(najveci)*(180/3.14159);
	stepeni=(int)najveci;
	min=(najveci-stepeni)*60;
	minute=(int)min;
	sekundi=(min-minute)*60;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekundi);
	return 0;
	}
	}
	if(Pp-P<0.001) printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	return 0;
}
