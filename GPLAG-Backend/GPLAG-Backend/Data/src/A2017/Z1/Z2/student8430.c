#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 0.0001
#define PI (4*atan(1))
int main() {
	double t1x,t1y,t2x,t2y,t3x,t3y,a,b,c,A,B,C,max,P,S;
	int step,min,sek,linija=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&t1x,&t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&t2x,&t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&t3x,&t3y);
	a=sqrt((t3x-t2x)*(t3x-t2x)+(t3y-t2y)*(t3y-t2y));
	b=sqrt((t3x-t1x)*(t3x-t1x)+(t3y-t1y)*(t3y-t1y));
	c=sqrt((t2x-t1x)*(t2x-t1x)+(t2y-t1y)*(t2y-t1y));

S=(a+b+c)/2;
P=sqrt(S*fabs(S-a)*fabs(S-b)*fabs(S-c));
	if(P<eps){
		printf("Linija\n");
		linija=1;
	}
	else if(fabs(a-b)<eps && fabs(a-c)<eps && fabs(c-b)<eps)
	printf("Jednakostranicni\n");
	else if(fabs(a*a+b*b-c*c)<eps || fabs(a*a+c*c-b*b)<eps || fabs(b*b+c*c-a*a)<eps){
		printf("Pravougli\n");
		if((fabs(a-b)<eps && fabs(c-b)>eps) || (fabs(a-c)<eps && fabs(a-b)>eps) || (fabs(c-b)<eps && fabs(c-a)>eps))
		printf("Jednakokraki\n");
		else 
		printf("Raznostranicni\n");
	}
	else if((fabs(a-b)<eps && fabs(c-b)>eps) || (fabs(a-c)<eps && fabs(a-b)>eps) || (fabs(c-b)<eps && fabs(c-a)>eps))
		printf("Jednakokraki\n");
	else
	printf("Raznostranicni\n");
	
	A=acos((a*a-b*b-c*c)/-(2*b*c))*180/PI;
	B=acos((b*b-a*a-c*c)/-(2*a*c))*180/PI;
	C=acos((c*c-a*a-b*b)/-(2*a*b))*180/PI;
	if(A>B && A>C)
	max=A;
	else if(B>A && B>C)
	max=B;
	else max=C;
	step=(int) (max+eps);
	min=(int)((max-step)*60);
	sek=(int)(((max-step)*60-min)*60);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sek);
	
	return 0;
}
