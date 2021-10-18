#include <stdio.h>
#include <math.h>
#include <cstdlib>
#define e 0.0001
int main() {
	double x1,x2,x3,y1,y2,y3,a,b,c,cosa,cosb,cosc;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf" "%lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf" "%lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf" "%lf",&x3,&y3);
	
	c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	

	cosa=((pow(c,2)+pow(b,2)-pow(a,2))/2*b*c);
	cosb=((pow(a,2)+pow(c,2)-pow(b,2))/2*a*c);
	cosc=((pow(a,2)+pow(b,2)-pow(c,2))/2*a*b);
	
	
	if(cosa==0 || cosb==0 || cosc==0)
	printf("Pravougli");
	
	else if ((c-b)<e && (b-a)<e && (c-a)<e && x1!=0 && x2!=0 && x3!=0)
	printf("Jednakostranicni");
	else if(c!=b && c!=a && b!=a)
	printf("Raznostranicni");
	else if(((c-b)<e && (abs(c-a))>e) || ((c-a)<e && (abs(c-b))>e) || ((b-a)<e && (abs(b-c))>e))
	printf("jednakokraki");
	
	return 0;
}
