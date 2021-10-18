# include <stdio.h>
# include <math.h>

int main()
{
	int brRed, brKol, sirina,i,j,k;
	do { printf("Unesite broj redova: ");
	scanf("%d",&brRed); }
	while (!(brRed>0 && brRed<=10));
	do {printf("Unesite broj kolona: ");
	scanf("%d",&brKol); }
	while (!(brKol>0 && brKol<=10));
	do {printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina); }
	while (!(sirina>0 && sirina<=10 ));
	


	for(k=0; k<brRed; k++) {

		for (i=0; i<brKol; i++) {
			for(j=0; j<sirina+1; j++) {
				if (j==0) {
					printf ("+");
				} else {
					printf ("-");
				}

			}
		}
		printf ("+\n");


		for (i=0; i<brKol; i++) {
			for(j=0; j<sirina+1; j++) {
				if (j==0) {
					printf ("|");
				} else {
					printf (" ");
				}

			}
		}
		printf ("|\n");
	}

	for (i=0; i<brKol; i++) {
		for(j=0; j<sirina+1; j++) {
			if (j==0) {
				printf ("+");
			} else {
				printf ("-");
			}

		}
	}
	printf ("+\n");



	return 0;
}