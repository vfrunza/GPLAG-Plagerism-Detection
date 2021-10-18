#include <stdio.h>

int main() {
	int i,j,n;
	
	
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0 || n<8)
			printf("Neispravno N!\n");
			continue;
	}while(n%4!=0 || n<8);
	printf("\n");
	
	for(i=0;i<n/2;i++){
		for(j=0;j<n;j++){
			if(j<n/2){
				if(i==j) printf("\\");
				else if(i+j==(n/2)-1) printf("/");
				else printf(" ");/*Prva figura, gornja lijeva*/
			}
				if(j>=n/2){
					if((i==0 && j==n/2) || (i==0 && j==n-1) || (i==n/2-1 && j==n/2) || (i==n/2-1 && j==n-1)) printf("+");
					else if(i==0 || i==n/2-1) printf("-");
					else if(j==n/2 || j==n-1) printf("|");
					else printf(" ");     /*Druga figura, gornja desna*/
				}
				
				
			}
		printf("\n");
	}
	
	for(i=0;i<n/2;i++){
		for(j=0;j<n;j++){
			if(j<n/2){
				if((i==0 && j==n/2-1) || (i==0 && j==0) || (i==n/2-1 && j==0) || (i==n/2-1 && j==n/2-1)) printf("+");
				else if(i==0 || i==n/2-1) printf("-");
				else if(j==0 || j==n/2-1) printf("|");
				else printf(" ");
			}
			
			if(j>=n/2){
				if((i==n/4-1 || i==n/4) && (j==n/2 + n/4-1 || j==n/2 + n/4)) printf("+");
				else if((i==n/4-1 || i==n/4)&&(j<(n/2+n/4)||j>(n/2+n/4))) printf("-");
				else if((j==n/2 + n/4-1 || j==n/2 + n/4)&&(i<(n/4)||i>(n/4))) printf("|");
				else printf(" ");
			}
			
		}printf("\n");
	}	


	return 0;
}
