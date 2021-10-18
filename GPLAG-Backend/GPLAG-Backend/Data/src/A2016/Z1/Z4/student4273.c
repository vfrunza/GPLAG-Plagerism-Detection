#include <stdio.h>

int main() {
	int n,i,j;
	
	do{
    printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<1 || n>50) printf("Pogresan unos\n");

	}while(n<1 || n>50);
	
	for(i=0;i<n;i++){
		for(j=0;j<(n*4)-3;j++){
			if(n==1) printf("***");
			else if(i==j || i+j==2*(n-1) || i+2*(n-1)==j || i+j==4*(n-1)) printf("*");
           else printf(" ");
		}
		printf("\n");
	}

return 0;
}