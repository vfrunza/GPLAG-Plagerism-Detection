#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int x,c1,c2,s,i=0,broj=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0) x=abs(x);
	while(x>0){

		c1=x%10;
		x/=10;
		if(x==0) break;
		c2=x%10;
		s=abs(c1-c2);
		broj=broj + s*pow(10,i);
		i++;
		
	}
	printf("%d",broj);
	return 0;
}
