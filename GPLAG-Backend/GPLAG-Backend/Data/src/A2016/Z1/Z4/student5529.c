#include <stdio.h>

int main() {
	int n,i,j,m,polovica;
	do{
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<=0||n>50)
		printf("Pogresan unos\n");
	
	} while(n<=0||n>50);
	m=4*n;
	polovica = n*2;
	if(n==1)
	printf("**");
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m-1;j++) {
			 if(j==i || j==polovica-i || j==polovica+i-2 || j==m-i-2) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	

	return 0;
}
