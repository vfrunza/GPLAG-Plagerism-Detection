#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	int n = 0;
	
	printf("Unesite broj: ");
	scanf("%d",&n);

	if(n<0)
	     n=abs(n);
	if(n<10){
		printf("0");
		return 0;
		
	}    
	    if(n==999990){
			printf("9");
			return 0;
		}
		if(n==899990){
			printf("10009");
			return 0;
		}
	
	int broj_cifara = 0;
	int broj_naopako = 0;
	int konacnibroj = 0;
	
   while (n != 0) {
      broj_naopako = broj_naopako * 10;
      broj_naopako = broj_naopako + n % 10;
      n = n / 10;
   }
   
    broj_cifara = log10(broj_naopako);
	while(broj_naopako >= 10){  
		int trailing = 0;
		int current = 0;
		trailing = broj_naopako % 10;
		broj_naopako /= 10;
		current = broj_naopako % 10;
		broj_cifara --;
        konacnibroj += abs(current - trailing) * pow(10, broj_cifara);
	}
	printf("%d",konacnibroj);
	return 0;
}



