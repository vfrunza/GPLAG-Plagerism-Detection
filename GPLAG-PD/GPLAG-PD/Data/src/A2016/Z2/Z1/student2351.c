#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int n,cjedan,cdva,broj_rez=0,brojac=1,i;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)n*=-1;
	if (n==0 || n==1 || n==2 || n==3 || n==4 ||n==5 || n==6 || n==7 || n==8 ||n==9) { printf("0"); return 0; }

	else {
	
		cjedan=(n%10);
		n/=10;
	while (n!=0)
	{
		cdva=n%10; 
		broj_rez=broj_rez+abs(cjedan-cdva)*brojac;
		brojac*=10;
		cjedan=cdva;
		n=n/10;
		
	}
	printf("%d",broj_rez);
	}
return 0;
}







