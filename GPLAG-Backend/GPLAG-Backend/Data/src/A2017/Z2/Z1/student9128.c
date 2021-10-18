#include <stdio.h>

int main() {
	
	int n, i, j;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n<8 || n%4!=0) {
			printf("Neispravno N! ");
			printf("\n");
		} 
	} while(n<8 || n%4!=0);
	
	printf("\n");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(i<n/2 && j<n/2) {
				if(i==j){
					printf("\\");
				} else if(i+j==n/2-1) {
					printf("/");
				} else {
					printf(" ");
				}
			}
			if(i<n/2 && j>=n/2) {
				if((j==n/2 || j==n-1) && (i==0 || i==n/2-1)) {
					printf("+");
				} else if(i==0 || i==n/2-1) {
					printf("-");
				} else if(j==n/2 || j==n-1) {
					printf("|");
				} else {
					printf(" ");
				}
			}
			if(i>=n/2 && j<n/2) {
				if((j==0 || j==n/2-1) && (i==n/2 || i==n-1)) {
					printf("+");
				} else if(i==n/2 || i==n-1) {
					printf("-");
				} else if(j==0 || j==n/2-1) {
					printf("|");
				} else {
					printf(" ");
				}	
			}
			if(i>=n/2 && j>=n/2) {
				if((i==((n/2)+(n-1))/2 || i==((n/2)+(n-1))/2+1) && (j==((n/2)+(n-1))/2 || j==((n/2)+(n-1))/2+1)) {
					printf("+");
				} else if(i==((n/2)+(n-1))/2 || i==((n/2)+(n-1))/2+1) {
					printf("-");
				} else if(j==((n/2)+(n-1))/2 || j==((n/2)+(n-1))/2+1) {
					printf("|");
				} else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
