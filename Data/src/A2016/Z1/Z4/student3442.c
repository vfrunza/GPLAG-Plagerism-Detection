#include <stdio.h>

int main() {
	
	int i,j,n;
	
	for(;;){
		printf("Unesite broj n: ");
		scanf("%d", &n);
		
		if(n<=0 || n>50){
			printf("Pogresan unos\n");
			continue;
		} else break;
	}
	
	if(n==1){
		printf("***");
		return 0;
	}
	
	for(i=0;i<n;i++){
		for(j=1;j<(4*n-2);j++){
			if(j==i+1 || j==(2*n-1-i) || j==(2*n-1+i) || j==(4*n-3-i)){
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
