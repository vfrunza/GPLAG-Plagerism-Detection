#include <stdio.h>

int main() {
	
	int n,i,j;
	


	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n%4!=0 || n<8){
			printf("Neispravno N!\n");
		}
	} while(n%4!=0 || n<8);
	
	printf("\n");
	for(i=0;i<n;i++){
		
		for(j=0;j<=n;j++){
			
			if(j==n) printf("\n");
			
			else{
			
				if(i<n/2 && j<n/2){
				 if(i==j && i+j<=n-2) printf("\\");
				 else if(i+j==(n-2)/2) printf("/");
				 else printf(" ");}
				
				 
				
				if(i<n/2 && j>=n/2){
				 if(i==0 && (j==n/2 || j==n-1)) printf("+");
		
				 else if(i==(n-2)/2 && (j==n/2 || j==n-1)) printf ("+");
			
				 else if(i==0 && (j>n/2 &&  j<n-1)) printf("-");
			
				 else if(i==(n-2)/2 && (j>n/2 &&  j<n-1)) printf("-");
				
				 else if(j==n/2 && i<n/2 && (i!=0 && i!=(n-2)/2)) printf("|");
				
				 else if(j==n-1 && i<n/2 && (i!=0 && i!=(n-2)/2)) printf("|");
				 
				 else printf(" ");
				}
				
				if(i>=n/2 && j<n/2){
					
				if(j==0 && (i==n/2 || i==n-1)) printf("+");
				
				else if(j==(n-2)/2 && (i==n/2 || i==n-1)) printf ("+");
				
				else if(j==0 && (i>n/2 &&  i<n-1)) printf("|");
				
				else if(j==(n-2)/2 && (i>n/2 &&  i<n-1)) printf("|");
				
				else if(i==n/2 && j<n/2 && (j>0 && j<(n-2)/2)) printf("-");
				
				else if(i==n-1 && j<n/2 && (j>0 && j<(n-2)/2)) printf("-");
				
				else printf(" ");
				}
				
				if(i>=n/2 && j>=n/2){
					
				if(i==n/2 + n/4 -1 && (i==j || j==i+1 )) printf("+");
			
				else if(i==n/2 + n/4 && (i==j || j==i-1)) printf ("+");
				
				else if(i==n/2 + n/4 -1 && j>(n-2)/2 && (i!=j && j!=i+1 )) printf("-");
			
				else if(i==n/2 + n/4 && j>(n-2)/2 && (i!=j || j!=i-1)) printf ("-");
				
				else if(j==n/2 + n/4 -1 && i>(n-2)/2 && (i!=j && j!=i-1 )) printf("|");
				
				else if(j==n/2 + n/4 && i>(n-2)/2 && (i!=j || j!=i+1)) printf ("|");
				
				else printf(" ");
				}
				

			}	
				
		}
	}
	return 0;
}
