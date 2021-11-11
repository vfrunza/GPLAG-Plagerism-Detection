#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int broj, novi_broj=0, cash1, cash2, dif, n=0, k, ponbr;
	printf("Unesite broj: "); scanf("%d",&broj);
	
	while (broj>=10 || broj<=-10){
		cash1=broj%10;
		ponbr=broj/10;
		cash2=ponbr%10;
		dif=abs(cash1-cash2);
		
		k=pow(10,n);
		novi_broj+=dif*k;
		broj/=10;
		n++;
	}
	printf("%d", novi_broj);
	return 0;
}