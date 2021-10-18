#include <stdio.h>

int main() 
{
	int n,i,j;
	
	printf("Unesite broj n: ");
	scanf("%d",&n);
	
	while(n<=0 || n>50)
	{
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d",&n);
	}
	if(n==1)
		printf("***");
	else
	{
	for(i=0;i<n;i++)
	{		
		for(j=0;j<n*4-1;j++)
		{
			if(i==j || i==n*2-j-2 || i==j-(((n*4)/2)-2) || i==n*4-j-4 )
				printf("*");
			else
				printf(" ");
		}	
		printf("\n");
	}
	}
	
	return 0;
}
