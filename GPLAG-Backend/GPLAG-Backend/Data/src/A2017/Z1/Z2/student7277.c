#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.14159265359

int main()
{
	double a, b, c, P, x1, x2, y1, y2, x3, y3, X, Y, Z, max=0, pretvaranje, sec1, m1;
	int st, m, sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	P=(1./2)*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	
	if (fabs(P-0) < eps)
	{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
		return 0;
	}
		
	if(fabs(a-b)<=eps && fabs(b-c)<=eps && fabs(a-c)<=eps)
	{
		printf("Jednakostranicni\n");
	}
	
	else if(fabs(a-b)<eps || fabs(b-c)<eps || fabs(a-c)<eps)
	{
			if(fabs((a*a+b*b)-c*c)<=eps || fabs((b*b+c*c)-a*a)<=eps || fabs((a*a+c*c)-b*b)<=eps)
	{
		
		printf("Pravougli\n");
	}
		printf("Jednakokraki\n");
	}
		
	else if(!(fabs(a-b)<=eps) && !(fabs(b-c)<=eps) && !(fabs(a-c)<=eps))
	{
			if(fabs((a*a+b*b)-c*c)<=eps || fabs((b*b+c*c)-a*a)<=eps || fabs((a*a+c*c)-b*b)<=eps)
	{
		
		printf("Pravougli\n");
	}
	printf("Raznostranicni\n");
	}
	
	X=acos((b*b+c*c-a*a)/(2*b*c));
	Y=acos((a*a+c*c-b*b)/(2*a*c));
	Z=acos((a*a+b*b-c*c)/(2*a*b));
	
	if(X>Y && X>Z)
	max=X;
	else if(Y>X && Y>Z)
	max=Y;
	else if(Z>X && Z>Y)
	max=Z;
	
	pretvaranje=max*(180./PI);
	st=pretvaranje;
	m1=(pretvaranje-st)*60;
	if(fabs(m1-60)<=eps)
	{
		st=st+1;
		m1=0;
	}
	m=m1;
	
	sec1=(m1-m)*60;
	
	if(fabs(sec1-60)<=eps)
	{
		m=m+1;
		sec1=0;
	}
	sec=sec1;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st, m, sec);

return 0;
}
