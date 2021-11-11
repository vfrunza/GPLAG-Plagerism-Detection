#include <stdio.h>

int main() {
	int i, j, k, a, b , c;
	do {
	printf("Unesite broj redova: ");
	scanf ("%d", &c);}
	while (c<=0 || c>10);
	do {
    printf ("Unesite broj kolona: ");
    scanf ("%d", &a);}
	while (a<=0 || a>10);
	do {
    printf ("Unesite sirinu jedne kolone: ");
    scanf ("%d", &b); }
    	while (b<=0 || b>10);
   	for (k=0;k<c;k++) {
    	printf ("+");
		for (i=0;i<a;i++) {
			for (j=0;j<b;j++){
				printf ("-");
				}printf ("+");
				}printf ("\n");
		
			printf ("|");
			for (i=0;i<a;i++) {
		for (j=0;j<=b;j++){
			if (j==b) {
				printf ("|");
		}	else {
				printf (" ");
				}}
		}printf ("\n");
    }			   
    printf ("+");
		for (i=0;i<a;i++) {
			for (j=0;j<b;j++){
				printf ("-");
				}printf ("+");
				}printf ("\n");
	return 0;
}
