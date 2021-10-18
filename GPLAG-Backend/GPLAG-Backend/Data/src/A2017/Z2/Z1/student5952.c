#include <stdio.h>

int main() {
	int broj, i, j;
	do {
	printf("Unesite broj N: ");
	scanf("%d", &broj);
	

	
	if (broj %4 !=0 || broj < 8) printf ("Neispravno N!\n");
	} while(broj%4 != 0 || broj < 8);
	printf ("\n");
	for (i=0; i<(broj/2); i++) {
		for (j=0; j<(broj); j++) {
			if (i==j) printf ("\\");
			else if (i+j==(broj/2)-1) printf ("/");
			else if (i==0 || i==(broj/2)-1) {
				if(j==broj/2 || j==(broj-1)) printf("+");
				else if(j>(broj/2) && j<(broj-1)) printf ("-");
				else printf (" ");
			}
			else if (i>0 && i<(broj/2)) {
				if(j==broj/2 || j==broj-1) printf ("|");
				else printf(" ");
			}
			else printf (" ");
		}
		printf ("\n");
	}
	for (i=(broj/2); i<broj; i++) {
		for (j=0; j<broj; j++) {
			if (i==broj/2 || i==(broj-1)) {
				if(j==0 || j==(broj/2)-1) printf ("+");
				else if(j>0 && j<broj/2) printf ("-");
				else if (j==((broj/2)+(broj-1))/2 || j==(((broj/2)+(broj-1))/2)+1) printf ("|");
				else printf (" ");
				
			}
			else if (i==((broj/2)+(broj-1))/2 || i==(((broj/2)+(broj-1))/2)+1) {
			if (j==0 || j==(broj/2)-1) printf ("|");
			else if (j==((broj/2)+(broj-1))/2 || j==(((broj/2)+(broj-1))/2)+1) printf ("+");
			else if (j>=(broj/2) && j<((broj/2)+(broj-1))/2) printf ("-");
			else if (j>=(((broj/2)+(broj-1))/2)+1 && j<=broj-1) printf ("-");
			else printf (" ");
			}
			else if (i>broj/2 && i<((broj/2)+(broj-1))/2) {
				if (j==0 || j==(broj/2)-1 || j==((broj/2)+(broj-1))/2 || j==(((broj/2)+(broj-1))/2)+1) printf ("|");
				else printf (" ");
			}
			else if (i>(((broj/2)+(broj-1))/2)+1 && i<broj-1) {
				if (j==0 || j==(broj/2)-1 || j==((broj/2)+(broj-1))/2 || j==(((broj/2)+(broj-1))/2)+1) printf ("|");
				else printf (" ");
			}
		}
		printf ("\n");
	}

	return 0;
}


