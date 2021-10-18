#include <stdio.h>
int main() {
	int i,j;
	int n;
	do {
	printf("Unesite broj N: ");
	scanf("%d", &n);
	if(n%4!=0 || n<8) printf("Neispravno N!\n");
	}while(n%4!=0 || n<8); 
	printf("\n");
	for(i=0; i<=n; i++) {
		for(j=0; j<n; j++) {
			if(i<n/2 && j<n/2 && i==j) {
			printf("\\");
			}
			else if(i<n/2 && j<n/2 && i+j==n/2-1) {
				printf("/");
			}
			else if(i<n/2 && j>=n/2) {
				if(i==0 || i==n/2-1) {
					if(j==n/2 || j==n-1)
				printf("+");
				else printf("-");
			}
			if(i>0 && i<n/2-1) {
				if(j==n/2 || j==n-1) printf("|");
				else printf(" ");
			}
			}
				else if(i>=n/2 && j<n/2) {
				if(i==n/2 || i==n-1) {
					if(j==0 || j==n/2-1)
				printf("+");
				else printf("-");
			}
			if(i>n/2 && i<n-1) {
				if(j==0 || j==n/2-1) printf("|");
				else printf(" ");
			}
			}
			else if(i>n/2-1 && (j==((n/2)+((n/2)/2)) || j==(n/2)+((n-1)/2)/2) && i<n && i!=(n/2)+n/4-1 && i!=(n/2)+n/4) printf("|"); 
			else if((i==(n/2)+(n/2)/2 || i==(n/2)+(n/2)/2-1) && j<n && j>n/2-1 && j!=(n/2)+n/4-1 && j!=(n/2)+n/4) printf("-");	
			else if((i==(n/2)+(n/4) || i==(n/2)+(n/4)-1) && (j==n/2+(n/4) || j==n/2+(n/4)-1 || j==n/2+(n/4)-2)) printf("+");
			else printf(" ");
	}
	printf("\n");
}
	return 0;
}
