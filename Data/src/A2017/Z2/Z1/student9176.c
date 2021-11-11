#include <stdio.h>

int main() {
	int i,j,n;
	do {
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0 || n<8) {
		printf("Neispravno N!\n");
		}
		}
	while(n%4!=0 || n<8);
	printf("\n");
	
	
	for(i=0; i<(n/2); i++) {
		for(j=0; j<(n/2); j++){
			if(i==j) {
				printf("\\"); }
				else if(j==(n/2)-1-i) {
					printf("/");
				}
				else printf(" ");
			
			
		}
	
		if(i==0 || i==(n/2)-1) {
			printf("+");
			for(j=0; j<(n/2)-2; j++) {
				printf("-"); }
			printf("+");
		
			}
		else {
			printf("|");
			for(j=0; j<(n/2)-2; j++) {
				printf(" ");
				
			}
			printf("|");
			
		}
		
		printf("\n");	
		
	} 
	for(i=0; i<n/2; i++) {
		
		for(j=0; j<n/2; j++) {
			if((i==j && i==0) || (i==j && i==(n/2)-1) || (i==0 && j==(n/2)-1) || (j==0 && i==(n/2)-1)) 
			printf("+");
			else {
				if(i==0 || i==(n/2)-1) printf("-");
				else { 
					if(j==0 || j==(n/2)-1) printf("|");
					else printf(" ");
				}
			}
			
		}
		if(i!=n/4 && i!=(n/4)-1) for(j=0; j<n/2; j++) {
			if(j!=(n/4) && j!=(n/4)-1) {
				printf(" ");
			}
			else printf("|");
		}
		else for(j=0; j<n/2; j++) {
			if(j!=(n/4) && j!=(n/4)-1) {
				printf("-");
			} 
			else printf("+");
			
		}
		printf("\n");
	}

	
	
	return 0;
}
