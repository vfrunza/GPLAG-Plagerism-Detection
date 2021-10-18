#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int n,c,pom,c2,rez=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) n=abs(n);
	while(n>9){
		c = n % 10;
		n = n / 10;
		c2 = n % 10;
		pom = abs(c-c2);
		rez = rez * 10 + pom;
	}
	
	while(rez % 10 == 0 && rez > 0) rez/= 10;
	
	if(rez==0) printf("%d",rez);
	while(rez!=0){
		c = rez % 10;
		rez = rez / 10;
		printf("%d",c);
	}

	
	
	
	
	return 0;
}
