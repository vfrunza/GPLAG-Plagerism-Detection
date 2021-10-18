#include <stdio.h>

int main() 
{
	int a,b,n;
    
    
	do {
	    printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50){
			printf("Pogresan unos \n");
			
		}
		
		}	while(n<=0 || n>50);
		if(n==1){
			printf("***");
			return 0;
		}
		
		for(a=0; a<n; a++)
		{
			for(b=0; b<4*n-3; b++) {
				if(a==b || 2*n-2-a==b || 2*n-2+a==b || 4*n-4-a==b) {
					printf("*");
				}
			else { 
				printf(" "); }
			
			}
	printf("\n");
		}	
	return 0;
		}
