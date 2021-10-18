#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, x, k;
	k=1;
	x=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	while(n<-9 || n>9){
		x=x+abs(n%10-(n/10)%10)*k;
		k*=10;
		n/=10;
	}
	printf("%d", x);
	return 0;
}
