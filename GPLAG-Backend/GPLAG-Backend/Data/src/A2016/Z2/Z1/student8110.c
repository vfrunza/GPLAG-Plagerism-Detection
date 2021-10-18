#include <stdio.h>
#include <math.h>
int main() {
	int x,y,z,a,k=0,n=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	x=fabs(x);
	y=x%10;
	x=x/10;
	while (x!=0) {
	    z=x%10;
	    a=fabs(y-z);
	    k=pow(10,n)*a+k;
	    n++;
	    y=z;
	    x=x/10;
	}
	    printf("%d", k);
	return 0;
}
	
