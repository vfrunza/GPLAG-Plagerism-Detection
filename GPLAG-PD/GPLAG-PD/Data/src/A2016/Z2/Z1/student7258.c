#include <stdio.h>
#include <stdlib.h>
int main() {
	int a,c1,c2,k,b=0;
	printf("Unesite broj: ");
	scanf("%d",&a);
	if (a<0) a=abs(a);
	k=1;
	while (a>=10) {
		c1=a%10;
		c2=(a/10)%10;
		b+=abs(c1-c2)*k;
		k*=10;
		a/=10;
	}
	printf("%d",b);
	return 0;
}
