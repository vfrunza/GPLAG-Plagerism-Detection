#include <stdio.h>

int main() {
	int n;
	int i,j,k,m,l;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if(n==1) {
		printf("***");
		return 0;
	}
	
	if(n<=0 || n>50) printf("Pogresan unos");
	
	while(n<=0 || n>50){	
		
		printf("\nUnesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50) printf("Pogresan unos");
	}
	
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			
			if(i==j) printf("*");
			else printf(" ");
		}
		for(k=n;k<2*n-1;k++){
			
			if(i==(2*n-2)-k) printf("*");
			else printf(" ");
		}
		for(m=2*n-1;m<3*n-2;m++){
			
			if(i==m-(2*n-2)) printf("*");
			else printf(" ");
		}
		for(l=3*n-2;l<4*n-3;l++){
			
			if(i==2*(2*n-2)-l) printf("*");
			else printf(" ");
		}
		
		
		
		printf("\n");
	}
	return 0;
}
