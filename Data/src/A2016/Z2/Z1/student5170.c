#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int n,a,b,c,d,f=0,g=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if (n<0) {n=-n;}
	if (abs(n)<10 && abs(n)>=0) {printf("0");}
else {
	while (n!=0) {
		a=n%10;
		if ((n/10)<1) break;
		n=n/10;
		b=n%10;
		c=abs(a-b);
	d=c*(pow(10,g));
	f=f+d;
	g++;
	}
		printf("%d", f); }
	return 0;
}
