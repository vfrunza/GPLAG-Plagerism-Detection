#include <stdio.h>

int main() {
	int i,n,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		if(i>=1 && i<=(n/2))
		{
			for(j=1; j<=i; j++)
			printf("\\");
			for(j=1;j<=(n/2)-i;j++)
			printf("/");
			printf("\n");
		} 

	 if (j>=(n/2)+1 && j<=n)
	
		{
				for (i=1; i<=(n/2); i++)
{
	for(j=(n/2); j<=n; j++) {
		if((i==1 && j==(n/2)) || (i==1 && j==n-1) || (i==(n/2) && j==(n/2)) || (i==(n/2) && j==n-1))
			printf("+");
		else if((i==1 || i==(n/2)) && (j>=((n/2)+1) && j<(n-1)))
			printf("-");
		else if((i>=2 && i<(n/2)) && (j==(n/2) || j==n-1))
			printf("|");
		else
			printf(" ");
	}
	printf("\n");
}
		}
		
	}printf("\n");
	return 0;
}
