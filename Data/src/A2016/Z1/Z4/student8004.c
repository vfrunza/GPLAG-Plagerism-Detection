#include <stdio.h>

int main() {
	int i,j,n;
greska:
	printf("\nUnesite broj n: ");
	scanf("%d",&n);
	if((n<1) || n>50){
		printf("Pogresan unos");
		goto greska;
	}
	if(n==1){
	printf("***");
	return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=(4*n-3);j++){
			if((i==j) || (i+j==2*n))
			printf("*");
			else if(i+j==2*n+2*(i-1))
			printf("*");
			else if(i+j==4*n-2)
			printf("*");
			else printf(" ");
		}
		printf("\n");
		}
	return 0;
}
