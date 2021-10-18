#include <stdio.h>
#include <stdlib.h>

int main() {
	int i=1,n,s=0,c1,c2;
	printf("Unesite broj: ");
	scanf ("%d",&n);
	n=abs(n);
	while (n>10) {
	c1=n%10;
	n=(n-c1)/10;
	c2=n%10;
	s=s+i*abs(c2-c1);
	i*=10;
	} 
	printf ("%d",s);
	return 0;
}
