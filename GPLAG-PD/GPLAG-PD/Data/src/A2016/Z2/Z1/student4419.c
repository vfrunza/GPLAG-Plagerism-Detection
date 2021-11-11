#include <stdio.h>
#include <math.h>

int main() {
	
	int broj,cifra1,cifra2,nova_cifra;
	int i=1;
	int novi_broj=0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	if(broj>=0 && broj<10) 
	{
		printf("0");
		return 0;
	}
	
	if (broj<0) broj=fabs(broj);
	
	while(broj>=10)
	{
		cifra1=broj%10;
		broj /= 10;
		cifra2=broj%10;
		
		nova_cifra=fabs(cifra1-cifra2);
		
		novi_broj += nova_cifra * i;
		i*=10;
	}
	
	printf("%d", novi_broj);
	
	return 0;
}
