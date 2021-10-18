#include <stdio.h>

int main() {
	int i,j,n;
	
	do{ 
		printf("Unesite broj N: ");
		scanf("\n%d",&n);
		if(n%4!=0 || n<8) printf("Neispravno N!");
		printf("\n");
	}
	while(n%4!=0 || n<8);
	
	
	 for(i=1;i<=n;i++){
	 	for(j=1;j<=n;j++){
	 		if((i==n && j==1) ||(i==n/2+1 && j==1) || (j==n/2 && i==n/2+1) ||(i==n && j==n/2) || (j==n/2+1 && i==1) || (j==n && i==1) || (i==n/2 && j==n/2+1) || (i==n/2 && j==n))
	 		 printf("+");
	 		else if((i==n/2+1 && j<n/2) || (i==n && j<n/2) || (i==1 && j>n/2) || (i==n/2 && j>n/2)) 
	 		 printf("-");
	 		else if((j==1 && i>n/2+1) || (j==n/2 && i>n/2+1) || (j==n/2+1 && i<n/2) ||(j==n && i<n/2) )
	 		 printf("|") ;
	 		else if((i==j && j<n/2+1 && i<n/2+1) )
	 		 printf("\\");
	 		 else if(i+j==n/2+1)
	 		 printf("/");
	 		
	 		 else if((i==n-(n/4-1) && j==n-(n/4-1)) || (i==n-(n/4-1) && j==n-(n/4)) || (i==n-(n/4) && j==n-(n/4-1)) || (i==n-(n/4) && j==n-(n/4)))
	 		 printf("+");
	 		  else if((j>n/2 && i==n-(n/4-1))|| (j>n/2 && i==n-(n/4)) )
	 		 printf("-");
	 		 else if((i>n/2 && j==n-(n/4)) || (i>n/2 && j==n-(n/4-1)))
	 		 printf("|");
	 	else printf(" ");
	 	}
	 	printf("\n");
	 }
	return 0;
}
