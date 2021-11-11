#include <stdio.h>
int main(){
	int n,i,j;
	greska: printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n < 1){
		printf("Pogresan unos\n");
		goto greska;
		
	}
	if(n == 1){
		printf("***");
		return 0;
	} else if(n <= 0 || n > 50){
		printf("Pogresan unos\n");
		goto greska;
	}
	for(i = 1; i <= n;i++){
		for(j = 1; j <= 4*n-3;j++){
			if(i == j){
				printf("*");
				
			} else if(j == 2*n-i){
				printf("*");
				
			}else if(j == 2*n - 2 + i  ){
				printf("*");
				
			}else if(j == 4*n - 2 - i){
				printf("*");
				}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	
return 0;	
}
	
 