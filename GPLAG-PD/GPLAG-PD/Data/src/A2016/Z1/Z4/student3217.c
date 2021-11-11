#include <stdio.h>
int main() {
	int  n, horizontalno, vertikalno;
	
	do {
		
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if (n <= 0 || n > 50) 
		printf("Pogresan unos\n");
	else break;
	
	} while(1);
	
	if(n==1)
	printf("**");

	for(horizontalno = 0; horizontalno < n; horizontalno++){
		
		for(vertikalno=0; vertikalno<4*n-3; vertikalno++){
			
			if(horizontalno==vertikalno || horizontalno + vertikalno==2*n-2 ||vertikalno - horizontalno == 2*n-2|| horizontalno + vertikalno == 4*n-4){
				printf("*");
				
			} else  printf(" ");
			
		}
		
		printf("\n");
		
	}
	
	return 0;
}
