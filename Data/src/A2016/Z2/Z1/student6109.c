#include <stdio.h>
#include <math.h>

int main() {
	int broj, suma, suma1, suma2;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	broj=fabs(broj);
	suma=1;
	while(broj>0)
	{
		suma1=broj%10;
		broj/=10;
		suma2=(broj%10);
		suma=suma*10+fabs(suma1-suma2);
	}
	
	suma/=10;
	
	suma1=0;
	while(suma>0)
	{
		suma1=suma1*10+suma%10;
		suma/=10;
	}
	suma1/=10;
	printf("%d", suma1);
	return 0;
}