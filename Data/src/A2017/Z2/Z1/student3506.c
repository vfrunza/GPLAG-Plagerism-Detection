#include <stdio.h>

int main() {
	int n, i=0, j=0;
	printf("Unesite cijeli broj N: ");
	scanf("%d",&n);
	do {
		for(i=0; i<n/2; i++){
			for(j=0; j<n/2; j++){
				if(i==0||i==(n/2)-1){ 
					if(j==0||j==n-1){
						printf("\\");
					}
					else{
					printf(" ");
				}
				}
				else{
					if(j==0||j==n-1){
						printf("|");
					}
					else{
						printf(" ");
					}
				}
			}printf("\n");
		} 
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i==0||i==n-1){ 
					if(j==0||j==n-1){
						printf("+");
					}
					else{
					printf("-");
				}
				}
				else{
					if(j==0||j==n-1){
						printf("|");
					}
					else{
						printf(" ");
					}
				}
			}printf("\n");
		} 
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		n=n/2;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i==0||i==n-1){ 
					if(j==0||j==n-1){
						printf("+");
					}
					else{
					printf("-");
				}
				}
				else{
					if(j==0||j==n-1){
						printf("|");
					}
					else{
						printf(" ");
					}
				}
			}printf("\n");
		} 
	} while(n%2!=0&&n<=8);
	return 0;
}
