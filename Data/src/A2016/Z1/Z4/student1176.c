#include <stdio.h>

int main() 
{
	int i, n, x, j;
	printf("Unesite broj n: ");
	scanf("%d", &n);    
	while(n<=0 || n>50){
		printf("Pogresan unos \nUnesite broj n: ");
		scanf("%d", &n);
	}
	if(n>1) { 
	x=(n*4)-3; 
	for(i=1; i<=n; i++){
		for(j=1; j<=x; j++){
			if(i==j || i+j==n*2 || j-i==((n*2)-2) || i+j==((n*4)-2)) printf("*");
			else printf(" "); 
		}  
	printf("\n");
	}  }
	else printf("***");
	return 0;
}
