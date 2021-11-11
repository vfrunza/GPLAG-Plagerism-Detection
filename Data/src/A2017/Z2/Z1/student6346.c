#include <stdio.h>

int main()
{
	int n,i,j;
	do {
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0 || n<8) printf("Neispravno N!");
		printf("\n");
	} while(n%4!=0 || n<8);

	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			if(i<=n/2 && j<=n/2) {
				if(i==j) printf("\\");
				if(j==((n/2)+1)-i) printf("/");
				if(j!=i && j!=((n/2)+1)-i) printf (" ");
			}
			if(i>n/2 && j<=n/2) {
				if((i==(n/2)+1) || (i==n)) {
					if(j==1 || j==n/2) printf("+");
					else printf("-");
				} else {
					if(j==1 || j==n/2) printf("|");
					else printf(" ");
				}
			}
			if(i<=n/2 && j>n/2) {
				if(i==1 || i==n/2) {
					if(j==n/2+1 || j==n) printf ("+");
					else printf("-");
				} else {
					if(j==n/2+1 || j==n) printf ("|");
					else printf(" ");
				}
			}
			if(i>n/2 && j>n/2) {

				if(i==(n/4)*3 || i==(n/4)*3+1) {
					if(j==(n/4)*3 || j==(n/4)*3+1) {

						printf("+");
					} else printf("-");
				} else {
					if (j==(n/4)*3 || j==(n/4)*3+1) printf ("|");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}

	return 0;
}