#include <stdio.h>
#include <stdlib.h>

int main() {
	int a,rezultat=0,b,c,d,k=1;
	printf("Unesite broj: ");
	scanf ("%d",&a);
	if (a<0) a=(abs(a));
	if (a/10==0) {printf("%d",rezultat);}
	else {
	do { b=a%10;
	c=(a/10)%10;
	d=(abs(b-c));
	rezultat+=d*k;
	k=k*10;
	a=a/10;
	}
	while (a/10!=0);
	printf("%d",rezultat);}
	return 0;
}
