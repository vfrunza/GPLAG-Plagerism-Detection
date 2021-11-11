#include <stdio.h>

int main() {
	printf("n");
	int n,i,j,v,h;
	scanf("%d", &n);  
	for (i=0; i<n; i++){
		for (j=0;j<n*10; j++){ 
			v= i+1; 
			h=2*n-j-1;
			if (i==j) printf("*");
				else if (v==h) printf("*"); 
				else printf(" ");
			
			if (i==j-n) printf("*");
				else if (n-i==2*j-n) printf(""); 
				else printf(" ");
			
				
		} 
		printf("\n"); }
	return 0;
}
