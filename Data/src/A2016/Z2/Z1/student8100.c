#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, prva_cifra, druga_cifra, desetice = 1, br=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if (n<0) n=abs(n);
	while(n>=10){
		prva_cifra = n%10;
		druga_cifra = (n/10)%10;
		br += (abs(prva_cifra - druga_cifra))*desetice;
		desetice*=10;
		n/=10;
	}
	printf("%d", br);
	return 0;
}
