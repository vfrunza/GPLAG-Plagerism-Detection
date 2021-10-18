#include <stdio.h>

int main()
{
	/*Prvo cemo deklarisati varijable i staviti njihovu pocetnu vrijednost*/
	int r=0, k=0, sk=0, i=0, j=0, l=0;
	/*Koristeci do-while petlju osigurat cemo da su svi uneseni brojevi veci od nule a manji ili jednaki deset*/
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &r);
	} while(r>10 || r<=0) ;
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &k);
	} while(k>10 || k<=0);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);
	} while(sk>10 || sk<=0);
	/*Koristeci for petlju formirat cemo nacin na koji ce se znakovi ispisivati*/
	for(i=0; i<=r; i++) { 
		for(j=0; j<k; j++) {
			printf("+");
			for(l=0; l<sk; l++) {
				printf("-");
			}
		}
		printf("+\n");
		if(i<r) {
			for(j=0; j<k; j++) {
				printf("|");
				for(l=0; l<sk; l++) {
					printf(" ");
				}
			}
			printf("|\n");
		}
	}


	return 0;
}
