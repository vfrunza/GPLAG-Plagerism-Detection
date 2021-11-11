#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,br1,br2,a,broj=0,j=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	 if(n<0) n=abs(n);
	
	do {
		br1=n%10;
		n=n/10;
		if (n==0) break;
		br2=n%10;
		a=abs(br1-br2);
		
		broj=broj + a*j;
		j=j*10;
		
		
	} while (n>0);
	printf("%d",broj);
	return 0;
}
