#include <stdio.h>

int main() {
	int n, i, j; 
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<1 || n>50) printf("Pogresan unos");
    else{
    	for(i=n-1; i>=1; i--){
    	//	for(j=i; j<n; j--) printf(" ");
    		for(j=0;j>i; j--) printf("*");
    	//	for(j=1; j<=n-i; j++){
    	//	printf("*");
    		
    		for(j=1; j<=2*i-1; j++)
    		printf("+");
    	
    	printf("\n");
    	}
}
    
	return 0;
}
