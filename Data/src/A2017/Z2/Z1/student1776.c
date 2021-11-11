#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite velicinu N: ");
	scanf("%d",&n);
	for(i=0;i<=(n-1);i++){
		for(j=0; j<(n); j++){
			if(i==0 || i==n-1){
				if(j==0 || j==n-1){
				printf("+");	
				}
				else{	printf("-");}
			}	
			else{
					if(j==0 || j==n-1){
				printf("|");	
				}
				else{printf(" ");}
			
			}
					
			
		}
			printf("\n");	
			}
	
	return 0;
}
