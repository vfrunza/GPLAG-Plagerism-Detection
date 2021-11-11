#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int x, c, br, a;
	int i=0;
	int zb=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	x=abs(x);
	c=x%10;
	if(x==0) printf ("0");
	else {
		do {
			x=x/10;
			zb=abs(c-x%10)*pow(10, i)+zb;
			c=x%10;
			i++;
		}
		while (x!=0);
		a=pow(10, i-1);
		br=zb%a;
		printf("%d", br);
	}
	return 0;
}
