#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI  3.141592653589793

int main() {
	double a,b,c,x1,x2,x3,y1,y2,y3,AB,BC,CA,maxug;
	int st=0,min=0,sek=0;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf,%lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf,%lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf,%lf", &x3,&y3);
	
	BC=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	CA=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	AB=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	
	a=acos((CA*CA+AB*AB-BC*BC)/(2*CA*AB))*(180/PI);
	b=acos((BC*BC+AB*AB-CA*CA)/(2*BC*AB))*(180/PI);
	c=acos((BC*BC+CA*CA-AB*AB)/(2*BC*CA))*(180/PI);
	
	if(a>b && a>c) maxug=a;
	else if(b>a && b>c) maxug=b;
	else maxug=c;
	
	if(fabs(a-90)<eps || fabs(b-90)<eps || fabs(c-90)<eps)
	printf("Pravougli\n");
	
	if(fabs(a-180)<eps || fabs(b-180)<eps || fabs(c-180)<eps)
	printf("Linija\n");
    else
	if(fabs(BC-CA)<eps && fabs(CA-AB)<eps && fabs(BC-AB)<eps)
	printf("Jednakostranicni\n");
	else
	if(fabs(BC-CA)<eps || fabs(CA-AB)<eps || fabs(BC-AB)<eps)
	printf("Jednakokraki\n");
	else
	printf("Raznostranicni\n");
	
	
	st=(int)maxug;
	maxug-=st;
	maxug*=60;
	min=(int)maxug;
	maxug-=min;
	maxug*=60;
	sek=(int)maxug;
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st,min,sek);
	
	
	
	
	return 0;
}
