#include <stdio.h>

int main() {
	int i,j,n,m;
	do
	{ 
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0 || n<8) printf("Neispravno N!\n");
	} while(n%4!=0 || n<8);
	m=n/2;
	printf("\n");
	for(i=0;i<n;i++)
	{
			if(i<m)
			{
		for (j=0;j<m;j++)
		{
			if(i==j) printf("\\");
			else if(i==m-1-j || j==m-1-i) printf("/");
			else  printf(" ");
		}
		for(j=0;j<m;j++)
		{
			if(i==0 || i==m-1)
			{
				if(i==j || i==m-1-j || j==m-1-i) printf("+");
				else printf("-");
			}
			else
			{
				if(j==0 || j==m-1) printf("|");
				else printf(" ");
			}
		}
		printf("\n");
			}
			else if(i>=m)
			{
				for(j=m;j<n;j++)
				{
					if(i==m|| i==n-1)	
						{
						if(i==j ||(j==m && i==n-1) || (j==n-1 && i==m)) printf("+");
						else printf("-");
						}
						else
						{
						if(j==m || j==n-1) printf("|");
						else printf(" ");
						}
				}
				for(j=m;j<n;j++)
				{
					if(i==n-(m/2) || i==n-1-(m/2))
					{
					if(j==n-(m/2) || j==n-1-(m/2)) printf("+");
					else printf("-");
					}
					else
					{
							if(j==n-(m/2) || j==n-1-(m/2)) printf("|");
							else printf(" ");
					}
				}
				printf("\n");
				
		
			}
		
	}
	return 0;
}
