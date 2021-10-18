#include <stdio.h>
#include <stdlib.h>

int main() {
int x;
int a,b,c=0, s=0, z=1;
printf ("Unesite broj: ");
scanf ("%d", &x);
   x= abs (x);
while (x > 10) {
a=x%10;
x=(x-a)/10;
b=x%10;


c=abs (a-b);

s=s+(z*c);
z=10*z;
}
printf ("%d", s);


	return 0;
}
