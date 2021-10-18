/*
\  /+--+ 			
 \/ |  |            
 /\ |  |            
/  \+--+            
+--+ ||             
|  |-++-            
|  |-++-            
+--+ ||             

*/


#include <stdio.h>

int main() {
	int i,j,n,a;
	do
	{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if (n%4!=0 || n<8)
			printf("Neispravno N!\n");
	}while(n<8 || n%4!=0);
	
	a=n/2;
	printf("\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<n;j++)
		{
			if (i==j && j<n/2)
				printf("\\");
			else if (j<n/2 && (i+j)==(n/2-1))
				printf("/");
			else if ((i==0 && j==n/2) || (i==0 && j==n-1) || (i==a-1 && j==n/2) || (i==a-1 && j==n-1))
				printf("+");
			else if ((j>n/2 && i==0) || (j>n/2 && i==a-1))
				printf("-");
			else if (j==n/2 || j==n-1)
				printf("|");
			else 
				printf(" ");
		}		
		printf("\n");	
	}

	for(i=0;i<a;i++)
	{
		for(j=0;j<n;j++)
		{
			if ((i==0 && j==0) || (i==0 && j==n/2-1) || (i==a-1 && j==0) || (i==a-1 && j==n/2-1))
				printf("+");
			else if ((i==0 && j<n/2) || (i==a-1 && j<n/2))
				printf("-");
			else if ((j==0 || j==n/2-1))
				printf("|");
			else if ((i==a/2 && ((j==(3*n)/4-1) || (j==(3*n)/4))) || (i==(a/2)-1 && (j==(3*n)/4 || j==(3*n)/4-1)))
				printf("+");
			else if ((i==(a/2)-1 && j>=n/2) || (i==(a/2) && j>=n/2))
				printf("-");
			else if ((j==(3*n)/4) || (j==(3*n)/4-1))
				printf("|");
			else 
				printf(" ");	
		}
		printf("\n");
	}


	return 0;
}
