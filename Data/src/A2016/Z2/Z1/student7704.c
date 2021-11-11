#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, broj, i, zadnja, predzadnja, suma = 0, br_cifara = 0, razlika, stepen = 1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if (n < 0) n *= -1;
	broj = n;
	while (broj) {
		broj/=10;
		br_cifara++;
	}
	for (i = 0; i < br_cifara-1; i++) {
		zadnja = n%10;
		n/=10;
		predzadnja = n%10;
		razlika = abs(zadnja-predzadnja);
		suma += razlika*stepen;
		stepen = stepen*10;
	}
	printf("%d", suma);
	return 0;
}
