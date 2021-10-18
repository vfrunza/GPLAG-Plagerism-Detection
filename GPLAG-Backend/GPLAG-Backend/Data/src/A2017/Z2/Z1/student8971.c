#include <stdio.h>

int main() {
	int n, i=0, j=0;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n%4!=0 || n<8) printf("Neispravno N!\n");
	} while(n%4!=0 || n<8);
	
	printf("\n");
	for(i=0; i<n; i++) {
		if(i<n/2) {
			for(j=0; j<n; j++) {
				if(j<n/2) {
					if(j==i) printf("\\");
					else if(j==n/2 - 1 - i) printf("/");
					else printf(" ");
				}
				else {
					if(i==0 || i==n/2 - 1) {
						if(j==n/2 || j==n - 1) printf("+");
						else printf("-");
					}
					else {
						if(j==n/2 || j==n - 1) printf("|");
						else printf(" ");
					}
				}
			}
			printf("\n");
		}
		else {
			for(j=0; j<n; j++) {
				if(j<n/2) {
					if(i==n/2 || i==n - 1) {
						if(j==0 || j==n/2 - 1) printf("+");
						else printf("-");
					}
					else {
						if(j==0 || j==n/2 - 1) printf("|");
						else printf(" ");
					}
				}
				else {
					if(i==(3*n)/4 - 1 || i==(3*n)/4) {
						if(j==(3*n)/4 - 1 || j==(3*n)/4) printf("+");
						else printf("-");
					}
					else {
						if(j==(3*n)/4 - 1 || j==(3*n)/4) printf("|");
						else printf(" ");
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
