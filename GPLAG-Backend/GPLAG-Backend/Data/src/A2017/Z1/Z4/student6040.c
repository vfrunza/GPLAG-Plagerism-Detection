#include <stdio.h>

int main() {
	int k, s, r, i, j, g;
	do {
	printf ("Unesite broj redova: ");
	scanf ("%d", &r);}
	while (r>10 || r<=0);
	
	do {
	printf ("Unesite broj kolona: ");
	scanf ("%d", &k);}
	while (k>10 || k<=0);
	
	do {
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d", &s);}
	while (s>10 || s<=0);
	for (g=0;g<r;g++){
		for (i=1;i<=k;i++) {
			printf ("+");
			for (j=1;j<=s;j++) {
				printf ("-");
			}
		}
		printf ("+\n");	
		
		for (i=1;i<=k;i++){
			printf ("|");
			for (j=1;j<=s;j++)
			printf (" ");
		}
		printf ("|\n");
	}
	for (i=1;i<=k;i++){
		printf ("+");
		for (j=1;j<=s;j++){
			printf ("-");
		}
	}
		printf ("+\n");
	return 0;
}
