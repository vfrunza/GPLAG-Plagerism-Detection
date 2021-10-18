#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int c1,c2,broj,broj2=0,sum, stepen=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);
	if(broj<10)
	{
		broj2=0;
		printf("%d",broj2);
	}else{
	do
	{
		c1=broj%10;
		broj/=10;
		if(broj!=0)
		{
		c2=broj%10;
		sum=abs(c2-c1);
		broj2=broj2+sum*pow(10,stepen);
		stepen++;
		}
	}while(broj!=0);
	printf("%d", broj2);
	}
	return 0;
}