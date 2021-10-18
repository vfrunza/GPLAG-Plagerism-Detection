#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int broj, kbroj=0, x=1;
	int a, b, c;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	broj=abs(broj);
	
	if(broj<10&&broj>=0) {printf("0"); return 0;}
	
	
	while(broj>9){
		
		a=broj%10;
		broj=broj/10;
		b=broj%10;
		c=abs(a-b);
		kbroj=kbroj+x*c;
		x=x*10;
		
	}
	
	printf("%d", kbroj); 
	
	return 0;
}
