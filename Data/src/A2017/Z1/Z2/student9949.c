#include <stdio.h>
#define PI 3.14159
#include <math.h>
#define e 0.0001

int main() {
    double x1,x2,x3,y1,y2,y3;
    double a,b,c,x,y,z,max,t;
    int st,min,s;
    
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	/* Vrsta trougla */
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	
	if(fabs((a*a+b*b)-c*c)<e || fabs((a*a+c*c)-b*b)<e || fabs((c*c+b*b)-a*a)<e){
	    printf("Pravougli\n");
	}
	if((fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))-0)<e){
	    printf("Linija\n");
	} else if(fabs(a-b)<e && fabs(b-c)<e){
	    printf("Jednakostranicni\n");
	} else if(fabs(a-b)>e && fabs(b-c)>e && fabs(a-c)>e){
	    printf("Raznostranicni\n");
	} else if(fabs(a-b)<e || fabs(b-c)<e || fabs(a-c)<e){
	    printf("Jednakokraki\n");
	} 
	
	/* Ugao */
	x=acos((a*a+b*b-c*c)/(2*a*b))*180/PI;
	y=acos((a*a+c*c-b*b)/(2*a*c))*180/PI;
	z=acos((c*c+b*b-a*a)/(2*c*b))*180/PI;
	
	max=x;
	if(y>max){max=y;}
	else if(z>max){max=z;}
	
	st=max;
	t=(max-st)*60;
	min=t;
	s=(t-min)*60;
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st,min,s);
	return 0;
}
