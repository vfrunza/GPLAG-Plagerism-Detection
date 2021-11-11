#include <stdio.h>

int main() {
	int n;
	int i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<=0 || n>50){
		printf("Pogresan unos");
		printf("\nUnesite broj n: ");
		scanf("%d",&n);
	}
	if(n==1){
		printf("***");
		return 0;
	}
	for(i=0;i<n;i++){

		for(j=0;j<=4*(n-1);j++){
			if(j<=(n-1)){
				if(j==i) printf("*");
				else printf(" ");
				}
			if(j>(n-1) && j<=2*(n-1)){
			if(i+j==2*(n-1)) printf("*");
			else printf(" ");
		}
		if(j>2*(n-1) && j<=3*(n-1)){
			if(j-i==2*(n-1)) printf("*");
			else printf(" ");	
			}
			
			if(j>3*(n-1)){
				if(j+i==4*(n-1)) printf("*");
				else printf(" ");
		}
		}

	printf("\n");
	}
	return 0;
}
