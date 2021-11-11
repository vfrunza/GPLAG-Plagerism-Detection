#include <stdio.h>

int main() {
	int n,i,j;
	do{
	printf("\nUnesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50){
		printf("Pogresan unos");
	}
	}while((n<=0 || n>50));
	for(i=0;i<n;i++){
		for(j=0;j<=4*n-2;j++){
			if(i==j || (i+j==(2*n-2)) || ((j>(2*n-2) && (j-i)==2*n-2) && j<(3*n-3)) || (j>=3*n-3 && i+j==4*n-4 && j<=4*n-4) || ((n==1 && j==0) || (n==1 && j==1) || (n==1 && j==2))){
				printf("*");
			}else{
				printf(" ");
			}
		} printf("\n");
			}
	
	return 0;
}
