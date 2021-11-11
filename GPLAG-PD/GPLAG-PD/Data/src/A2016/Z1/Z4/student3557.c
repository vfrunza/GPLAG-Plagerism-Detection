#include <stdio.h>

int main() {
	
	int n, i=1, j=1;
	
	
	for(;;) {
		printf("Unesite broj n: ");
	    scanf("%d" , &n); 
		if(n==0 || n>50 || n<0) printf("Pogresan unos\n");
		
		else break;
	}
	
	if(n==1) {
		printf("***");
		return 0; 
		
	} 
	
	for( i=0; i<n; i++) {
		for(j=0; j<4*n-3 ; j++){
		
		if( i==j ||  i+j==2*n-2 || i+j==4*n-4 || j==2*n+i-2 )  printf("*");
		
		 else printf(" "); 
	
		
	}
	printf("\n");
}
return 0;
}