#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,i,s=0,a,b,suma=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)n=abs(n);
	if(n>=0 && n<=9){printf("0");
	return 0;}
	for(i=0; i<n; i++){
		a=n%10;
		n=n/10;
		b=n%10;
		s=a-b;
		if(s<0)s=abs(s);
		suma+=(s*pow(10,i));
		if(n>=0 && n<=9)break;

	}
	printf("%d", suma);
	return 0;
}
