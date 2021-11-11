#include <stdio.h>

int main() {
	
	int i,j ;
	int n ;
	
	do{
		printf("Unesite broj n: ");
		scanf("%d",&n);
	if(n<1 || n>50){							/*j==n-1-i+n-1 */
		printf("Pogresan unos\n");
	}else{
		
		for(i=0;i<n;i++){
			
			for(j=0;j<=4*n-4;j++){
				if(n==1){printf("***");}else
				if((j==i &&  j<=n-1) || (j==4*n-4-i && j>=3*n-3) || (j==2*n-2-i && i<=n-1) || (j==i+2*n-2 && i<=n-1)){
				printf("*");
				}else {printf(" ");}
			}
			
			printf("\n");
		}	
		
	}
	}while(n<1 || n>50);
	return 0;
}
