#include <stdio.h>
#include <stdlib.h>
int main() {
int n,c,d,R;
	R=0;
	d=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	do {
		c=n%10;
		n=n/10;
		R=R+abs(c-(n%10))*d;
		d=d*10;
	} while (n/10!=0);
	printf("%d",R);
	return 0;
}
