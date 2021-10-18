#include <stdio.h>
#include <math.h>
#define PI 3.14159265359


int main() {
/*	printf("Zadaća 1, Zadatak 2");*/
double x1, y1, x2, y2, x3, y3, a, b, c, P, s, alfa=0, beta=0, gama=0, max, stepeni, minute, sekunde;
double EPSILON = 0.0001;

printf("Unesite koordinate tacke t1: ");
scanf("%lf %lf", &x1, &y1);

printf("Unesite koordinate tacke t2: ");
scanf("%lf %lf", &x2, &y2);

printf("Unesite koordinate tacke t3: ");
scanf("%lf %lf", &x3, &y3);


a=sqrt(pow((x1-x2),2) + pow((y1-y2),2)); 
b=sqrt(pow((x1-x3),2) + pow((y1-y3),2)); 
c=sqrt(pow((x2-x3),2) + pow((y2-y3),2)); 
s=(a+b+c)/2;
P=sqrt(s*(s-a)*(s-b)*(s-c));

if (P<EPSILON)
{
 printf("Linija\n");
}
else {
 if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON)
 {
  printf("Jednakostranicni\n");
 }
 if((fabs(a*a-(b*b+c*c))<EPSILON) || (fabs(b*b-(a*a+c*c))<EPSILON) || (fabs(c*c-(b*b+a*a))<EPSILON))
 {
  printf("Pravougli\n");
 }
 if (fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON)
 {
  printf("Raznostranicni\n");
 }
 
 if((fabs(a-b)>EPSILON && fabs(a-c)<EPSILON) || (fabs(a-c)>EPSILON && fabs(a-b)<EPSILON) || (fabs(b-c)>EPSILON && fabs(a-b)<EPSILON))
 {
  printf("Jednakokraki\n");
 }

}

alfa=acos((a*a + c*c - b*b)/(2*a*c));
beta=acos((a*a + b*b - c*c)/(2*a*b));
gama=acos((b*b + c*c - a*a)/(2*b*c));

max = alfa;
if(beta > max) max = beta;
if(gama > max) max = gama;

max=max*180/PI;
if(fabs(max-ceil(max))<EPSILON) max = ceil(max);

stepeni = floor(max);
minute=floor((max-stepeni)*60);
sekunde=floor((max-stepeni-minute/60)*3600);
printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepeni, minute, sekunde);

return 0;
}
