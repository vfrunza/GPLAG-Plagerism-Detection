#include <stdio.h>
#include <math.h>
#define P 0.0001

int main()
{
float x1, y1, x2, y2, x3, y3, a1, b1, c1, A, B, C, z, t, g, h, p, q, r, s, a, b, c, d;
	printf("Unesite koordinate tacke t1: ");
	scanf ("%f %f", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf ("%f %f", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf ("%f %f", &x3, &y3);
	a1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b1=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c1=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	if((fabs(a1+b1-c1)<=P)||(fabs(a1+c1-b1)<=P)||(fabs(c1+b1-a1)<=P)) 
	{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
		
	}
   if((fabs(a1*a1-b1*b1-c1*c1)<=P)||(fabs(b1*b1-c1*c1-a1*a1)<=P)||(fabs(c1*c1-b1*b1-a1*a1)<=P))
    
		printf("Pravougli\n");
		
   if((fabs(a1-b1)>P)&&(fabs(b1-c1)>P)&&(fabs(c1-a1)>P))
	
		printf("Raznostranicni\n");
		
   if((fabs(a1-b1)<=P)&&(fabs(b1-c1)<=P)) 
		
		printf("Jednakostranicni\n");
	
   if(((fabs(a1-b1)<=P)&&(fabs(b1-c1)>P))||((fabs(a1-c1)<=P)&&(fabs(c1-b1)>P))||((fabs(c1-b1)<=P)&&(fabs(b1-a1)>P)))
	
		printf("Jednakokraki\n");
				
	A=acos((b1*b1+c1*c1-a1*a1)/(2*b1*c1));
	A=(180*A)/(4*atan(1));
	z=A-(int)A;
	t=z*60;
	g=t-(int)t;
	h=g*60;
	
	B=acos((a1*a1+c1*c1-b1*b1)/(2*a1*c1));
	B=(180*B)/(4*atan(1));
	p=B-(int)B;
	q=p*60;
	r=q-(int)q;
	s=r*60;
	
	C=acos((a1*a1+b1*b1-c1*c1)/(2*a1*b1));
	C=(180*C)/(4*atan(1));
	a=C-(int)C;
	b=a*60;
	c=b-(int)b;
	d=c*60;
	
	if(((a1>=b1)&&(b1>=c1))||((a1>=c1)&&(c1>=b1)))
				printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)A, (int)t, (int)h);
			else if(((b1>=a1)&&(a1>=c1))||((b1>=c1)&&(c1>=a1)))
				printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)B, (int)q, (int)s);
			else if(((c1>=b1)&&(b1>=a1))||((c1>=a1)&&(a1>=b1)))
				 printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)C, (int)b, (int)d);
				
	return 0;
}
