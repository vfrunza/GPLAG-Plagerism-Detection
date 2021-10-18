#include <stdio.h>

int main() {
	int i, j, l, a, b , c;
	do {
	printf("Unesite broj redova: ");
	scanf ("%d", &a);}
	while (a<=0 || a>10);
	do {
    printf ("Unesite broj kolona: ");
    scanf ("%d", &b);}
	while (b<=0 || b>10);
	do {
    printf ("Unesite sirinu jedne kolone: ");
    scanf ("%d", &c); }
    	while (c<=0 || c>10);
   	for (l=0;l<a;l++) {
    	printf ("+");
		for (i=0;i<b;i++) {
			for (j=0;j<c;j++){
				printf ("-");
				}printf ("+");
				}printf ("\n");
		
			printf ("|");
			for (i=0;i<b;i++) {
		for (j=0;j<=c;j++){
			if (j==c) {
				printf ("|");
		}	else {
				printf (" ");
				}}
		}printf ("\n");
    }			   
    printf ("+");
		for (i=0;i<b;i++) {
			for (j=0;j<c;j++){
				printf ("-");
				}printf ("+");
				}printf ("\n");
	return 0;
}