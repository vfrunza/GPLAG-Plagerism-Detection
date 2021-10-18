#include <stdio.h>

int main() {
	int n,i,j;
   
     printf("Unesite broj n: ");
     scanf("%d",&n);
     
     	while(n<=0 || n>50)
     	{
     		printf("Pogresan unos\nUnesite broj n: ");
     		scanf("%d",&n);
     	}
     
	 if(n==1)
	{
		for(i=0;i<3*n;i++)
		printf("*");
		
	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<4*n;j++)
			{
				if(j<n && i==j) printf("*");
				else if(j>=n && j<2*n-1 && i+j==2*(n-1)) printf("*");
				else if(j>=2*n-1 && j<3*n-2 && j-i==2*(n-1)) printf("*");
				else if(j>=3*n-2 && j<4*n-3 && i+j==4*n-4) printf("*");
				else printf(" ");
			}
		
			printf("\n");
		}
	}
	
	return 0;
}
