#include <stdio.h>

int main() {
	int n,i,j;
	for(;;){
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50)
		printf("Pogresan unos\n");
		else break;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n*4-3;j++){
			if(n==1)
			printf("**");
			if(i==j || j-i==n*2-2 || j+i==n*2-2 || j==n*4-4-i)
			printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
