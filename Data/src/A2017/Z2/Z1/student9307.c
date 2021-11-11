#include <stdio.h>

int main()
{
	int n,i,j;
	do {
		printf ("Unesite broj N: ");
		scanf ("%d", &n);
		
		if (n<7 || n%4 != 0)
		printf ("Neispravno N!\n");
	} 
	while (n<7 || n%4 != 0);
	printf ("\n");

	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++) {

			if (i==j && j<=(n/2))
				printf ("\\");

			else if (i<=(n/2) && j<=(n/2) && (j== n/2-i+1))
				printf ("/");

			else if ((j==(n/2+1) || j==n) && j>=5 && (i==1 || i == n/2))
				printf ("+");

			else if ((i==1||i==n/2) && (j>(n/2+1)) && (j<n))
				printf ("-");

			else if (((j==(n/2 + 1)) || j==n) && i>1 && i<=(n/2))
				printf ("|");

			else if ((i==(n/2 + 1) || i==n) && i >=5 && (j==1 || j == n/2))
				printf ("+");

			else if ((j==1 || j==n/2) && (i>(n/2 +1)) && (j<n))
				printf ("|");

			else if (((i==(n/2 + 1)) || i==n) && j>1 && j<=(n/2))
				printf ("-");

			else if (i>n/2 && j>n/2 && i==(n/2+n/4) && j==(n/2+n/4))
				printf ("+");

			else if (i>n/2 && j>n/2 && i==(n/2+n/4) && j==(n/2+n/4+1))
				printf ("+");

			else if (i>n/2 && j>n/2 && j==(n/2+n/4) && i==(n/2+n/4+1))
				printf ("+");

			else if (i>n/2 && j>n/2 && j==(n/2+n/4+1) && i==(n/2+n/4+1))
				printf ("+");

			else if (i>n/2 && j>n/2 && ((j==(n/2+n/4)) || j==(n/2+n/4+1)))
				printf ("|");

			else if (i>n/2 && j>n/2 && ((i==(n/2+ n/4)) || i==(n/2 + n/4 +1)))
				printf ("-");

			else
				printf (" ");
		}
		printf ("\n");
	}
	return 0;
}
