#include <stdio.h>
#include <math.h>
#define PI 3.14159265359
int main() {

int stepen, minute, sekunde;
double alfa,beta,gama;
double t1, t2, t3,max;
double x1,x2,x3,y1,y2,y3;
double a,b,c;

printf("Unesite kordinate tacke t1: ");
scanf("%lf %lf", &x1, &y1);

printf("Unesite kordinate tacke t2: ");
scanf("%lf %lf", &x2, &y2);

printf("Unesite kordinate tacke t3: ");
scanf("%lf %lf", &x3, &y3);

t1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
t2=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
t3=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);

a=sqrt(t1);
b=sqrt(t2);
c=sqrt(t3);

if(a==b && a==c && b==c) printf("Jednakostranicni\n");
else if(a!=b && a!=c && b!=c) printf("Raznostranicni\n");
else if (a==b || b==c || a==b) printf("Jednakokraki\n");
else printf("Nije trougao\n");

alfa=acos((b*b+c*c-a*a)/2*b*c);
beta=acos((a*a+c*c-b*b)/2*a*c);
gama=acos((b*b+a*a-c*c)/2*b*a);

alfa=alfa*(180/PI);
beta=beta*(180/PI);
gama=gama*(180/PI);


if(alfa>beta && alfa>gama) max=alfa; //printf("Najveci ugao ima %d stepeni %d minuta %d sekundi", stepen, minute, sekunde); }
if(beta>alfa && beta>gama) max=beta; //printf("Najveci ugao ima %d stepeni %d minuta %d sekundi", stepen, minute, sekunde); }
else  max=gama;//printf("Najveci ugao ima %d stepeni %d minuta %d sekundi", stepen, minute, sekunde); 


stepen=(int)max;
minute=(int)((max-stepen)*3600)/60;
sekunde=(int)((max-stepen)*3600)%60;

printf("%lf %d %d %d",max, stepen, minute, sekunde);

return 0;
}
