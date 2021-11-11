#include <stdio.h>

int main() {
	
	int i,j,n;
	
	do{
	printf ("Unesite broj N: ");
	scanf ("%d", &n);
	if (n<8 || n%4!=0) 
	printf ("Neispravno N!\n");
	}while (n<8 || n%4!=0);
	printf ("\n");

	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			
			/* Prvi oblik */
			
			if (i==0 && j==0)
			printf ("\\");
			
			else if (i==0 && j==(n/2)-1)
			printf ("/");
			
			else if ((i==j) && (j<n/2))
			printf ("\\");
			
			else if ((j==(n/2)-1-i) && j<n/2)
			printf ("/");
			
			/* Drugi oblik */
			
			else if (i==0 && j==n/2)
			printf ("+");
			
			else if (i==0 && j==n-1)
			printf ("+");
			
			else if (i<(n/2)-1 && j==n/2)
			printf ("|");
			
			else if (i<(n/2)-1 && j==n-1)
			printf ("|");
			
			else if (i==(n/2)-1 && j==n/2)
			printf ("+");
			
			else if (i==(n/2)-1 && j==n-1)
			printf ("+");
			
			else if (i==0 && j>n/2)
			printf ("-");
			
			else if (i==(n/2)-1 && j>n/2)
			printf ("-");
			
			/* Treci oblik */
			
			else if (i==n/2 && j==0)
			printf ("+");
			
			else if (i==n/2 && j==(n/2)-1)
			printf ("+");
			
			else if (i==n/2 && j>0 && j<(n/2)-1)
			printf ("-");
			
			else if (j==0 && i<n-1 && i>n/2)
			printf ("|");
			
			else if (j==(n/2)-1 && i<n-1 && i>n/2)
			printf ("|");
			
			else if (j==0 && i==n-1)
			printf ("+");
			
			else if (j==(n/2)-1 && i==n-1)
			printf ("+");
			
			else if (i==n-1 && j>0 && j<n/2)
			printf ("-");
			
			
			/* Cetvrti oblik */
			
			else if (i==(n+(n/2))/2 && j==(n+(n/2))/2)
			printf ("+");
			
			else if (i==((n+(n/2))/2)-1 && j==(n+(n/2))/2)
			printf ("+");
			
			else if (i==(n+(n/2))/2 && j==((n+(n/2))/2)-1)
			printf ("+");
			
			else if (i==((n+(n/2))/2)-1 && j==((n+(n/2))/2)-1)
			printf ("+");
			
			else if (i>=n/2 && j==(n+(n/2))/2)
			printf ("|");
			
			else if (i>=n/2 && j==((n+(n/2))/2)-1)
			printf ("|");
			
			else if (j>=n/2 && i==(n+(n/2))/2)
			printf ("-");
			
			else if (j>=n/2 && i==((n+(n/2))/2)-1)
			printf ("-");
			
		  else 
		  printf (" ");
			
		}
		printf ("\n");
	}
	return 0;
}