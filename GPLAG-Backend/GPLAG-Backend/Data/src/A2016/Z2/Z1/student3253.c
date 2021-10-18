#include <stdio.h>
#include <stdlib.h>
#include <math.h>


	int main() {
		int x, c1, c2, s=0, k=1;
		printf("Unesite broj: ");
		scanf("%d", &x);
		
		if(x<0){
		x=fabs(x);
	}
	if(x<10){
		printf("0");
		return 0;
	}
		
		while (x>=10){
			c1=x%10;
			x=x/10;
			c2=x%10;
			s=s+k*fabs(c1-c2);
			k*=10;
		}
		printf("%d", s);
	return 0;
}
