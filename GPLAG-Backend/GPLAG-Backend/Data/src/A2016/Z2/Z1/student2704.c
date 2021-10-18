#include <stdio.h>
#include <stdlib.h>

int main() {
	int c, x, y, br=0, z=1;
	printf("Unesite broj: ");
	scanf("%d", &x);
	
	while(x!=0) {

		c=abs(x)%10;
		x=abs(x)/10;		
		if(x==0) break;
		y=abs(x)%10;		
		br+=(abs(c-y))*z;
		z*=10;
		
	}
	printf("%d", br);
	return 0;
}
