#include <stdio.h>

int main() {
	int a;
	printf("Unesite broj: ");
	scanf("%d", &a);
	int k=1;
	int sumica=0;
	int c1,c2,l;
	while(a!=0) {
		c1=a%10;
		a/=10;
		c2=a%10;
		l=c1-c2;
		if(l<0)
			l=-l;
		if(a==0) break;
		sumica+=k*l;
		k*=10;
	}
	printf("%d", sumica);
	return 0;
}
