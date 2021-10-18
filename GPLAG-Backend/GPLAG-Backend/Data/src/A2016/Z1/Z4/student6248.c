#include <stdio.h>

int main() {
	int i,j,n;
	do{
    printf("Unesite broj n: ");
    scanf("%d",&n);
    if(n>50 || n<=0 || n-(int)n!=0) printf("Pogresan unos\n");
	} while(n>50 || n<=0 || n-(int)n!=0);
	
	
	for(i=0; i<n; i++){
		for(j=0; j<(4*(n-2)+5); j++){
			if (n==1) printf("***");
			else if (i==j || i+(4*(n-2)+4)/2==j || i+j==(4*(n-2)+4)/2 || i+j==4*(n-2)+4) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
