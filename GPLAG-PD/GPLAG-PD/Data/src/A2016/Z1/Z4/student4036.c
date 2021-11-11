#include <stdio.h>

int main() {
    int i,j,n;
    do {
	printf("Unesite broj n: ");
	scanf ("%d",&n);
	if (n<=0 || n>50)
		printf("Pogresan unos\n");
	else break;
	} while (1);
	if (n==1)
	printf("**");
	
	for (i=0; i<n;i++){
    for (j=0;j<4*n-3;j++){
    	if (i==j)
    	printf("*");
    	else if (j==2*(n-1)-i)
    	printf("*");
    	else if (j==2*(n-1)+i)
    	printf("*");
    	else if (j==4*(n-1)-i)
    	printf("*");
    	else printf(" ");
    }	
    printf("\n");
	}
    
	return 0;
}
