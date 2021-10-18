#include <stdio.h>

int main() {
	int i,j,n,a;
	
	printf("Unesite broj N: ");
	
	do{
		scanf("%d", &a);
		if(a<8 || a%4!=0) {
			printf("Neispravno N!\n");
			printf("Unesite broj N: ");
		}
		else n=a;
		
	}while(a%4!=0 || a<8);
	printf("\n");
	
	for(i=0; i<n/2; i++){
		for(j=0; j<n; j++){
			if(i==j) printf("\\");
				else if(i+j==n/2-1) printf("/");
				else if((i==0 || i==n/2-1) && (j==n/2 || j==n-1)) printf("+");
				else if((i==0 && j>n/2) || (i==n/2-1 && j>n/2)) printf("-");
				else if(j==n/2 || j==n-1) printf("|");
				else printf(" ");
					}
					printf("\n");
				}
   
         	for(i=n/2; i<n; i++){
         		for(j=0; j<n; j++){
         			if(((i==n/4*3-1 && j==n/4*3-1) || (i==n/4*3-1 && j==n/4*3) || (i==n/4*3 && j==n/4*3-1) || (i==n/4*3 && j==n/4*3)) || ((i==n/2 || i==n-1) && (j==0 || j==n/2-1))) printf("+");
         			else if((j==0 || j==n/2-1) || (j==n/4*3 || j==n/4*3-1)) printf("|");
         			else if((i==n/2 && j<n/2) || (i==n-1 && j<n/2) || (i==n/4*3 && j>=n/2) || (i==n/4*3-1 && j>=n/2)) printf("-");
         			else printf(" ");
         		}
         		printf("\n");
         	}
	
	
	return 0;
}