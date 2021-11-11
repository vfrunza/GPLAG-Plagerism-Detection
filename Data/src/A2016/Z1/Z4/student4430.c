#include <stdio.h>

int main() {
	 int n, i, j;
	 Labela:
	 printf("Unesite broj n: ");
	 scanf("%d", &n);
	 if(n<1 || n>50){
	 	printf("Pogresan unos\n");
	 	goto Labela;
	 }
	 if(n==1){ printf("***"); return 0;}
	 for(i=0; i<n; i++){
	 	for(j=0; j<(4*n)-1 ; j++){
	 		if(i==j) printf("*"); 
	 		else if(j>n-1 && i<n-1 && i+j==2*n-2) printf("*"); 
	 		else if(i==(j-(2*n-2))) printf("*"); 
	 		else if(i==n-1 && j==(n*3-3)) printf("*"); 
	 		else if(j>3*n-3 && i<n-1 && i+j==(4*n)-4) printf("*");
			else printf(" ");
	 
	 		
	 	}
	 	printf("\n");
	 }
	 
	 
	 
	 
	return 0;
}
