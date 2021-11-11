#include <stdio.h>
#include <stdlib.h>

int main() {
	int br,broj=0,pr,c1,c2,c,um=1;
	printf("Unesite broj: ");
	scanf("%d",&br);
	
	if(br<0)
		br=-br;
	
	while(br>9){
		c1=br%10;
		c2=(br/10)%10;
		c=abs(c1-c2);
		pr=c*um;
		broj+=pr;
		um*=10;
		br=br/10;
	}
    printf("%d",broj);
	return 0;
}
