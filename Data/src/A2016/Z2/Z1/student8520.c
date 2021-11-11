#include <stdio.h>
#include <math.h>

int oduzmi(int broj){
	int zadnja,predzadnja;
	zadnja = broj%10;
	predzadnja = (broj/10)%10;
	return fabs(zadnja-predzadnja);
}
int main() {
	int broj;
	int noviBroj = 0;
	int i, cifra, cifra2;

	i = 1;
	printf("Unesite broj: ");
	scanf("%i", &broj);
	broj = fabs(broj);
	while(broj > 10){
		noviBroj += oduzmi(broj) * i;
		i*=10;
		broj/=10;
	}

	
	printf("%d",noviBroj);
}