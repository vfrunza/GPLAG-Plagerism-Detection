#include <stdio.h>

int main() {
	int i, j, n;
	do {
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	
	while (n<0 || n>50);
	for  (i=0; i<n; i++) {
		for (j=0; j <= 4*n-4; j++){
			if(i == j) printf ("*");
		else	if((n*2)-2 == i+j && i != n-1 ) printf ("*");
		else	if(2*(n-1)+i == j) printf ("*");
		else if(i+j == 4*n-4) printf ("*");
			else printf (" ");
		}
		printf ("\n");
	}
	
	
	return 0;
}
