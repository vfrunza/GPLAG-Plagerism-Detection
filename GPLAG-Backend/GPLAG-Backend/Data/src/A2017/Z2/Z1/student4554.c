#include <stdio.h>

int main () {
	
	int n,i,j;
	
	do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n%4==1 || n<8) {
			printf("Neispravno N!\n");
		} else break;
	} while(1==1);
	
	printf("\n");
	
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			
			/* X */
			
			if(i==j && i<n/2) printf("\\");
			else if(i<n/2 && i==n/2-1-j) printf("/");
			
			/* gornji kvadrat */
			
			else if((i==0 && j==n/2 && i<n/2) || (i==0 && i<n/2 && j==n-1)) printf("+");
			else if((i==n/2-1 && i<n/2 && j==n/2) || (i<n/2 && i==n/2-1 && j==n-1)) printf("+");
			else if((i<n/2 && i==0 && j>n/2 && j<n) || (i<n/2 && i==n/2-1 && j>n/2 && j<n)) printf("-");
			else if((i<n/2 && j==n/2 && i>0 && i<n/2-1) || (i<n/2 && j==n-1 && i>0 && i<n/2-1)) printf("|");
			
			/* donji kvadrat */
			
			else if((i==n/2 && j==0) || (i>n/2 && i==n-1 && j==0) || (i==n/2 && j==n/2-1) || (i>n/2 && i==n-1 && j==n/2-1)) printf("+");
			else if((i==n/2 && j>0 && j<n/2-1) || (i==n-1 && i>n/2 && j>0 && j<n/2-1)) printf("-");
			else if((i>n/2 && i<n-1 && j==0) || (i>n/2 && i<n-1 && j==n/2-1)) printf("|");
			
			/* plus */
			
			else if((i>n/2 && i==(n/2) + (n/4) && j==(n/2)+(n/4)) || (i>n/2 && i==(n/2)+(n/4)-1 && j==(n/2)+(n/4)-1)) printf("+");
			else if((i>n/2 && i==(n/2)+(n/4) && j==(n/2)+(n/4)-1) || (i>n/2 && i==(n/2)+(n/4)-1 && j==(n/2)+(n/4))) printf("+");
			else if((i>=n/2  && j==(n/2)+(n/4)) || (i>=n/2 && j==(n/2)+(n/4)-1)) printf("|");
			else if((i>n/2 && i==(n/2)+(n/4) && j>=n/2) || (i>n/2 && i==(n/2)+(n/4)-1 && j>=n/2)) printf("-");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
