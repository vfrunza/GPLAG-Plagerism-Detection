#include <stdio.h>

int main() {
	
	int i,j,n;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n==1) printf("**");
	while(n<=0 || n>50){
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d",&n);
		
	}
	for(i=0;i<n;i++){
		for(j=0;j<4*n-3;j++){
			if(i==j && j<n ) printf("*");
			else if(j==2*n-1-i-1 && j<2*n-1) printf("*");
			else if(j==2*n-2+i && j>=2*n-1) printf("*");
			else if(j==4*n-3-i-1 && j<4*n-3) printf("*");
			else printf(" ");
			
		}
		printf("\n");
		
	}
	return 0;
}
