#include <stdio.h>
#include <math.h>
int main (){
int n,b1=0,b2=1,x=0,y=0,a;
printf("Unesite broj: ");
scanf("%d",&n);
if (n<0) n=-1*n;
if(fabs(n)>=0 && fabs(n)<10) printf("0");
else { 
	a=n;
 while(a>0){
 	a/=10;
 	b1++; }
 while(n/10>0) 
    { x=fabs(n%10-((n/10)%10));
      if(b2<b1)
      y+=pow(10,b2-1)*x;
      n/=10;
      b2++;}
printf("%d",y);}
return 0;
}