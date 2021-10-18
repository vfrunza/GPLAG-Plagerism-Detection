#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int main() {
	int n, cifra, zadnja, i, broj, novi;
	cifra=0; zadnja=0; broj=0; novi=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	
	if(n<0) n*=-1;
	if (n<10)
	{
		printf("0"); return 0;
	}
	i=0;
	while (fabs(n)>9)
	{
		zadnja=n%10;
		n=n/10;
		broj=n%10;
		cifra=fabs(zadnja-broj);
		novi=novi+pow(10,i)*cifra;
		i++;
	}
		
	
	printf("%d",novi);
	return 0;
}
