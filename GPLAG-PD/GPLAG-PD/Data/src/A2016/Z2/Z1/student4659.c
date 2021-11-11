#include <stdio.h>
#include <math.h>
int main() {
    int n,a,b,c,broj=0,k=1;
    
	printf("Unesite broj: ");
	scanf("%d",&n);
    if(n<0) n=n*(-1);
		while(n>=10){
		a=n%10;
		
		b=(n/10)%10;
		c=a-b;
		if(c<0) c=c*(-1);
		broj+=(c*k);
		k*=10;
		n/=10;
        }

printf("%d",broj);
return 0; }
