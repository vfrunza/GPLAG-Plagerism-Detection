#include <stdio.h>

int main() {
	int n, i, j;
	do{
		printf("\nUnesite broj n: ");
		scanf("%d", &n);
		if (n>50 || n<=0) printf("Pogresan unos");
	}while(n>50 || n<=0);
	if(n==1) printf("***");
	else{
	for (i=1; i<=n; i++){
		for(j=1; j<=(4*n-3); j++){
			if(j==i) printf("*");
			else if(j==i+2*n-2) printf("*");
			else if(j==2*n-i) printf("*");
			else if(j==4*n-i-2) printf("*");
			else printf(" ");
		}
		/*for(j=i;j<=(4*n-3); j++){
			if(j==2*n-1) printf("*");
			else if(j==4*n-3) printf("*");
		}*/
		printf("\n");
	}
	}
	return 0;
}
