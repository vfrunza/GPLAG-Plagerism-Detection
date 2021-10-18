#include <stdio.h>
#include <math.h>
int main() {
int a,n,rez=0,c,v=0,r=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n=fabs(n);
	a=n;
	 while (a > 10)
   {
   	  a=a/10;
      r=r*10;
   }
   while (r>1){
    	c=n/r;
    	n=n-(n/r)*r;
    	r=r/10;
    	v=n/r;
    	rez+=(fabs(c-v)*r);
    }
     printf("%d",rez);
	return 0;
}