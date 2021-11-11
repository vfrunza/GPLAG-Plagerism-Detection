#include <stdio.h>

int main() {
	int i,j,n;
	printf ("Unesite broj n: ");
	scanf ("%d",&n);
	while (n<=0 || n>50) {
		printf ("Pogresan unos\n");
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
	}
	if (n==1){
		printf ("***");
		return 0;
	}
		for (i=1;i<=n;i++){
			for (j=1;j<=(n+(n-1)*3);j++){
				if (i==j)
					printf ("*");
				else  if (j>n && j<n*2-1 && j-n==n-i) /*drugi krak*/
					printf ("*");
				else if (j>=(n*2-1) && i==(j-(n*2-2)))
					printf ("*"); /*treci krak*/
				else if (j>=n*3-1 && j-(3*n-2)==n-i)
					printf ("*");
				else printf (" ");
			}
		printf ("\n");
		}
	return 0;
}
