#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,br=0,broj=0,broj1,broj2,i=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0){
		n=abs(n);
	}
	if(n>=0 && n<10){
		broj=0;
		printf("%d",broj);
    	return 0;

	}
	 while (n>9){
		broj1 = n % 10;
		n=n/10;
		broj2=n% 10;
		br=abs((broj1-broj2))* pow(10,i);
		broj=broj+br;
		i++;
	}
	printf("%d", broj);
	return 0;
}
