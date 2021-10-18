#include <stdio.h>

int main() 
{
	int n=0,i,j;
	
	do
	{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n<8 || n%4!=0)
		{
			printf("Neispravno N!\n");
		}
	}while(n<8 || n%4!=0);
	
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(i<(n/2))
		{
			for(j=0;j<n;j++)
			{
				if(j<(n/2)) 
				{
					if(i==j) printf("\\");
					else if((n/2-j-1)==i) printf("/");
					else printf(" ");
				}
				else 
				{
					if(i==0 || i==(n/2-1)) 
					{
						if(j==n/2 || j==n-1) printf("+");
						else printf("-");
					}
					else
				    {
				    	if(j==n/2 || j==n-1) printf("|");
						else printf(" ");
				    }
				}
			}
		}
		else
		{
			for(j=0;j<n;j++)
			{
				if(j<(n/2))
				{
					if(i==n/2 || i==n-1) 
					{
						if(j==0 || j==n/2-1) printf("+");
						else printf("-");
					}
					else 
					{
						if(j==0 || j==n/2-1) printf("|");
						else printf(" ");
					}
				}
				else 
				{
					if((j==n/2+n/4 || j==n/2+n/4-1) && (i==n/2+n/4 || i==n/2+n/4-1)) printf("+");
					else if(j==n/2+n/4 || j==n/2+n/4-1) printf("|");
					else if(i==n/2+n/4 || i==n/2+n/4-1) printf("-");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
