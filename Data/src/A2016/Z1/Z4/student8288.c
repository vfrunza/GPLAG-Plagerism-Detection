#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int i,j,n;

	
	while(1)	
	{
		printf("Unesite broj n: ");
		scanf("%d",&n);
		
		if(n<=0 || n>50)
		{
			printf("Pogresan unos\n");
			continue;
		}
		
		break;
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n*4-3;j++)
		{
		
			if(i==j)printf("*");
			else if(j==i+((4*n-3)/2))printf("*");
			else if(((4*n-3)/2)-i==j)printf("*");
			else if(j==(4*n-3)-i-1)printf("*");
			else printf(" ");
		}
		
		printf("\n");
	}
		
	
	

	

	return 0;
}
