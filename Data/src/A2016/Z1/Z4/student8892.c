#include <stdio.h>

int main() {
	int n, i, j, raz1, raz2;
	do{
		printf ("Unesite broj n: ");
		scanf ("%d",&n);
		if (n<=0 || n>50){
			printf ("Pogresan unos\n");
		}
		
	}while (n<=0 || n>50);
	raz1=2*n-3;
	raz2=-1;
	for (i=1; i<=n; i++){
		if (i==1){
			printf ("*");
			for (j=1;j<=raz1;j++){
				printf (" ");
			}
			printf ("*");
			for (j=1;j<=raz1;j++){
				printf (" ");
			}
			printf ("*\n");
		}
		else if (i==n){
			for (j=1; j<n;j++){
				printf (" ");
			}
			printf ("*");
			for (j=1;j<=raz2;j++){
				printf (" ");
			}
			printf ("*\n");
		}
		else {
			for (j=1; j<i; j++){
				printf (" ");
			}
			printf ("*");
			for (j=1; j<=raz1;j++){
				printf (" ");
			}
			printf ("*");
			for (j=1; j<=raz2;j++){
				printf (" ");
			}
			printf ("*");
			for (j=1; j<=raz1;j++){
				printf (" ");
			}
			printf ("*\n");
		}
		raz1=raz1-2;
		raz2=raz2+2;
	}
	return 0;
}
