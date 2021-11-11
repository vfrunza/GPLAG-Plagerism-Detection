#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main() 
{
double stp=0,min=0,sek=0;
double a[500];
double st[500];
double m[500];
double s[500];
int n=0,i=0,j=0,x=0; 
do 
{  printf("Unesite broj uglova: ");
   scanf("%d", &n);  } 
while (n<0 || n>500);
for (i=0; i<n ; i++)
{  scanf ("%lf", &a[i]); 
    stp=a[i]*180/PI;
    min=(stp-(int)(stp))*60;
    sek=(min-(int)(min))*60;
if (fabs(sek)>30.5 && (fabs)(sek)<59.5)
    { 
    for (j=i;j<n-1;j++)
    {
    a[j]=a[j+1];}
    n--;
    i--;}
   else 
   { 
if (stp>0)
    {
    stp=(floor)(stp);
    }
   else 
    {
    stp=(ceil)(stp);
    }
if (min>0)
    {
        min=(floor)(min);
    }
   else
   {
   min=fabs((ceil)(min));
   }
   sek=fabs((round)(sek));
if ((abs)(sek)==60 && (abs)(min)==59)
   {
    sek=0;
    min=0;
    if (stp>0)
   {stp++;}
   else 
   {stp--;}}
   else if (fabs(sek==60))
   {
    sek=0;
    if (min>0)
    {min++;}
    else
    {min--;}}
st[i]=stp;
m[i]=min;
s[i]=sek;}}
printf ("Uglovi su:\n");
for (x=0;x<n;x++)
{
    if (a[x]>0 || a[x]<0)
    {
        printf ("%.lf stepeni %.lf minuta %.lf sekundi\n",st[x],m[x],s[x]);
    }
    else if (a[x]==0)
    {
    printf ("0 stepeni 0 minuta 0 sekundi\n");
    }}
return 0;}
