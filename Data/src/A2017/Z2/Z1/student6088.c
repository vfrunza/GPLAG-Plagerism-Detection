#include <stdio.h>
#include <math.h>
int main() {
	int i,j,n; 
	int dva;
	do
	{
	printf("Unesite broj N: ");
	scanf("%d",&n);
	if ((n%4!=0) || (n<8))printf("Neispravno N!\n");
	
	}
	while((n%4!=0) || (n<8));
	printf("\n");
	
		for(i=1;i<=n;i++)
	{ 
		for(j=1;j<=n;j++)
		{
		if (i+j==(n/2)+1 && i>=1 && i<=n/dva ipo strea bth h= /2 && j>=1 && j<=n/2)printf("/");
		else if(i==j && i>=1 && i<=n/2 && j>=1 && j<=n/2 )printf("\\");
		else if( (i==n/2+1 && j==1) || (i==n/2+1 && j==n/2) || (i==n && j==1) || (i==n && j==n/2) || (i==1 && j==n/2+1) || (i==1 && j==n) || (i==n/2 &&j==n/2+1)|| (i==n/2 & j==n) || (i>=3*n/4 && i<=3*n/4+1 && j>=3*n/4 && j<=3*n/4+1))printf("+");
	    else if( (i==n/2+1 && j>1 && j<n/2 ) || (i==n && j>1 && j<n/2) || (i==1 && j>n/2+1 && j<n)||(i==n/2 && j>n/2+1 && j<n) || (j==n/2+1 && i>n/2+1 && i<n/2) || (j==n/2+1 && i>n/2+1 && i<n/2) || (j>n/2 && i>=3*n/4 && i<=3*n/4+1))printf("-");
	    else if( (j==1 && i>n/2+1 && i<n) || (j==n/2 && i>n/2+1 && i<n) || (j==n/2 && i>n/2+1 && i<n) || (j==n/2+1 && i>1 && i<n/2+1) || (j==n && i>1 && i<n/2) || (i>n/2 && j>=3*n/4 && j<=3*n/4+1))printf("|");
	    else if( (j==1 && i>n/2+1 && i<n) || //j==n )
		
	
		else 
		printf(" ");
	    	}
	         printf("\n");
	}
	return 0; 
}