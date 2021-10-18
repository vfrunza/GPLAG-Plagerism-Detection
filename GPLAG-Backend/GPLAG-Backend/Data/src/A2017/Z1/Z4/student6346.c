#include <stdio.h>

int main()
{
	int a,b,c,i,j,k;
	do {
		printf ("Unesite broj redova: ");
		scanf ("%d", &a);
	} while (a<=0 || a>10);

	do {
		printf("Unesite broj kolona: ");
		scanf ("%d", &b);
	} while (b<=0 || b>10);

	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &c);
	} while (c<=0 || c>10);

	for (j=1; j<2*a+2; j++) {
		if (j%2==1) {
			printf ("+");
			for (k=1; k<=b; k++) {
				for (i=1; i<=c; i++) {
					printf ("-");
				}
				printf ("+");
			}
			printf ("\n");
		}

		if (j%2==0) {
			printf ("|");
			for (k=1; k<=b; k++) {
				for (i=1; i<=c; i++) {
					printf (" ");
				}
				printf ("|");
			}
			printf("\n");
		}
	}



    

	return 0;
}