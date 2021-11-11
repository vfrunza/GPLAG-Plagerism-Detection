#include <stdio.h>

int main() {
	
	int n, d, i, j;
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	while(n>50||n<=0){printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	
	if(n==1) printf("***");
	else{
	d=n+3*(n-1);
	
	for(i=1;i<=n;i++){
		for (j=1;j<=d;j++){
			if(j==i||j==d-i+1||j==(d/2)+i||j==(d/2)+2-i) printf("*");
			else printf(" ");
		}
	printf("\n");
	
	}}
	
	return 0;
}
