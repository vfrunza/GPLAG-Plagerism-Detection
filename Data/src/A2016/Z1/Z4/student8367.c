#include <stdio.h>

int main() {
	int n;
	int i, j;
	
	for(;;)
	{printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50)
	{printf("Pogresan unos\n");
	continue;}
	else break;}
	
	
	if(n==1)printf("***");
	
	else{
		
	for(i=1; i<=n; i++)
	{for(j=1; j<=3+4*(n-1); j++)
	
	{if(i==j) printf("*"); 
	
	if(i+j==2*n-1 && (i!=n && j!=n-1)) printf("*"); 
	
	
	if(j-i==2*n-4 && i!=1 && i!=n) printf("*");
	
	if(i==n && j==3*(n-1)) printf("*");
	
	if(i!=n && i!=1 && i+j==4*(n-1)-1) printf("*");
	
	if(i==1 && j==4*(n-1)-1) printf("*");
	
	
	else printf(" ");
	}
	printf("\n");
	}
	}


	return 0;
}
