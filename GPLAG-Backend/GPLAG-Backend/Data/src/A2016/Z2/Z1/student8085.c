#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int broj,stepen=0,noviBroj=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);
	while(broj>9){
		noviBroj+=abs(broj%10-(broj%100)/10)*pow(10,stepen);
		broj/=10; stepen++;
	}
	
	printf("%d",noviBroj);
	return 0;
}
