#include <stdio.h>
#include <math.h>
int main() {
float x1,x2,x3,y1,y2,y3,a,b,c,a2,b2,c2;
double u1,u2,u3,u,uf;
int g,m,s,ts;
int br=1;
double mf;
double eps=0.0001;
printf("Unesite koordinate tacke t1: ");
scanf("%f",&x1);
scanf("%f",&y1);
printf("Unesite koordinate tacke t2: ");
scanf("%f",&x2);
scanf("%f",&y2);
printf("Unesite koordinate tacke t3: ");
scanf("%f",&x3);
scanf("%f",&y3);
a=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
b=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
c=sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
a2=a*a;
b2=b*b;
c2=c*c;
u1=(b2+c2-a2)/(2*b*c);
u1=acos(u1);
u2=(c2+a2-b2)/(2*c*a);
u2=acos(u2);
u3=(a2+b2-c2)/(2*a*b);
u3=acos(u3);
u=u1;
	if(u1>u2 && u1>u3)
	{
		u=u1;
	}
	else if(u2>u1 && u2>u3)
	{
		u=u2;
	}
	else if(u3>u1 && u3>u2)
	{
		u=u3;
	}
	
	ts=floor((u*360*60*60)/(2*3.141592));
	s=ts%60;
	m=(ts/60)%60;
	g=ts/(60*60);
	if((x1==x2 && x2==x3 && x3==x1)||(y1==y2 && y2==y3 && y3==y1)||g==180)
{
    printf("Linija \n");
    printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    return 1;
}
if(g==90)
	{
		printf("Pravougli \n");
	}
if(fabs(a-b)<=eps)
{
    br=br+1;
}
if(fabs(b-c)<=eps)
{
    br=br+1;
}
if(fabs(c-a)<=eps)
{
    br=br+1;
}
if(br==2)
{
    printf("Jednakokraki \n");
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",g,m,s);
    return 0;
}
if(fabs(a-b)<=eps && fabs(b-c)<=eps && fabs(c-a)<=eps)
{
    printf("Jednakostranicni \n");
    printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
    return 0;
}
if(br==1)
{
    printf("Raznostranicni \n");
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",g,m,s);
    return 0;
}
return 0;
}
