#include <stdio.h>

int main() {
	int n,i,j;
	greska:
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<1){
	printf("Pogresan unos\n");
	goto greska;
	}else{
	for(i=0;i<(n+1);i++){
		
		for(j=0;j<(4*n-1);j++){
			if((j<=n-1 && i==j) || (j>n-1 && i+j==2*n-2)||(j<=3*n-3 && j-i==2*n-2) || (j>3*n-3 && i+j==4*n-4)){
				printf("*");
			} else{
				printf(" ");
			}
			
			
		}
		printf("\n");
		
	}
	}
	
	return 0;
}
