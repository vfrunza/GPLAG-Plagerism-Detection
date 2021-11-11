#include <stdio.h>

int main() {
	int i, j, n;
	while(1){
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<1 || n> 50){
		printf("Pogresan unos\n");
	}
	else{ break;}
	}
	
	if(n==1) {printf("***");
	return 0;}
	
	for(i=0; i<n; i++){
		for(j=0; j<i; j++){
			printf(" ");
		}
		printf("*");
		for(j=0; j<(2*n-3)-i*2; j++){
			printf(" ");
		}
		if(i!=n-1) printf("*");
		
		for(j=0; j<2*i-1; j++){
			printf(" ");
		}
		if(i!=0) printf("*");
		
		for(j=0; j<(2*n-3)-i*2; j++){
			printf(" ");
		}
		if(i!=n-1) printf("*");
		
		printf("\n");
		
	}
	return 0;
}
