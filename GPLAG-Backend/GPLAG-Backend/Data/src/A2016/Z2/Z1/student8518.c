#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main ()
{
    double z=0;
	int x,c,d,y,n=0,m;
	printf("Unesite broj: ");
	scanf("%d",&x);
    if(x<0){
	x=abs(x);}
	c=x%10;
	x=x/10;
	while(x!=0){
	    d=x%10;
	    y=abs(c-d);
	    c=d;
	    z=z+y;
	    z=0.1*z;
	    n++;
	    x=x/10;
	    
	}
	z=round(z*pow(10,n));
	m=z;
	printf("%d",m);
	    return 0;
}