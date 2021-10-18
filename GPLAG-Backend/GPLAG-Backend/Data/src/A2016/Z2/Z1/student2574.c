#include <stdio.h>
#include <math.h>
int main()
{
int broj=0;
int x=0,y=0,z=0,k=0,c=0;
printf ("Unesite broj: ");
scanf ("%d",&broj);
broj=fabs(broj);
if (broj<10)
{
printf ("0");
return 0;
}
do
{
x=broj%10;
broj=broj/10;
y=broj%10;
z=fabs(x-y);
k=k+z*pow(10,c);
c=c+1;
}
while (broj>10);
printf ("%d",k);
return 0;
}
