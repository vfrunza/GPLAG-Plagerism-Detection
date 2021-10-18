#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, x, y, broj=0, k=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0){
		n=abs(n);
	}
	if(n%10==n){
		printf("0");
		return 0;
	}

	while(n>=10){
		x =n%10;
		n/=10;
		y=n%10;
		broj+=abs(x-y)*k;
		k=k*10;
	}
	printf("%d", broj);

	return 0;
}
