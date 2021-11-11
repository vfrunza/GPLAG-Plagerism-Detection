#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n=0, n2=0, dec1=0, dec2=0, i;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=abs(n);
	for(i=0; n>10 ;i++){
		dec1 = n%10;
		n /= 10;
		dec2 = n%10;
		if(n<0){
			break;
		}
		n2 = n2 + (abs(dec1 - dec2)*pow(10, i));
	}
	printf("%d", n2);
}