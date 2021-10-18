#include <stdio.h>

int main() {
//	printf("Zadaća 1, Zadatak 4");

	//printf ("Unesite broj n: ");
	int n;
	
	/*do {
		printf ("Unesite broj n: ");
		scanf ("%d", &n);	
	} while (n>0 && n<51);
	*/
	unos:
		printf ("Unesite broj n: ");
		scanf ("%d", &n);
		if (n<1 || n>50)  {
			printf ("Pogresan unos \n");
			goto unos;
		};
		
		
	int i, j, r;
	
//	if (i==1) printf ("***");
	
	for (i=1; i<=n; i++) {
		
		if (i==1) {
			printf ("*");
			if (n==1) r=0;
			else if (n==2) r=1;
			else if (n==3) r=3;
			else if (n==4) r=5;
			else r=(2*(n-i)-1);
			for (j=1; j<=r; j++) printf (" ");
			printf ("*");
			for (j=1; j<=r; j++) printf (" ");
			printf ("*\n");
		}
		
		else if (i==n) {
			for (j=1; j<=(n-1); j++) printf (" ");
			printf ("*");
			for (j=1; j<=2*n-3; j++) printf (" ");
			printf ("*");
			//for (j=1; j<=(n-1); j++) printf (" ");
		}
		
		else {
			for (j=1; j<=(i-1); j++) printf (" ");
			printf ("*");
			if (i==n-1) printf (" *");
			else {
				for (j=1; j<=(2*(n-i)-1); j++) printf (" ");
				printf ("*");
			}
			if (i==2) r=1;
			else if (i==3) r=3;
			else if (i==4) r=i+1;
		//	else if (i==5) r=(2*(n-i)-1);
			else r=2*i-3;
			for (j=1; j<=r; j++) printf (" ");
			printf ("*");
		//	if (i==n) r
			for (j=1; j<=2*(n-i)-1; j++) printf (" ");
			printf ("*");
			for (j=1; j<=(i-1); j++) printf (" ");
			printf ("\n");
		}
		
	}

	return 0;
}
