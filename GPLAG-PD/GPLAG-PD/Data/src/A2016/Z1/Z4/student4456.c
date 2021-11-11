

#include <stdio.h>

int main() {
	int n=0, i, j; 

	while(n<1 || n>50){
	printf("Unesite broj n: ");
	scanf("%d", &n);
    if(n<1 || n>50)	printf("Pogresan unos\n");
	}
	    if(n==1)printf("***");
	    else if(n!=1){
    	for(i=0; i<n; i++){
    	for(j=0; j<4*n-3; j++) {
    	if(i==j || i+j==2*n-2 || i+j==4*n-4 || j==(2*n)+i-2) printf("*");
    	else printf(" ");
    	}
    	
    	
    	printf("\n");
}
	    }
	return 0;
}
	
