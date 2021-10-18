#include <stdio.h>
#include <math.h>

int main() {
	int n=0, k=1, cifra1=0, cifra2=0, novi=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=fabs(n);
	
	while(n>=10) {
		cifra1=n%10;
		cifra2=(n/10)%10;
		novi = novi + fabs(cifra1-cifra2)*k;
		k*=10;
		n/=10;
	}
	
	printf("%d", novi);
	
	return 0;
}
