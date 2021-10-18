#include <stdio.h>

int main() {
	
	int i,j,n;
	
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n<8 || n%4!=0)
		printf("Neispravno N!\n");
	}while(n<8 || n%4!=0);
	 
	 printf("\n");
	for(i = 0; i < n; i++){
		
		for(j = 0; j < n; j++){
			
			if(i>=0 && i<n/2 && j>=0 && j<n/2 && i==j)     
			printf("\\");
			else if(i>=0 && i<n/2 && j>=0 && j<n/2 && i+j==n/2-1)  
			printf("/");
			else if( ( (i==0 && (j==n/2 || j==n-1)) || ( i==n/2-1 && (j==n/2 || j==n-1) ) ) || ( (i==n/2 && (j==0 || j==n/2-1) ) || (i==n-1 && (j==0 || j==n/2-1) ) ) || ( i>=n-(n/2)/2-1 && i<=n-(n/2)/2 && j>=n-(n/2)/2-1 && j<=n-(n/2)/2 ) )                 
			printf("+");
			else if( ( (i==0 || i==n/2-1) && (j>n/2 && j<n-1) ) || ( (i==n/2 || i==n-1) && (j>0 && j<n/2-1) )  || ( i>=n-(n/2)/2-1 && i<=n-(n/2)/2 && j!=n-(n/2)/2-1 && j!=n-(n/2)/2 && j>=n/2 ) )
			printf("-");
			else if( ( i>0 && i<n/2-1 && (j==n/2 || j==n-1) ) || ( i>n/2 && i<n-1 && (j==0 || j==n/2-1) ) || ( i>=n/2 && j<n && i!=n-(n/2)/2-1 && i!=n-(n/2)/2 && j>=n-(n/2)/2-1 && j<=n-(n/2)/2 ) )
			printf("|");
			else
			printf(" ");
				
		}
		printf("\n");
	}
	return 0;
}
