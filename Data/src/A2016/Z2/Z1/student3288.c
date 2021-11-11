#include <stdio.h>
#include <math.h>

int main() {
	int n,x,a,b,rez=0,c=1;
    printf("Unesite broj: ");
    scanf("%d", &n);
    	while(n>=10 || n<=-10) {
    	    a=n%10;
    	    b=n%100;
    	    b=b/10;
    	    x=fabs(a-b)*c; c*=10;
    	    rez=rez+x;
    	    n=n/10;
    	    }
    printf("%d",rez);
	return 0;
}
