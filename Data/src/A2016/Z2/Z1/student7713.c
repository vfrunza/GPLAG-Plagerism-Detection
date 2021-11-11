#include <stdio.h>
#include <stdlib.h>

int main() {
	int broj,prvi,drugi,s,n=1,suma=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	do {
	
		prvi = broj%10;
		broj/=10;
		drugi = broj%10;
		if(broj==0) break;
		s=abs(prvi-drugi)*n;
		n*=10;
		suma+=s;
		
	}while(broj!=0);
	
	printf("%d", suma);
	
	return 0;
}
