#include <stdio.h>

int main() {
	int n,i,j;
	greska:printf("\nUnesite broj n: ");
	scanf("%d", &n);
	if (n==0 || n>50 || n<0){
		printf("Pogresan unos"); goto greska;
	} 
	else if (n==1) printf("***");
	else {
		for(i=0;i<=n-1;i++) {
			for(j=0;j<=(n+(n-1)*3);j++) {
				if(i==j || i+j==2*(n-1) || j-i==2*(n-1) || i+j==4*(n-1)) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
