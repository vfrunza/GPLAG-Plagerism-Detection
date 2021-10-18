#include <stdio.h>

int main() {
	int n ;
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50){
	printf("Pogresan unos", n);
	}
	int j,i,k,l;
	printf("\n");
	for(i=0;i<n;i++){
		printf("*");
		printf("\n");
	for(j=0;j<=i;j++)
		printf("  ");
	}
	for(k=0;k<i-n;k++){
	printf("*");
	printf("        ");
	}
	
	return 0;
}
