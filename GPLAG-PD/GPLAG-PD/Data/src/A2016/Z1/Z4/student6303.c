#include <stdio.h>

int main() {
	int n, i, j;
	for(; ;) {
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(!(n>0 && n<=50)) {
		printf("Pogresan unos \n"); }
		else break;
	}
	for(i=0; i<n; i++) {
		for(j=0; j<=n+3*(n-1)-1; j++) {
				if(n==1) 
			{ 
				printf("***"); break;
				
			}
		
			else if(i==j && i<n && j<n-1) printf("*");
		    else if(i<n && j<2*n-2 && i+j==2*n-2) printf("*");
		    else if(i<n && j>=2*n-2 &&  j-i==2*n-2) printf("*");
		    else if(i+j==3*n+(n-4)) printf("*");
			else printf(" ");
		}
			if(n==1) 
			{ 
			 break;
				
			}
		printf("\n");
	}
	
	return 0;
}
