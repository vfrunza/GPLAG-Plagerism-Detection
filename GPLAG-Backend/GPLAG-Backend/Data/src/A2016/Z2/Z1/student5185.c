#include <stdio.h>
#include <math.h>

int main() {
	/*Variable declaration*/
	int n, a, b, razlika, rezultat, brojac, i, test, c;
	rezultat = 0;
	brojac = 0;
	
	/*Data input*/
	printf("Unesite broj: " );
	scanf("%d", &n);
	
	if (n < 0)
	{
		n = fabs(n);
	}
	else if (n < 10 && n >= 0)
	{
		printf("0");
		return 0;
	}
	
	while (n > 10)
	{
		a = n % 10;
		b = (n / 10) % 10;
		razlika = fabs(b-a);
		
		n = n / 10;
		/*printf("%i, %i", a ,b);*/
		rezultat = rezultat * 10 + razlika; 
		brojac++;
	}
	
	c = powf(10, brojac-1);
	test = rezultat % c;
	
	if (test == 0)
	{
		rezultat = rezultat / c;
		printf("%i", rezultat);
	}
	else { 

	
	for (i = 0; i < brojac; i++)
	{
		a = rezultat % 10;
		printf("%i", a);
		rezultat = rezultat / 10;
	}
	}
	
	return 0;
}
