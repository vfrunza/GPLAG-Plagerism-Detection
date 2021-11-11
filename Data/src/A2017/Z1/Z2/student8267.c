#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592653
int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,A,B,C;
	int stepA=0,minA=0,sekA=0,stepB=0,minB=0,sekB=0,stepC=0,minC=0,sekC=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	b=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	c=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
 A=(acos((c*c+b*b-a*a)/(2*b*c)))*(180/PI);
 B=(acos((c*c+a*a-b*b)/(2*a*c)))*(180/PI);
 C=(acos((a*a+b*b-c*c)/(2*b*a)))*(180/PI);
  if(fabs(A-90)<EPSILON||fabs(B-90)<EPSILON||fabs(C-90)<EPSILON)
   printf("Pravougli\n");
  if(fabs(a-b)<EPSILON&&fabs(a-c)<EPSILON&&fabs(b-c)<EPSILON)
	  printf("Jednakostranicni\n");
	 else if(fabs(A-180)<EPSILON||fabs(B-180)<EPSILON||fabs(C-180)<EPSILON)
   printf("Linija\n");
 	else if(fabs(a-b)<EPSILON||fabs(a-c)<EPSILON||fabs(b-c)<EPSILON)
	  printf("Jednakokraki\n");
 	else if(fabs(a-b)>=EPSILON&&fabs(a-c)>=EPSILON&&fabs(b-c)>=EPSILON)
   printf("Raznostranicni\n");

if(A>B&&A>C)
    {
     stepA=(int)A;
     A-=stepA;
     A*=60;
     minA=(int)A;
     A-=minA;
     A*=60;
     sekA=(int)A;
     printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",stepA,minA,sekA);
    }
else if(B>A&&B>C)
    {
     stepB=(int)B;
     B-=stepB;
     B*=60;
     minB=(int)B;
     B-=minB;
     B*=60;
     sekB=(int)B;
     printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",stepB,minB,sekB);
    }
else if(C>B&&C>A)
    {
     stepC=(int)C;
     C-=stepC;
     C*=60;
     minC=(int)C;
     C-=minC;
     C*=60;
     sekC=(int)C;
     printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",stepC,minC,sekC);
    }
	return 0;
}
