#include <stdio.h>
int main () {
	int i,j,n;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while(n<=0 || n>50) {
		printf("Pogresan unos");
		printf("\nUnesite broj n: ");
		scanf("%d" , &n);
	}
	if(n>0 && n<=50) {
		for(i=1;i<=n;i++) {
		for(j=1;j<=4*n-3;j++){
			if ( j==i || j+i==2*n || j-i==2*n-2 || j+i==4*n-2 )
			printf("*");
			else 
			printf(" ");
			
		}
		printf("\n");
	}
	}
	
	return 0;
}
