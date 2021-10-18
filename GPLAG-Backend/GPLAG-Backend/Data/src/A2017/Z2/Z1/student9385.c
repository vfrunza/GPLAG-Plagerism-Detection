#include <stdio.h>

int main()
{
	int i,j ,N;
	printf ("N=");
	scanf ("%d", &N);

	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
		if (i==0 && j==N-N/2  || i==N-N/2-1 && j==N-N/2 || i==N-N/2-1 && j==N-1) printf ("+");
		else if (i==0 || i==N-N/2-1) printf ("-");
		else if (j==N-N/2 || j==N-1) printf ("|");
		else printf (" ");
		}
		printf ("\n");
	}


	return 0;
}
