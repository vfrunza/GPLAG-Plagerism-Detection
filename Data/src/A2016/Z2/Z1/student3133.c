#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int a, b=0, c, d, x=1;
	printf("Unesite broj: ");
	scanf("%d", &a);
	if(a<0) a=abs(a);
	do{
		c=a%10;
		d=(a/10)%10;
		b+=x*abs(c-d);
		a=a/10;
		if(a<10) break;
		x*=10;
	}
	while (a!=0);
	if(a<10&&d==0) printf("0");
	else printf("%d", b);
	return 0;
}
