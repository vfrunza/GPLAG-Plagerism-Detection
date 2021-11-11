#include <stdio.h>

int main()
{
	int i,j,n;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n<8 || n%4!=0) {
			printf("Neispravno N!\n");
		}
	} while(n<8 || n%4!=0);
	printf("\n");

	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {

			if(i<=n/2) {
				if(j<=n/2) {
					if(i==j) {
						printf("\\");
					} else if(n==2*(i+j-1)) {
						printf("/");
					} else {
						printf(" ");
					}
				} else {
					if(j==(n/2+1) || j==n) {
						if (i==1 || i==n/2) {
							printf("+");
						} else {
							printf("|");
						}

					} else {
						if(i==1 || i==n/2) {
							printf("-");
						} else {
							printf(" ");
						}
					}
				}
			}

			else {
				if(j<=n/2) {
					if(j==1 || j==n/2) {
						if (i==n/2+1 || i==n) {
							printf("+");
						} else {
							printf("|");
						}

					} else {
						if(i==n || i==n/2+1) {
							printf("-");
						} else {
							printf(" ");
						}
					}
				} else {
					if(j==3*n/4 || j==3*n/4+1) {
						if(i==3*n/4 || i==3*n/4+1) {
							printf("+");
						} else if(i<3*n/4 || i>3*n/4+1) {
							printf("|");
						}
					} else if(i==3*n/4 || i==3*n/4+1) {
						printf("-");
					} else {
						printf(" ");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
