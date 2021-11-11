#include <stdio.h>
#include <math.h>

int main() {
	long long int a,b=0,c=0,d=0,e=1,f=0,i=0,h,j;
	printf("Unesite broj: ");
	scanf("%lld",&h);
	a=fabs(h);
	do
	{
	 i++;
	 b=a%10;
	 a=a/10;
	 if (a==0) break;
	 c=a%10;
	 d=fabs(b-c);
	 for(j=0;j<i;j++)
	 {
	 	e=e*10;
	 }
	 i=0;
	 f=f+e*d;
	 }
    while(a!=0);
    f=f/10;
    printf("%lld\n",f);
    
	return 0;
}
