/*Napisati program koji na ekranu ispisuje tabelu sastavljenu od znakova plus (+), minus (-) i vertikalna linija
tj. pipe (|) kao u primjeru. Korisnik unosi broj redova, broj kolona i širinu jedne kolone (u minusima) a zatim se 
iscrtava tabela. Pomoću do-while petlje osigurati da su svi uneseni brojevi veći od nule a manji ili jednaki 10. 
Primjer:

Unesite broj redova: 2
Unesite broj kolona: 5
Unesite sirinu jedne kolone: 3
+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
*/

#include <stdio.h>

int main() {
	
	int i,j,k,a,b,c;
	
do {	printf("Unesite broj redova: ");
		scanf("%d", &a);
	} while (a<=0 || a>10);
do {	printf("Unesite broj kolona: ");
		scanf("%d", &b);
	} while (b<=0 || b>10);
do {	printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &c);
	} while (c<=0 || c>10);	
	
	for (k=0 ; k<a ; k++){
	
		for (i=0; i<b ; i++){
				printf("+");
				for(j=0 ; j<c ; j++){
					printf ("-");
				}
			} printf("+");
	
			printf("\n");
	
	
	
		for (i=0 ; i<b; i++){
				printf ("|");
				for(j=0 ; j<c ; j++){
					printf (" ");
				} 
			} printf ("|");
	
			printf ("\n");
	}
	

			for (i=0; i<b ; i++){
				printf("+");
					for(j=0 ; j<c ; j++){
						printf ("-");
					}
			} printf("+"); 

		
	return 0;
}
