	#include <stdio.h>
	#include <math.h>
	
	int main() {
		int i , j, n, k;
		
		
		for(k=0;k<100;j++){
			printf("Unesite broj n: ");
			scanf("%d", &n);
			if(n<=50 && n>0){
				break;
			}
			else {
				printf("Pogresan unos\n");
			}
		}

		
		for(i=0;i<n;i++){
			for(j=0;j<=pow(n,2);j++){
				if(i==j){		
					printf("*");
				}
			
					
				else if(i+j==2*n-2 && i!=n-1 && i!=0){
						printf("*");
					}
					
				else if(i+j==4*n-4){
					printf("*");
				}
				
				else if(j-i==2*n-2){	
					printf("*");
				}		
				
				else printf(" ");
				
			}
			printf("\n");
		}
		
		
		return 0;
	}
