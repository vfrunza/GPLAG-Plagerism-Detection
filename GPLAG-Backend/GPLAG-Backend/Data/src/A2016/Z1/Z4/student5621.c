#include <stdio.h>

int main() {
	int n,x,y;
	do{ 
		printf("Unesite broj n: ");
		scanf ("%d", &n); 
		if (n<=0 || n>50) {
			printf ("Pogresan unos \n");
		} 
	} while (n<=0 || n>50);
	
	if(n==1){
		printf("***");
		return 0;
	}
	
	for (x=0; x<n; x++){
		for(y=0; y<4*n-3; y++){
			if(x==y || y==2*n-2-x || y==2*n-2+x || y==4*n-4-x){
				printf("*");
				
			}
			else { printf(" ");}
		}
		printf("\n");
	}
	
	return 0;
}
