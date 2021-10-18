#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int i=0,broj=0,novi=0,prvacifra=0,drugacifra=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	
	while(broj!=0)
	{   if(broj/10==0) break;
		prvacifra=broj%10;
		broj=broj/10;
		drugacifra=broj%10;
		novi= novi + (abs(prvacifra-drugacifra) )*pow(10,i);
		i++;
	}
	printf("%d",novi);
	return 0;
}
