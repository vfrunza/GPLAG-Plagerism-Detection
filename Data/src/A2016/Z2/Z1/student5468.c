#include <stdio.h>
#include <stdlib.h>
int main() {
	int a,b,c,k,n=1,a1=0;
	printf("Unesite broj: ");
	scanf("%d",&a);
	if (a<10 && a>-10){
		a1=0;
	printf("%d",a1);
	return 0;
	}
	else if (a<0)
	a=abs(a);
	do {
		c=a%10;
		b=(a/10)%10;
		k=abs(c-b)*n;
		n=n*10;
		a=a/10;
		a1=a1+k;
	}while(a>9);
		printf("%d",a1);
	return 0;
}
