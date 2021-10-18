#include <stdio.h>

int main()
{
	int N,i,j,brojac,nosorog,zirafa;


	do {
		printf("Unesite broj N: ");
		scanf ("%d", &N);
		if (N%4!=0 ||N<8) printf ( "Neispravno N!\n");
	} while (N%4!=0 || N<8);

	printf ("\n");
	for (i=1; i<=N; i++) {
		if (i<=N/2) {
			for (j=1; j<=N/2; j++) {
				if (j==i) {
					printf ("\\");
				}
				if (i==N/2-j+1) {
					printf ("/");
				} else {
					if (i!=0 && j!=i) {
						printf (" ");
					}
				}
			}

			brojac=N/2;
			for (j=1; j<=brojac; j++) {
				if ((i==1 || i==brojac)) {
					if (j==1 || j==brojac) printf ("+");
					else printf("-");
				} else {
					if (j==1 || j==brojac) printf ("|");
					else printf (" ");
				}

			}
			printf ("\n");
		} else {
			brojac=N/2;
			for (j=1; j<=brojac; j++) {
				if ((j==1 && i==brojac+1) || (j==1 && i==N) ||(j==brojac && i==brojac+1) || (j==brojac && i==N) ) printf ("+");
				else if (i==brojac+1 || i==N)  printf ("-");
				else if (j==1 || j==brojac) printf ("|");
				else printf (" ");
				/* ZADNJI KVADRAT :'( */
			}
			nosorog = brojac + brojac/2;
			zirafa = brojac/2;
			for (j=1; j<=N/2; j++) {
				if (i==nosorog && (j==zirafa+1 || j==zirafa) ) printf ("+");
				else if (i==nosorog+1 && (j==zirafa ||j==zirafa+1)) printf ("+");
				else if (j==zirafa+1 || j==zirafa) printf ("|");
				else if (i==nosorog || i==nosorog+1) printf ("-");
				else printf (" ");
			}
			printf ("\n");
		}
	}





	return 0;
}
