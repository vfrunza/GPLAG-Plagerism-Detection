#include <stdio.h>
#define ep 0.0001
#include <math.h>
#define PI 3.14159265359

int main() {
	
	
	int sekunde,minute,stepeni,ukupnosekundi,istina=1;
	double a,b,c,L,B,C,max,x1,x2,x3,y1,y2,y3;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	a=sqrt( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) );
	b=sqrt( (x2-x3) * (x2-x3) + (y2-y3) * (y2-y3) );
	c=sqrt( (x3-x1) * (x3-x1) + (y3-y1) * (y3-y1) );
	
	L=acos((b*b+c*c-a*a)/(2*b*c));
	B=acos((c*c+a*a-b*b)/(2*c*a));
	C=acos((a*a+b*b-c*c)/(2*a*b));
	
	if (L>B && L>C)
	{
		max=L;
	}
	else if(B>L && B>C)
	{
		max=B;
	}
	else
	{
		max=C;
	}
	max=max*(180/PI);
	if (fabs(max-90)<ep)
	{
		printf("Pravougli\n");
	}
	if (fabs(a-b)<ep && fabs(b-c)<ep)
	{
		printf("Jednakostranicni\n");
	}
	else if ((fabs((a+b)-c)<ep || fabs((a+c)-b)<ep || fabs((b+c)-a)<ep))
	{
		istina=0;
		printf("Linija\n");
	}
	else if (fabs(a-b)<ep && fabs(b-c)>ep || fabs(a-b)>ep && fabs(b-c)<ep || fabs(a-c)>ep && fabs(a-b)<ep)
	{
		printf("Jednakokraki\n");
	}
	else if((fabs(a-b)>ep) && (fabs(a-c)>ep) && (fabs(b-c)>ep))
	{
		printf("Raznostranicni\n");
	}
	max+=ep;
	ukupnosekundi=(max*60*60);
	sekunde=ukupnosekundi % 60;
	minute=(ukupnosekundi/60)%60;
	stepeni=ukupnosekundi / (60*60);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	
	
	return 0;
	
	
	
}
