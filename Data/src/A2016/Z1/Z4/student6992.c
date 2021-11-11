#include <stdio.h>

int main() {
	int i, j, n;
	while(1){
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if(n<=0 || n>50) {
	printf("Pogresan unos\n");
	continue;
	} 
	else if(n==1){
	printf("***");
	break;
	}
	else {
	for(j=0;j<n;j++) {
		for(i=0;i<4*n-3;i++) {
			if(j<n-1 && (i==j))
			printf("*");
			else if((j>=n-1 || j<2*n-2) && i+j==2*n-2)
			printf("*");
			else if((j>=2*n-2 || j<3*n-3) &&  i==j+2*n-2)
			printf("*");
			else if((j>=3*n-3 || j<4*n-4) && i+j==4*n-4)
			printf("*");
			else 
			printf(" ");
		}
		printf("\n");
	}
	break;
	}
	}
	return 0;
}
