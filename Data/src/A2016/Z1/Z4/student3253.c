#include <stdio.h>

int main() {
	int i, n, j;
	a: printf("Unesite broj n: ");
	
	scanf("%d", &n);
		
	if(n<=0 || n>50){
	printf("Pogresan unos \n");
	goto a;
	}
	else if(n==1){
	printf("***"); }
	else {
	int a=0, b=2*n-1, c=4*n-3;


		for (i=0; i<n; i++){
			for(j=0; j<4*n-3; j++){
		if(j==a || j==b-a-1 || j==b+a-1 || j==c-a-1){
			printf("*"); }
			else
			
			printf(" ");
		}
	
		printf("\n");
		a++;
		
	}
	}

	 
	return 0;
	 } 

