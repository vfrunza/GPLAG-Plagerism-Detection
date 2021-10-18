#include <stdio.h>

int main() {
	int broj,cifra1,cifra2,suma=0,k=1,temp;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<0)broj=-broj;
	if(broj<10) suma=0;
	
	while(broj>=10)
	{
		cifra1=broj%10;
		broj/=10;
		cifra2=broj%10;
		temp=cifra1-cifra2;
		if(temp<0)temp=-temp;
		suma+=k*temp;
		k*=10;
	}
	printf("%d",suma);
	return 0;
}
