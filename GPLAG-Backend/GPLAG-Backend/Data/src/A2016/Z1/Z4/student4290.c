#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: \n");
	scanf("%d",&n);
	while((n<1)||(n>50)){
		printf("Pogresan unos \n");
		scanf("%d",&n);
	}
		
	
	
	
	for(i=0;i<(((n-1)*4)+1);i++){
		for(j=0;j<n;j++){
			while(i<n){
				if(i==j) printf("*");
				else printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
