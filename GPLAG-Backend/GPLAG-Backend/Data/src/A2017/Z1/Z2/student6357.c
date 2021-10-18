#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define EPSILON 0.0001
int main() {
double x1,y1,x2,y2,x3,y3,najveci=0,a=0,b=0,c=0,alfa=0,beta=0,gama=0,temp=0;
int stepeni=0,minute=0,sekunde=0;
printf("Unesite koordinate tacke t1: ");
scanf("%lf %lf",&x1,&y1);
printf("Unesite koordinate tacke t2: ");
scanf("%lf %lf",&x2,&y2);
printf("Unesite koordinate tacke t3: ");
scanf("%lf %lf",&x3,&y3);
a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
alfa=acos((b*b+c*c-a*a)/(2*b*c));
beta=acos((a*a+c*c-b*b)/(2*a*c));
gama=acos((a*a+b*b-c*c)/(2*a*b));
if((alfa-beta)<=EPSILON && (alfa-gama)<=EPSILON && (beta-gama)<=EPSILON) najveci=alfa;
if((alfa-beta)>=EPSILON && (alfa-gama)>=EPSILON) najveci=alfa;
else if((beta-alfa)>=EPSILON && (beta-gama)>=EPSILON) najveci=beta;
else if((gama-alfa)>=EPSILON && (gama-beta)>=EPSILON) najveci=gama;
else if((alfa-beta)<=EPSILON && (alfa-gama)>EPSILON) najveci=alfa;
else if((alfa-gama)<=EPSILON && (alfa-beta)>EPSILON) najveci=gama;
najveci*=(180./PI);
stepeni=(int)(najveci);
najveci-=stepeni;
temp=najveci*60;
minute=(int)(temp);
najveci=temp-minute;
sekunde=najveci*60;
if(stepeni==90) printf("Pravougli\n");
if(stepeni==180) printf("Linija\n");
else if(fabs(a-b)<=EPSILON && fabs(a-c)<=EPSILON && fabs(b-c)<=EPSILON) printf("Jednakostranicni\n");
else if(fabs(a-b)<=EPSILON || fabs(a-c)<=EPSILON || fabs(b-c)<=EPSILON) printf("Jednakokraki\n");
else if(fabs(a-b)>EPSILON && fabs(a-c)>EPSILON && fabs(b-c)>EPSILON) printf("Raznostranicni\n");
printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	return 0;
}
