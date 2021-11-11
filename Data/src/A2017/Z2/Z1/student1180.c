#include <stdio.h>

int main() {
	int n,i,j;
	
	
	do
	{	
		printf("Unesite broj N: ");
		scanf("%d",&n);
		
		if(n%4!=0 || n<8)
		{
			printf("Neispravno N!");
		}
		printf("\n");
		
	}
	while(n%4!=0 || n<8);
	
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if( i==j && i<=n/2 && j<=n/2) 
				printf("\\");
			else if (i==n/2-j+1)
				printf("/");
				
			else if((i==1 && j==(n/2)+1) || (i==1 && j==n) || (i==n/2 && j==(n/2)+1) || (i==n/2 && j==n))
				printf("+");
			else if((i==1 && j>=(n/2)+2 && j<n) || (i==n/2 && j>=(n/2)+2 && j<n))
				printf("-");
			else if((i>=2 && i<n/2 && j==(n/2)+1) || (i>=2 && i<n/2 && j==n))
				printf("|");
			else if((i==(n/2)+1 && j==1) || (i==n && j==1) || (i==(n/2)+1 && j==n/2) || (i==n && j==n/2))
				printf("+");
			else if((i==(n/2)+1 && j>1 && j<n/2) || (i==n && j>1 && j<n/2))
				printf("-");
			else if((i>(n/2)+1 && i<n && j==1) || (i>(n/2)+1 && i<n && j==n/2))
				printf("|");
			else if((i>n/2 && i<3*n/4 && (j==3*n/4 || j==3*n/4+1)) || (i>3*n/4+1 && i<=n && (j==3*n/4 || j==3*n/4+1)))
				printf("|");
			else if((i==3*n/4 && j>n/2 && j<3*n/4) || (i==3*n/4 && j>3*n/4+1 && j<n+1) || (i==3*n/4+1 && j>n/2 && j<3*n/4) || (i==3*n/4+1 && j>3*n/4+1 && j<n+1))
				printf("-");
			else if(i>=3*n/4 && i<=3*n/4+1 && j>=3*n/4 && j<=3*n/4+1)
				printf("+");
			

			else 
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
