#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,m=0,x,l,k=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	while(n>=10) {
		
		if(n<0)
		n=abs(n);
		else if(n>0 && n<10) {
		m=0;
		break; }
		
		x=n%10;
		l=(n/10)%10;
		m += abs(x-l)*k;
		k = k*10;
		
		n=n/10;
		
		
		
		
	
		
		
	}
	printf("%d", m);
	return 0;
}
