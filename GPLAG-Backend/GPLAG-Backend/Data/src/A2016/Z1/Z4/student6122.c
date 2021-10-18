#include <stdio.h>

int main() {
	int i , j, n, b;
	printf("Unesite broj n: ");
	scanf("%d", &n);
if(n==1)
printf("**");
while (n<=0 || n>50){
	printf("Pogresan unos\n");
	printf("Unesite broj n: ");
	scanf("%d", &n);
}
	b=(n*4)-3;
	for(i=0; i<n; i++){
	    for(j=0; j<b; j++){
	        if ((j<=j && i==j) || (j>i && j<=b/2 && j+i==b/2) || (j>b/2 && j==i+b/2) || (j<=b && j+i==b-1))
	        printf("*");
	        else printf (" ");
	    }
	    printf("\n");
	}
	
	return 0;
}
