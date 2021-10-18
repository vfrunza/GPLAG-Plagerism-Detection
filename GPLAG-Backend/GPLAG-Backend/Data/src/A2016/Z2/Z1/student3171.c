#include <stdio.h>
#include <math.h>

int main() {
	
	int broj, b, c, pc, x;
	int suma=0;
	int br=0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	

	if(broj==0) printf("0");
	else {
	while(broj!=0)
	{
		b=broj%10;
		c=(broj/10)%10;
		suma=suma + fabs(b-c)*pow(10, br);
		broj=broj/10;
		br++;
		
	}
	
	x=pow(10, br-1);
	pc=suma%x;
	
	printf("%d", pc);
	}
	
	
	return 0;
}
