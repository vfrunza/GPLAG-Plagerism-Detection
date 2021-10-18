#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, b, f, r;
	b=0;
	f=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)
		n=abs(n);
	if(n>-10 && n<10){
		printf("0");
		return 0;
	}
	while(n!=0){
		r=(n%10)-(n/10%10);
		f+=abs(r)*pow(10,b);
		n=n/10;
		b++;
	}
	f=f%(int)pow(10,b-1);
	printf("%d", f);
	return 0;
}
