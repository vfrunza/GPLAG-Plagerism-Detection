#include <stdio.h>

int main() {
	int n,i,j;
	
	do { printf("Unesite broj n: ");
	scanf ("%d", &n);
	if (n>0 && n<=50) break;
	printf("Pogresan unos\n"); }
	while (n<=0 || n>50);
	if(n==1){
		printf("***");
	}
	for (i=0;i<n*4-4;i++) {
		for(j=0;j<n-1;j++){
			if((i==j) )
			printf("*");
			else printf(" ");
		}
		for(j=n-1;j>-1;j--){
			
			if(i==j )
			printf("*");
			else printf(" ");
		}
		for(j=1;j<n-1;j++){
			if((i==j) && j>0 )
			printf("*");
			else printf(" ");
		}
		for(j=n-1;j>-1;j--){
			if(i==j )
			printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
