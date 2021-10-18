#include <stdio.h>
#include <math.h>
#define pi 3.14159265359
#define epsilon 0.0001
int main()
{
double t1,t11,t2,t22,t3,t33;
double a,b,c,A,B,C,max;
int ist=1,sekunde,minute,stepeni,usekunde;
printf("Unesite koordinate tacke t1: ");
scanf("%lf %lf",&t1,&t11);
printf("Unesite koordinate tacke t2: ");
scanf("%lf %lf",&t2,&t22);
printf("Unesite koordinate tacke t3: ");
scanf("%lf %lf",&t3,&t33);
a=sqrt((t1-t2)*(t1-t2)+(t11-t22)*(t11-t22));
b=sqrt((t2-t3)*(t2-t3)+(t22-t33)*(t22-t33));
c=sqrt((t3-t1)*(t3-t1)+(t33-t11)*(t33-t11));
A=acos((b*b+c*c-a*a)/(2*b*c));
B=acos((c*c+a*a-b*b)/(2*c*a));
C=acos((a*a+b*b-c*c)/(2*a*b));
if (A>B && A>C)
{
	max=A;
}
else if (B>A && B>C)
{
	max=B;
}
else 
{
	max=C;
}
max=max*(180/pi);
if (fabs(max-90)<epsilon)
{
	printf("Pravougli\n");
}
if (fabs(a-b)<epsilon && fabs(b-c)<epsilon)
{
	printf("Jednakostranicni\n");
}
else if ((fabs((a+b)-c)<epsilon) || (fabs((a+c)-b)<epsilon) || (fabs((b+c)-a)<epsilon))
{
	ist=0;
	printf("Linija\n");
}
else if (fabs(a-b)<epsilon && fabs(b-c)>epsilon || fabs(a-b)>epsilon && fabs(b-c)<epsilon || fabs(a-c)<epsilon && fabs(a-b)>epsilon)
{
	printf("Jednakokraki\n");

}
else if ((fabs(a-b)>epsilon) && (fabs(a-c)>epsilon) && (fabs(b-c)>epsilon))
{
	printf("Raznostranicni\n");
}
max+=epsilon;
usekunde=max*60*60;
sekunde=usekunde % 60;
minute=(usekunde/60) % 60;
stepeni=usekunde/(60*60);
printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);








	return 0;
}
