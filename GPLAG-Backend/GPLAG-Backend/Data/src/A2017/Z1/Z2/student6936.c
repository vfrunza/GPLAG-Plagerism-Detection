#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define EPSILON 0.00001

int main() {
	double x1, y1, x2, y2, x3, y3;
	double povrsina;
	double a, b, c;
	double najveca;
	double ugao1=0,ugao2=0,ugao3=0;
	int stepeni,sekunde,minute;
	int usekunde;
	
printf ("Unesite koordinate tacke t1: ");
scanf ("%lf %lf", &x1, &y1);
printf ("Unesite koordinate tacke t2: ");
scanf ("%lf %lf", &x2, &y2);
printf ("Unesite koordinate tacke t3: ");
scanf ("%lf %lf", &x3, &y3);
povrsina=(1./2)*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
if (fabs(povrsina-0)<EPSILON) {
	printf ("Linija\n"); goto linijaugao; }
a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
//jednakostranican
if (fabs (a-b)<EPSILON && fabs (a-c)<EPSILON && fabs (b-c)<EPSILON) {
	printf ("Jednakostranicni\n"); goto ugao;}
//pravougli
if (a>=b && a>=c) {
	najveca=a;
}
if (b>=a && b>=c) {
	najveca=b;
}
if (c>=a && c>=b) {
	najveca=c;
}
if (fabs(najveca-sqrt(a*a+b*b))<EPSILON) {
	printf ("Pravougli\n");
}
//raznostranican
if (fabs (a-b)>EPSILON && fabs (a-c)>EPSILON && fabs (b-c)>EPSILON) {
	printf ("Raznostranicni\n"); goto ugao;
}
if ((fabs (a-b)<EPSILON && fabs (a-c)>EPSILON)|| (fabs (a-c)<EPSILON && fabs (a-b)>EPSILON) || (fabs (b-c)<EPSILON && fabs (b-a)>EPSILON)) {
	printf ("Jednakokraki\n"); goto ugao;
}
linijaugao:
{printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi."); return 0; }
ugao:
ugao1=acos((a*a+c*c-b*b)/(2*a*c));
ugao2=acos((b*b+c*c-a*a)/(2*b*c));
ugao3=acos((a*a+b*b-c*c)/(2*a*b));
if(ugao1>=ugao2 && ugao1>=ugao3)
{usekunde=round(((ugao1*360*60*60)/(2*3.141592653589793238462643383279502884197169399375105820974944592307816406286))-0.5);
sekunde=usekunde%60;
minute=(usekunde/60)%60;
stepeni=usekunde/(60*60);
printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
}
if(ugao2>=ugao1 && ugao2>=ugao3)
{usekunde=round(((ugao2*360*60*60)/(2*3.141592653589793238462643383279502884197169399375105820974944592307816406286))-0.5);
sekunde=usekunde%60;
minute=(usekunde/60)%60;
stepeni=usekunde/(60*60);
printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
}
if(ugao3>=ugao1 && ugao3>=ugao2)
{usekunde=round(((ugao3*360*60*60)/(2*3.141592653589793238462643383279502884197169399375105820974944592307816406286))-0.5);
sekunde=usekunde%60;
minute=(usekunde/60)%60;
stepeni=usekunde/(60*60);
printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
}
	
	return 0;
}
