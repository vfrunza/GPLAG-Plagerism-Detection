#include <stdio.h>
#include <stdlib.h>
int main() {
	int broj, kopija, djeljitelj=1, n1, n2, broj2=0;
	//Unos broja
	printf("Unesite broj: ");
	scanf("%d", &broj);
	broj=abs(broj);
	kopija=broj;
	//Odredivanje velicine dekadskog djeljitelja
	while(kopija>10){
		kopija/=10;
		djeljitelj*=10;
	}
	//dijeljenje i oduzimanje susjednih cifara
	while(djeljitelj>1){
		n1=broj/djeljitelj;
		broj=broj-(broj/djeljitelj)*djeljitelj;
		djeljitelj/=10;
		n2=broj/djeljitelj;
		broj2+=(abs(n1-n2)*djeljitelj);
		}
		printf("%d", broj2);
	return 0;
}
