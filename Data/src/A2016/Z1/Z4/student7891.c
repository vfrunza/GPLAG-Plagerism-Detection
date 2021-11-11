#include <stdio.h>

int main() {
	int i,j;
	int n=0;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while(n<=0 || n>50)
	{  printf("Pogresan unos\n");
	printf("Unesite broj n: ");
	scanf("%d", &n);



	} 
	if(n==1) printf("***\n"); else{
	for(i=0; i<n; i++)
	{
		for(j=0 ; j<=4*n-4; j++)
		{
			if(i==j || j+i==2*n-2 && i!=n-1 || j-i==2*n-2 || j+i==4*n-4) printf("*");
			else printf(" ");
			
	
		
			
		}
		printf("\n");
	
	}
	}
	
	return 0;
}
