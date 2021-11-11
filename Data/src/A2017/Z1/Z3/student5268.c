#include <stdio.h>
#define epsilon 0.001
int main() {
	int a,b,c,D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d", &a,&b,&c);
	D=b*b-4*a*c;
	if(D<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	else{
		
	}
	
	return 0;
}
