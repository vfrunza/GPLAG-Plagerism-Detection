#include <stdio.h>
#include <stdlib.h>
int main() 
{
int n,n1=0,k=1,ost,ost1;
printf("Unesite broj: ");
scanf("%d",&n);
while(n<0)
{
n=abs(n);
break;
}
{
if(n<10)
{
printf("0");
return 0;
}
}
while(1==1)
{
ost=n%10;
n=n/10;
ost1=n%10;
n1=n1+abs(ost1-ost)*k;
if(n<10)
{
break;
}
k=k*10;
}
printf("%d",n1);
return 0;
}
