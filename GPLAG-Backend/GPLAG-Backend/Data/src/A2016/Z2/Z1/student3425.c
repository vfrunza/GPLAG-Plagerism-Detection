#include <stdio.h>
#include <stdlib.h>

int main() {
//	printf("Zadaća 2, Zadatak 1");
	int broj,cifra,desetka=1,rezulat=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	while(broj/10!=0){
		cifra=broj%10;	//cifra postaje zadnja cifra broja, ostatak od 10 je zadnja cifra
		broj= broj/10;	//broj skratimo za zadnju cifru
		rezulat= rezulat+abs(cifra-(broj%10))*desetka;	//rezulat se poveca za apsolutnu vrijednost rezulata oduzimanja zadnje i predzadnje cifre
		desetka=desetka*10;
	}
	printf("%d",rezulat);
	return 0;
}
