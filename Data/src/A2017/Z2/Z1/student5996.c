#include <stdio.h>

int main()
{
	int n=0;
	int i;
	int j;

	do {
		printf("Unesite broj N: ");
		scanf ("%d", &n);
		if (n%4!=0 || n<8) {
			printf("Neispravno N!\n");
		}
	} while (n%4!=0 || n<8);
	printf("\n");

	for(i=0; i<n; i++) {
		if(i<(n/2)) {
			for(j=0; j<n; j++) {
				if(j<(n/2)) {
					if (i==j) printf("\\");
					else if(i==(n/2-j-1)) printf("/");
					else printf(" ");
				}
				else {
					if(i==0 || i==(n/2-1) ) {
						if(j==n-1 || j==n/2) printf("+");
						else printf("-");
					}
				
					else
					{
						if(j==n-1 || j==n/2) printf("|");
						else printf(" ");
					}
				}
			}
		} else {
			for(j=0; j<n; j++) {
				if(j<(n/2)) {
					if (i==n-1 || i==n/2) {
						if (j==n/2-1 || j==0) printf("+");
						else printf("-");

					} else {
						if(j==n/2-1 || j==0) printf("|");
						else printf(" ");
					}
				} else {
					if((i==n/2+n/4-1 || i==n/2+n/4) && (j==n/2+n/4-1 || j==n/2+n/4)) printf("+");
					else if(i==n/2+n/4-1 || i==n/2+n/4) printf("-");
					else if(j==n/2+n/4-1 || j==n/2+n/4) printf("|");
					else printf (" ");
				}
			}
		}

		printf("\n");
	}
	return 0;
}
