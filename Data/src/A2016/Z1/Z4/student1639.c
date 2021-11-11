#include <stdio.h>

int main() {
	int n,i=0;
	int j=0;
	do{printf("Unesite broj n: ");
	scanf("%d", &n);
	if (n<=0 || n>50){printf("Pogresan unos\n");}
	}
	while (n<=0 || n>50);
	if(n==1){printf("***");} 
	else{
	 	for (i=0; i<n; i++){
	 		for (j=0; j<4*n-1; j++){
	 			if (i==j || i+j==2*n-2 || i==j-2*(n-1) || i+j-3*(n-1)==n-1){printf("*");}
	    			else{printf(" ");}}
	    	 	printf("\n");}
	}
	   
		 
	return 0; 
}
