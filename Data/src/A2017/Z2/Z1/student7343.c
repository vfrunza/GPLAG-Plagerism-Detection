#include <stdio.h>
#define polovina n/2
#define cetvrtina n/4

int main() {
	int n,i,j;
	           
	do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
			if(n%4!=0 || n<8) printf("Neispravno N!\n");
	
	} while (n%4!=0  || n<8);
	
	for(i=0; i<n; i++) {
		
		for(j=0; j<n; j++) 
			if(i<=polovina && j<=polovina) {
				if(i==j) 
					printf(" \ ");
		        else if(i==j-i-1
				
			
	}	
	
	return 0;
}
