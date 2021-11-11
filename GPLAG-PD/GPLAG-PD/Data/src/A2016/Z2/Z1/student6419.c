#include <stdio.h>
#include <math.h>
int main () {
	int a, b=0, temp1=0, temp2=0, n=0, p=1, t=0;
	printf("Unesite broj: ");
	scanf("%d", &a);
	if(a<0) 
		a=fabs(a);
	while(a>10) {
		temp1=a%10;
		a/=10;
		b=a;
		temp2=b%10;
		n=p*(temp1-temp2);
		if(n<0)
			n=fabs(n);
		p*=10;
		t+=n;
	}
	printf("%d", t);
	return 0;
}