#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int broj1, temp=0, broj2, broj, vrijednost=1, suma=0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if((broj>=0) && (broj<=9)) {
		printf("0");
		return 0;
	} else {
		
		broj=abs(broj);
		do {
			
			broj2=broj%10;
			broj1=(broj/10)%10;
			temp=(abs(broj2-broj1))*vrijednost;
			broj=broj/10;
			vrijednost*=10;
			suma=suma+temp;
		
		}while(broj>10); 
		
		printf("%d", suma);
		
	}
	return 0;
}
