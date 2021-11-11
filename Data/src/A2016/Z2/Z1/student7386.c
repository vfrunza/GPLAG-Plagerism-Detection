#include <stdio.h>
#include <stdlib.h>
 
int main() {
	int n,m=0,x=1,c1,c2,r;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n=abs(n);
	if(n<10){
		printf("0"); return 0;
	}
	do {
		c1=n%10;
		n=n/10;
		c2=n%10;
		r=abs(c1-c2);
		m=m+x*r;
		x=x*10;
	}
	while(n>9);
	printf("%d",m);
    return 0;
}