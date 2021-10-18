#include <stdio.h>

int main() {
	
	int n;
	int i,j;
	int duzina;
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	while(n>50||n<=0){
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d", &n);	}
		
			duzina=4*n-3;
		
		if(n==1) printf("***");
		
		else{
		
		for(i=0; i<n; i++){
			for(j=0;j<duzina; j++){
				if(j==i) printf("*");
				else if(j==duzina/2-i) printf("*");
				else if(j==duzina/2+i) printf("*");
				else if(j==duzina-1-i) printf("*");
				else printf(" ");
			}
			printf("\n");
		}}
	return 0;
}
