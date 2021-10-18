#include <stdio.h>

int main() {
	int i,j,n;
	do{
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n<=0 || n>50) printf("Pogresan unos\n");
	}while(n<=0 || n>50);
	if(n==1){ 
		for(i=0;i<(2*n);i++){
			printf("*");
		}
	}
		for(i=1;i<=n;i++){
			for(j=1;j<=(4*n-3);j++){
				if(i==j || i+j==2*n || j-i==(2*n-2) || (i+j)==(4*n-2)) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
		
	
	return 0;
}
