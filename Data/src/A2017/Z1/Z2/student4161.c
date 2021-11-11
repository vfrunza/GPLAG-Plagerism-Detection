#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.141592
int main() {
	double a,b,c, uA,uB,uC, cA,cB,cC,max=-1;
	float xa,xb,xc,ya,yb,yc;
	int s,min,sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%f %f",&xa,&ya);
	printf("Unesite koordinate tacke t2: ");
	scanf("%f %f",&xb,&yb);
	printf("Unesite koordinate tacke t3: ");
	scanf("%f %f",&xc,&yc);
	
	a=sqrt(pow((xb-xc),2)+pow((yb-yc),2));
	b=sqrt(pow((xa-xc),2)+pow((ya-yc),2));
	c=sqrt(pow((xb-xa),2)+pow((yb-ya),2));
	
	cA=(pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c);
	cB=(pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c);
	cC=(pow(b,2)+pow(a,2)-pow(c,2))/(2*b*a);
	
	uA=(acos(cA)*180)/PI;
	uB=(acos(cB)*180)/PI;
	uC=(acos(cC)*180)/PI;
	
	if(uA>max) max=uA;
	if(uB>max) max=uB;
	if(uC>max) max=uC;
	
	if(fabs(a+b-c)<E || fabs(a+c-b)<E || fabs(b+c-a)<E){
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	else if(fabs(a-b)<E && fabs(a-c)<E && fabs(b-c)<E) printf("Jednakostranicni");
	else if((int)max==90) {
		printf("Pravougli\n");
		if(fabs(a-b)<E || fabs(a-c)<E || fabs(b-c)<E) printf("Jednakokraki");
	}
	else if(fabs(a-b)<E || fabs(a-c)<E || fabs(b-c)<E) printf("Jednakokraki");
	if(fabs(a-b)>E && fabs(a-c)>E && fabs(c-b)>E) printf("Raznostranicni");
	
	s=floor(max);
	min=floor((max-s)*60);
	sec=floor(((max-s)*60-min)*60);
	
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",s,min,sec);
	
	return 0;
}
