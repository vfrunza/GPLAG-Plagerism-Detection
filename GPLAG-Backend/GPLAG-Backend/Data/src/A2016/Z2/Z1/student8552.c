#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,cifra,cifra2,suma=0,k=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n>=-9 && n<=9)
		printf("0");
	else {	
		if(n<0)
			n=abs(n);
		while(n>9) {
			cifra=n%10;
			n/=10;
			cifra2=n%10;
			suma+=k*abs(cifra-cifra2);
			k*=10;
		}
		printf("%d",suma);
	}
	return 0;
}
