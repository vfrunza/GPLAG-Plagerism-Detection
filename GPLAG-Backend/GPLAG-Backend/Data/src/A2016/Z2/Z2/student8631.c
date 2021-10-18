#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#define PI 3.1415926
int main() {
 int n, i,j, step, min, sec;
double mat[500], x;
do 
{printf("Unesite broj uglova: ");
scanf("%d", &n);
	if(n<0 && n>500)
	printf("Neispravan unos: ");
}
while (n<1 || n>500);
for(i=0; i<n; i++){
scanf("%lf", &mat[i]);} printf("Uglovi su:"); 
for(i=0; i<n; i++)
{ x=(((mat[i])*180)/PI*3600);
if (x>=0) {
x=(int)(x+0.5);
step=x/3600;
min=(fabs(x)-abs(step)*3600)/60;
sec=(fabs(x)-abs(step)*3600-abs(min)*60); 
if(sec>=60) {min++; sec-=60;}
if(min>=60) {step++; min-=60;}
if(sec>30) {for(j=0; j<n-1; j++) { mat[j]=mat[j+1];}  n--;i--; }}

else  
{ x=(int)(fabs(x)+0.5);
step=-x/3600;
min=(fabs(x)-abs(step))*3600/60;
sec=(fabs(x)-abs(step)*3600-abs(min)*60);
if(sec>=60) { min++; sec-=60;}
if(min>=60) { step++; min-=60;}
else printf("\n%d stepeni %d minuta %d sekundi", step, abs(min), abs(sec));
}}
return 0; }







