#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, c1, c2, broj=0, proizvod=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	for(;;) {
		c1=n%10;
		n/=10;
		if(n==0)
		  break;
		c2=n%10;
		broj+=abs(c1-c2)*proizvod;
		proizvod*=10;
	}
	printf("%d", broj);
	return 0;
}
