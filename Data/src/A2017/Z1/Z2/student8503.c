#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.141592
int main() {
	double x1,x2,x3,y1,y2,y3,a,b,c;
	double najugao,ugaoa,ugaob,ugaoc;
	int stepeni,minute,sekunde;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);

	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	 
	a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	
	ugaoa=acos((-a*a+b*b+c*c)/(2.0*b*c))*180.0/PI;
	ugaob=acos((-b*b+a*a+c*c)/(2.0*a*c))*180.0/PI;
	ugaoc=acos((-c*c+b*b+a*a)/(2.0*b*a))*180.0/PI;
	
	if((ugaoa>ugaob) && (ugaoa>ugaoc))
	najugao=ugaoa;
	if((ugaob>ugaoa) && (ugaob>ugaoc))
	najugao=ugaob;
	if((ugaoc>ugaob) && (ugaoc>ugaoa))
	najugao=ugaoc;
	
	if(fabs(najugao-90.0)<e)
	printf("Pravougli\n");
	
	if(fabs(najugao-180.0)<e)
	printf("Linija\n");
	
	else if(fabs(a-b)<e && fabs(b-c)<e)
	printf("Jednakostranicni\n");
	
	else if(fabs(a-b)<e || fabs(b-c)<e || fabs(a-c)<e)
	printf("Jednakokraki\n");
	
	else printf("Raznostranicni\n");
	

	
	stepeni = (int)najugao;
	
	ugaoa=(najugao-(double)stepeni)*60.0;
	
	minute=(int)ugaoa;
	
	ugaob=(ugaoa-(double)minute)*60.0;
	
	sekunde=(int)ugaob;
	
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",stepeni,minute,sekunde);
	
	return 0;
}
