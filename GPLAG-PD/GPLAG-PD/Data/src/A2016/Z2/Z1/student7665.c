#include <stdio.h>
#include<stdlib.h>

int main() {
	int broj_prvi, broj_drugi, krajnji_broj=0,n,i=1;
	printf("Unesite broj: "); scanf("%d", &n);
	broj_prvi=n%10;
	n=n/10;
	while(n!=0){
		
		broj_drugi=n%10;
		krajnji_broj=krajnji_broj+ abs(broj_prvi-broj_drugi)*i;
	
		i*=10;
		n/=10;
		broj_prvi=broj_drugi;
		

	}
    printf("%d", krajnji_broj);
	return 0;
}
