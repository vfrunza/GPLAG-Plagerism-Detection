#include <stdio.h>

int main() {
	int n, i, j;
	
	for(i=0;i<1;i++) {
		printf ("Unesite broj N: "); 
		scanf ("%d", &n);
		if (n%4==0 && n>=8 && n!=4) continue;
		else if (n<=7) {
			printf ("Neispravno N! ");
			i--;
		}
		printf ("\n");
	} printf ("\n");
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j && i <= (n/2)-1 && j <= (n/2)-1) {
				printf ("\\");
			} else if (j == (n/2)-i-1 && i <= (n/2)-1 && j <= (n/2)-1) {
				printf ("/");
			} else if ((i==0 && j == n/2) || (i==0 && j==n-1) || (i==n/2-1 && j==n/2) || (i==n/2-1 && j== n-1) || (i==n/2 && j==0) || (i==n/2 && j==n/2-1) || (i==n-1 && j==0) || (i==n-1 && j==n/2-1)) {
				printf ("+");
			} else if ((i==0 && j>n/2) || (i==n/2-1 && j>n/2) || (i==n/2 && j<n/2) || (i==n-1 && j<n/2)) {
				printf ("-");
			} else if ((i>n/2 && j==0) || (i>n/2 && j==n/2-1) || (i<n/2 && j==n/2) || (i<n/2 && j==n-1)) {
				printf ("|"); 
			/*kraj gornjeg desnog i donjeg lijevog kvadrata*/
			} else if ((i==(n/2)+(n/4) && j==(n/2)+(n/4)) || (i==(n/2)+(n/4)-1 && j==(n/2)+(n/4)) || (i==(n/2)+(n/4) && j==(n/2)+(n/4)-1) || (i==(n/2)+(n/4)-1 && j==(n/2)+(n/4)-1)) {
				printf ("+");
			} else if ((i>n/2-1 && j==(n/2)+(n/4)-1) || (i>n/2-1 && j==(n/2)+(n/4))) {
				printf ("|");
			} else if ((j>n/2-1 && i==(n/2)+(n/4)-1) || (j>n/2-1 && i==(n/2)+(n/4))) {
				printf ("-");
			} else printf (" ");
		}
		printf ("\n");
	}
	return 0;
}
