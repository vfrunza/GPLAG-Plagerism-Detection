#include <stdio.h>

int main() {
	int n, i, j, kolona;
	printf ("Unesite broj n: ");
	scanf ("%d", &n);
	if (n<=0 || n>50) {
		printf ("Pogresan unos");
		printf ("\nUnesite broj n: ");
		scanf ("%d", &n);
	}
	while (n<0 || n>50) {
		printf ("Pogresan unos");
		printf ("\nUnesite broj n: ");
		scanf ("%d", &n);
	}
	if (n==1) {
		printf ("**");
	}
	kolona=n*4-3;
	for (i=0;i<n;i++) {
		for (j=0;j<(kolona);j++) {
				if(i==j) {
					printf("*"); }
					else if (i+j==(kolona)/2) {
						printf ("*"); }
						else if (i==j-(kolona)/2) {
							printf("*"); }
							else if (i+j==kolona-1) {
								printf ("*");
							}
							else printf (" ");
						}
						printf ("\n");
					}
	return 0;

}
