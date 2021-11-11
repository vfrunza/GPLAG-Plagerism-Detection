#include <stdio.h>

int main ()
{
	int n, i, j;
	char backslash=92;
	
	do 
	{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if (n%4!=0 || n<8)
		{
			printf("Neispravno N!\n");
		}
	}
	while (n%4!=0 || n<8);
	printf("\n");
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if (i==j && i<n/2 && j<n/2)
			{
				printf("%c", backslash);
			}
			else if (i+j==(n/2)-1 && i<n/2 && j<n/2) 
			{
				printf("/");
			}
			else if ( ((j==n/2 || j==n-1) && (i==0 || i==n/2-1) && (i<n/2 && j>=n/2)) || ((j==0 || j==n/2-1) && (i==n/2 || i==n-1) && (i>=n/2 && j<n/2))     )
			{
				printf("+");
			}
			else if ((j==n/2+(n/4-1) || j==n/2+(n/4)) && (i==n/2+(n/4-1) || i==n/2+(n/4)))
			{
				printf("+");
			}
			else if ((j>n/2 && j<n-1) && (i==0 || i==n/2-1))
			{
				printf("-");
			}
			else if ((j<n/2 && j>0) && (i==n/2 || i==n-1))
			{
				printf("-");
			}
			else if ((i==n/2+(n/4-1) || i==n/2+(n/4)) && ((j>=n/2 && j<n/2+(n/4-1)) || (j<n && j>n/2+(n/4))))
			{
				printf("-");
			}
			else if ((j==0 || j==n/2-1) && (i>n/2 && i<n-1))
			{
				printf("|");
			}
			else if ((j==n/2 || j==n-1) && (i<n/2-1 && i>0))
			{
				printf("|");
			}
			else if ((j==n/2+(n/4-1) || j==n/2+(n/4)) && ((i>=n/2 && i<n/2+(n/4-1)) || (i<n && i>n/2+(n/4))))
			{
				printf("|");
			}
			
			/*kraj uslova*/
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}