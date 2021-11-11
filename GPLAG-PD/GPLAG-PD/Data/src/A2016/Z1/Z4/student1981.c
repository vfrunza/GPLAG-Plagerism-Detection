#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	

	
	while (n<=0 || n>50) {
	printf("Pogresan unos\n"); 
	printf("Unesite broj n: ");
	scanf("%d", &n);
	}
	
	 
	 if(n>0 || n<=50)
	{
	if(n==1) printf("***");	
	
	else {printf("*");
	for(i=1; i<n*2-2; i++)
	printf(" ");
	printf("*");
	
	
	
	for(i=1; i<n*2-2; i++)
	printf(" ");
	printf("*");
	
	
	
	for(i=1; i<n-1; i++){
	printf("\n");
	printf(" ");
	
	for(j=1; j<i; j++)
	printf(" ");
	printf("*");
	
	for(j=1; j<2*(n-i)-2; j++)
	printf(" ");
	printf("*");
	
	for(j=1; j<2*i; j++)
	printf(" ");
	printf("*");
	
	for(j=1; j<2*(n-i)-2; j++)
	printf(" ");
	printf("*");
}
	printf("\n");
	
	for(i=1; i<n; i++)
	printf(" ");
	printf("*");
	
	
	
	for(i=1; i<2*n-2; i++)
	printf(" ");
	printf("*");
	}
	}
	return 0;
}
