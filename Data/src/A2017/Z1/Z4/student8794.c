#include <stdio.h>

int main() {
	int brojredova, brojkolona, sirinakolone, i, j, broj, k;
	do {printf("Unesite broj redova: ");
	scanf ("%d", &brojredova); } while (brojredova<=0 || brojredova>10);
	do {printf ("Unesite broj kolona: ");
	scanf ("%d", &brojkolona);} while (brojkolona<=0 || brojkolona>10);
	do {printf ("Unesite sirinu jedne kolone: "); 
	scanf ("%d", &sirinakolone);} while (sirinakolone<=0 || sirinakolone>10);
	broj=2*brojredova+1;
	for (i=0; i<broj; i++){
		if (i%2==0){
			for (j=0; j<brojkolona; j++){
				printf ("+");
				for (k=0; k<sirinakolone; k++){
					printf ("-");
				}
			}
			printf ("+");
			printf ("\n");
		}
		if (i%2==1){
			for (j=0; j<brojkolona; j++){
				printf ("|");
				for (k=0; k<sirinakolone; k++){
					printf (" ");
				}
			}
			printf ("|");
			printf ("\n");
		}
	}
	
	return 0;
}
