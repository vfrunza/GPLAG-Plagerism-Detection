#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	double x1,x2,x3,y1,y2,y3,a,b,c;
	double alfa,beta,gama;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	
	if((a+b)<c || (a+c)<b ||(b+c)<a) {
		printf("Linija");
		return 0;
	}
	
	if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON && fabs(b-c)<EPSILON) {
		printf("Jednakostranicni\n");
		alfa=asin(0.5);
		printf("Najveci ugao ima %g stepeni, 0 minuta i 0 sekundi.",alfa);
		
	}
	if((c*c-(b*b+a*a)<EPSILON) || (b*b-(a*a+c*c)<EPSILON) || (a*a-(b*b+c*c)<EPSILON)) printf("Pravougli\n");
	
	if((fabs(a-b)<EPSILON && fabs(a-c)>EPSILON) || (fabs(b-c)<EPSILON && fabs(a-c)>EPSILON) || (fabs(a-c)<EPSILON && fabs(a-b)>EPSILON)) {
			printf("Jednakokraki\n");
	}
	
	if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON) printf("Raznostranicni\n");
	
	
	
	
	return 0;
}
