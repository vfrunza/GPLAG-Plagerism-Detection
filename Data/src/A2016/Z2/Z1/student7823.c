#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	//printf("Zadaća 2, Zadatak 1");
	int broj, i, j=0, dec=1;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	while(broj/10!=0){
		i=broj%10;
		broj/=10;
		j+= abs(i-(broj%10))*dec;
		dec*=10;
	}
	printf("%d", j);
	return 0;
}
