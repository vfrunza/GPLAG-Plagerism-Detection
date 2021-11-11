#include <stdio.h>
#include <stdlib.h>

int main() {
	int x=1,novibr=0,br1,br2,br;

	printf("Unesite broj: ");
	scanf("%d", &br);
	br=abs(br);
	
	while(br>9){
		br1=br%10;
		br/=10;
		br2=br%10;
		
		novibr=novibr +abs(br2-br1)*x;
		
	x*=10;
		
	
		
		
	}
	printf("%d",novibr);
	
	
	return 0;
}
