#include <stdio.h>

int main() {
	
	int n, i, j, k;
	
	printf("Unesite N: ");
	scanf("%d", &n);
	
	k=n/2-2;
	
	
	for (i=1; i<=n; i++)
	{

		
		for (j=1; j<=n; j++)
		{
			if (i==1 && j==1) printf("\\");
			if (i==1 && j==n/2) printf("/");
			else if (i==1 && j<n/2) printf(" ");
			if (i==1 && j==n/2+1 || i==1 && j==n) printf("+");
			if (i==1 && j>n/2+1 && j<n) printf("-");
			
			
		   	if (i==2 && j==2) printf("\\");
			if (i==2 && j==1  || i==2 && j==n/2+1 || i==2 && j==n ) printf(" ");
			if (i==2 && j==n/2-1) printf("/");
			if (i==2 && j==n/2+1 || i==2 && j==n) printf("|");
			
		}
		
		printf("\n");
		
		
		
		
	}
	return 0;
}
