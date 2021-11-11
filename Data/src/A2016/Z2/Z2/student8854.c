#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define eps 0.001
int main() {
	int b,c,e,x1,x2,t,q=1;
	double a[500];
	double v;
	printf("Unesite broj uglova: ");
	scanf("%d",&c);
	for (b=1;b<=c;b++)
	scanf("%lf",&a[b]);
	printf("Uglovi su:\n");
for (b=1;b<=c;b++)
{
    if(a[b]<0)
    {a[b]=-a[b];
    q=0;}
    else
    q=1;
   a[b]=180*a[b];
    a[b]=a[b]/PI;
    e=(int)(a[b]);
    x1=e;
	
	a[b]=60*(a[b]-e);
	e=(int)(a[b]);
	x2=abs(e);
	
	a[b]=60*(a[b]-e);
	v=a[b];
	
	e=(int)(a[b]+0.5);
	
	if(e==60)
	{e=0;
	if(x2==59)
	{x2=0;
	x1++;}
	else
	x2++;}
	
	
	if(e>30)
	{for(t=b;t<c;t++)
	{
		a[t]=a[t+1];
	}
	c--;
	}
	if(fabs(a[b]-v)>eps)
	{b--;
	continue;}
	else
	{
	



if(e<31){
	if(q==0)
	{printf("%d stepeni ",-x1);
	printf("%d minuta ",x2);
	printf("%d sekundi \n",e);}
	else
	{printf("%d stepeni ",x1);
	printf("%d minuta ",x2);
	printf("%d sekundi \n",e);}
	}}
}
	return 0;
}
