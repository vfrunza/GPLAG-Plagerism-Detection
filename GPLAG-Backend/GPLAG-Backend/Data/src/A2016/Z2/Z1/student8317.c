#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
int razlika,cifra1,cifra2,stepen=0,novibr=0,broj;
printf("Unesite broj: ");
scanf("%d", &broj);
broj=abs(broj);

if(broj<10)
{
	novibr=0;
	printf("%d",novibr);
	return 1;
}
else
{
	do
{
	cifra1=broj%10;
	broj=broj/10;
	cifra2=broj%10;
	razlika=abs(cifra2-cifra1);
	novibr=novibr+razlika*pow(10,stepen);
	stepen++;
			}
 while(broj>9);
printf("%d",novibr);
}

	return 0;
}
