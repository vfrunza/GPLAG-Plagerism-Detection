#include <stdio.h>

int main() {
	int i, j, k, n;
	int a[20], b[20];
	int c[20][20];
	for(i=0;i<20;i++)
	{
		for(j=0; j<20;j++)
		c[i][j]=0;
	}
	do
	{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if((n<1)||(n>10))
	{
		printf("Pogresan unos\n");
	}
	}
	while((n<1)||(n>10));
	
		
	for (i=0; i<n; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &a[i], &b[i]);
		if((a[i]<0)||(a[i]>19)||(b[i]<0)||(b[i]>19))
		{
			printf("Pogresan unos\n");
			i--;
		}
	}
	for (i=0; i<n; i++)
		{
	    	for(j=0; j<20; j++)
			{
				for(k=0; k<20; k++)
				{
					
					if((j==b[i]) &&(k==a[i]))
					{
						c[j][k]=1;
					 
					}
					
					
				
				}
			}
		
		}
    	for(j=0; j<20; j++)
		{
			for(k=0; k<20; k++)
			{
			if(c[j][k]==1)
			printf("*");
			else 
			printf(" ");
			}
			printf("\n");
		}
		
    
	return 0;
}
