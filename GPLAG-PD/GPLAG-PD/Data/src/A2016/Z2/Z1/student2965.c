#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,c1,c2,t=1,suma=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) { 
		n=abs(n);
	}
	while (n>=10) {
		c1=n%10;
		c2=(n/10)%10;
		suma=suma+t*fabs(c1-c2);
		t=t*10;
		n=n/10;
	
	}
	printf("%d",suma);
	
	
	return 0;
}
