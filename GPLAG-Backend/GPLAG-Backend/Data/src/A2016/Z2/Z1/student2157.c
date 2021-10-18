#include <stdio.h>
#include <stdlib.h>
int main() {
	int e=0, a, b, c, d=1;
	printf("Unesite broj: ");
	scanf("%d", &c);
	c=abs(c);
	if(c<10){
	printf("0");
	return 0;
	} 
	while(c>=10){
	a=c%10;;
	c=c/10;
	b=c%10;
	e=e+(abs(a-b))*d;
	d=10*d;
	}
	printf("%d", e);
	return 0;
}
