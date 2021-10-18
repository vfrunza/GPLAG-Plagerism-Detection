#include <stdio.h>
#include <stdlib.h>
int main() {
	int rezultat=0, desetke=10;
	int broj, c1, c2, razlika;
	
	/* ----- unos broja i uslovi ----- */
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0){
		broj=abs(broj);
	}
	if(broj/10<=1 || broj==0){ /* ako je broj jednocifren ispisati 0 i kraj programa */
		printf("0");
		return 0;
	}
	
	/* ----- rastavljanje na cifre i ispisivanje ----- */
	while(broj>10){
		c1=broj%10;
		broj=broj/10;
		c2=broj%10;
		razlika=c2-c1;
		if(razlika<0){
			razlika = abs(razlika);
		}
		rezultat=rezultat+(razlika*desetke);
		desetke=desetke*10;
	}
	rezultat=rezultat/10; /* ----- zbog mnozenja sa stepenima desetke mora se smanjiti na kraju za jedan deseti dio ----- */
	printf("%d", rezultat);
	return 0;
}
