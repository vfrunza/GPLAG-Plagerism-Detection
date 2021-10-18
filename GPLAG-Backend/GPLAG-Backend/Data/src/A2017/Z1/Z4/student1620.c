#include <stdio.h>

int main() {
	int r,k,s,x,y,z,a,p,c;
	y = 1;
	x=1;
	z=1;
	a=1;
	p=1;
	c=1;
do {
	printf ("Unesite broj redova: ");
 
	scanf ("%d",&r);
 } while (r <= 0 || r > 10);
 	do {
	printf ("Unesite broj kolona: ");

	scanf ("%d",&k);	
	} while (k<= 0 || k > 10);
		do {
	printf ("Unesite sirinu jedne kolone: ");

	scanf ("%d",&s);
	} while (s <= 0 || s>10);
	for (y;y<r+1;y++) {
		x=1;
		z=1;
		a=1;
		for (x;x<k+1;x++) {
			printf ("+");
			z =1;
			for (z;z<s+1;z++) {
				printf("-");
				}
			if (x+1 == k+1) {
				printf ("+");
			}
			}
			printf("\n");
			for (a;a<k+1;a++) {
			printf ("|");
			p =1;
			for (p;p<s+1;p++) {
				printf(" ");
				}
			if (a+1 == k+1) {
				printf ("|");
			}
			}
			printf("\n");
			if (y+1 == r+1) {
				for (c;c<k+1;c++) {
			printf ("+");
			z =1;
			for (z;z<s+1;z++) {
				printf("-");
				}
			if (c+1 == k+1) {
				printf ("+");
			}
			}
			}
		}

	return 0;
}
