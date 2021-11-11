#include<stdio.h>
#include<stdlib.h>
int main() {
	int n;
	int x, y, z;
	int novi_broj = 0;
	int i = 1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n = abs(n);
	if (n >= 0 && n < 10){
		printf("0");
		return 0;
	}
	while(n > 9){
		x = n%10;
		n = n/10;
		y = n%10;
		z = abs(x-y);
		novi_broj = novi_broj + i*z;
		i = i*10;
	}
		printf("%d", novi_broj);
	return 0;
}
