#include <stdio.h>

int main() {
	
	int redovi, kolone, sirina, i1=0,i2=0,j=0,k=0;
	do {
	printf ("Unesite broj redova: ");
	scanf ("%d", &redovi);
	}
	while (redovi<=0 || redovi>10);
	do {
	printf ("Unesite broj kolona: ");
	scanf ("%d", &kolone);
	}
	while (kolone<=0 || kolone>10);
	do{
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &sirina);
	}
	while (sirina<=0 || sirina>10);
	while (1) {
		if (i1<redovi+1) {
			for (j=0; j<kolone; j++){
				printf ("+");
				for (k=0; k<sirina; k++) printf ("-");
			}
			printf ("+\n");
			i1++;
		}
		if (i2<redovi) {
			for (j=0; j<kolone; j++){
				printf ("|");
				for (k=0; k<sirina; k++) printf (" ");
			}
			printf ("|\n");
			i2++;
		}
		if (i1>=redovi+1 && i2>=redovi) break;
		
	}
    

	return 0;
}
