#include <stdio.h>

int main() {
	int n,i,j;
 
	printf("Unesite broj n: ");   
	scanf("%d", &n);
	while(n<=0 || n>50 )
	{
		printf("Pogresan unos\n");
	    printf("Unesite broj n: ");
	    scanf("%d", &n);
		
	}
	if(n==1) 
	{
		for(i=0;i<3;i++)
		{
			printf("*");
		}
	}
	else {
	for(i=0;i<(n*4)-3;i++)
	{
		if(i==0 || i==((n*4)-3)/2 || i==(4*n)-4)
		{
			printf("*");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<(n*4)-3;j++)
		{
			if(i==j-1 || i+j==(((n*4)-3)/2)-1 || i+j==(n*4)-5 || i==(j-((n*2)-1)))
			{
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	}
	
	
	

	return 0;
}
