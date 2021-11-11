#include <stdio.h>

int main() {
	int i,n, j;
	printf("Unesite broj n: ");
	scanf("%d", &n);
    for (i=0;i<1;)
    {
		if((n<=0)||(n>50))
		{
			printf("Pogresan unos\n");
			printf("Unesite broj n: ");
	        scanf("%d", &n);
		}
		else i++;
    }
		if(n==1)
		{
			printf("***");
		}
		else {
		
    for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
		{
			
			     
			if(i==j)
			printf("*");
			else 
			printf(" ");
			if(j==(n-1))
			{
				
				for(j=1;j<n;j++)
				{
					if((i+j)==(n-1))
					printf ("*");
					else 
					printf(" ");
					
					if(j==(n-1))
			{
				for(j=1;j<n;j++)
				{
					
					if(i==j)
					printf ("*");
					else 
					printf(" ");
					if(j==(n-1))
			{
				for(j=1;j<n;j++)
				{
					if((i+j)==(n-1))
					printf ("*");
					else 
					printf(" ");
				}
			}
				}
			}
				}
			}
			
				
			
		}
				printf("\n");
	}
		}

	
	return 0;
}
