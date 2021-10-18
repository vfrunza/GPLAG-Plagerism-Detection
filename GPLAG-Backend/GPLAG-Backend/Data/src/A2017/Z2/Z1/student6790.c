#include <stdio.h>

int main() {
	int n,i,j;
	
	do {
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if((n%4!=0) || (n<8)) printf("Neispravno N!\n");
	} while ((n%4!=0) || (n<8));
	printf("\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			
			if((i>0 && i<=n/2) && (j>0 && j<=n/2)) {
				if(i==j) printf("\\");
				else if((i+j==(n/2+1))) printf("/");
				else printf(" ");
			}
			
			else if ((i>0 && i<=n/2) && (j>n/2 && j<=n)) {
				if ((i==1 && j==n/2+1) || (i==1 && j==n) || (i==n/2 && j==n/2+1) || (i==n/2 && j==n)) printf("+");
				else if((i==1 && j>n/2+1 && j<n) || (i==n/2 && j>n/2+1 && j<n)) printf("-");
				else if((j==n/2+1 && i>1 && i<n/2) || (j==n && i>1 && i<n/2)) printf("|");
				else printf(" ");
			}
			
			else if ((i>n/2 && n<=n) && (j>0 && j<=n/2)) {
				if ((i==n/2+1 && j==1) || (i==n/2+1 && j==n/2) || (i==n && j==1) || (i==n && j==n/2)) printf("+");
				else if((i==n/2+1 && j>1 && j<n/2) || (i==n && j>1 && j<n/2)) printf("-");
				else if((j==1 && i>n/2+1 && i<n) || (j==n/2 && i>n/2+1 && i<n)) printf("|");
				else printf(" ");
			}
			
			else {
				if ((i==(n+n/2)/2) || (i==(n+n/2+2)/2)) {
					if ((j==(n+n/2)/2) || (j==(n+n/2+2)/2)) printf("+");
					else printf("-");
				}
				else if ((j==(n+n/2)/2) || (j==(n+n/2+2)/2)) {
					if((i!=(n+n/2)/2) || (i!=(n+n/2+2)/2)) printf("|");
				}
				else printf(" ");
			}
			
			
			
		}
		printf("\n");
	}
	
	
	return 0;
}
