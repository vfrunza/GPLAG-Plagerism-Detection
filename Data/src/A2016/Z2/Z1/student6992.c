#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, x=0, a, b, o=0, c, control=0, i=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)
	n=abs(n);
	while(n>0) {
	a=n%10;
	n/=10;
	b=n%10;
	x+=abs(a-b);
	x*=10;
	if(abs(a-b)==0 && i==0)
		control=1;
	i++;
	
	}
	x/=100;
	
	while(x>0) {
		c=x%10;
		o+=c;
		o*=10;
		x/=10;
		
		
	}
	o/=10;
	if(control)
		o*=10;
	printf("%d", o);
	
	return 0;
}
