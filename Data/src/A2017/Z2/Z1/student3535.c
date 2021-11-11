#include <stdio.h>

int main() {
	
	int n,i,j,pom,pom2;
	do{
	printf("Unesite broj N: ");
	scanf("%d",&n);
	if(n<8 || n%4!=0) 
	printf("Neispravno N!\n");
	} while(n<8 || n%4!=0);
	
			pom=((n/2)+(n/2)/2)-1;
			pom2=((n/2)/2)-1;
			printf("\n");
	
	for(i=0; i<n/2; i++){
		for(j=0; j<n; j++){
			if(j<n/2){
				if(i==j) 
				printf("\\");
				else if(j==n/2-i-1) 
				printf("/");
				else printf(" ");
			}
			
			
			if(j>=n/2){
				if(i==0 || i==n/2-1){
					if(j==n/2 || j==n-1) 
					printf("+");
					else printf("-");
				}
				else{
					if(j==n/2 || j==n-1) 
					printf("|");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}
	
	
	for(i=0; i<n/2; i++){
		for(j=0; j<n; j++){
			if(j<n/2){
				if(i==0 || i==n/2-1){
					if(j==0 || j==n/2-1) 
					printf("+");
					else printf("-");
				}
				else{
					if(j==0 || j==n/2-1) 
					printf("|");
					else printf(" ");
				}
			}
			
			
			
			
			if(j>=n/2){
				if(i==0 || n/2-1){
					if((i==pom2||i==pom2+1) && (j==pom || j==pom+1)) 
					printf("+");
					else if(i==pom2 || i==pom2+1) 
					printf("-");
					else if(j==pom || j==pom+1) 
					printf("|");
					else printf(" ");
					
				}
			}
		}
		printf("\n");
	}
	return 0;
}
