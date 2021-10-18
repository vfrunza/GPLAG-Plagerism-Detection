#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
	int n,a,broj,tk=1,b=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	a=n/10;
	while(a!=0){
		broj=abs(n%10-a%10);
		b=tk*broj+b;
		n/=10;
		tk*=10;
		a/=10;
	}
	printf("%d",b);
	
	return 0;
}
