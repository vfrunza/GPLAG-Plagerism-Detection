#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
int a,b,c,razlika,f,g;
f=0;
g=1;
printf ("Unesite broj: ");
scanf ("%d",&a);

if (a<0) {a=(-a);}
if (a<10)
{ a=0;
printf ("%d",a); return 0;}
else
{ while (a>9)
    {
b=a%10;
a=a/10; 
c=a%10;
razlika= abs(b-c);
f=f+razlika*g;
g=g*10;
    }} printf ("%d", f);


	return 0;
}
