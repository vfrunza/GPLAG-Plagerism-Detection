#include <stdio.h>

int main() {
	int n,i,j;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n%4!=0 || n<8) {
			printf("Neispravno N!\n");
		} else {
			continue;
		}
	} while (n%4!=0 || n<8);
	printf("\n");
	for (i=0;i<n;i++) {
		
		for(j=0;j<n;j++) {
			
			if(i<n/2) {
				if(j<n/2) {
					if(i==j) {
					printf("\\");
					} else if (i+j==(n/2)-1) {
					printf("/");
					} else {
					printf(" ");
					}
					}
				if(j>=n/2) {
					if((i==0 && (j==(n/2) || j==n-1)) || (i==(n/2)-1 &&(j==(n/2) || j==n-1))) {
					printf("+");
					} else if (i==0 || i==(n/2)-1) {
					printf("-");
					} else if ((j==n-1 && i<n/2) || (j==n/2 && i<n/2)) {
					printf("|");
					} else {
					printf(" ");
					}
					}
			} else {
				if(j<n/2) {
					if((i==n/2 && (j==(n/2)-1 || j==0)) || (i==n-1 && (j==0 || j==(n/2)-1))) {
					printf("+");
					} else if (j<n/2 && (i==n/2 || i==n-1)) {
					printf("-");
					} else if(j==0 || j==(n/2)-1) {
					printf("|");
					} else {
					printf(" ");
					}
					} 
				if(j>=n/2) {
					if ((j==3*n/4) || (j==((3*n/4)-1))) {
						if (i==3*n/4) {
							printf("+");
						} else if (i==((3*n/4)-1)) {
							printf("+");
						} else { 
							printf("|");
						}
					} else if ((i==3*n/4) || (i==(3*n/4)-1)) {
						if (j==3*n/4) {
							printf("+");
						} else if (j==((3*n/4)-1)) {
							printf("+");
						} else {
							printf("-");
						}
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
