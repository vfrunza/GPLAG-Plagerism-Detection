#include <stdio.h>

int main() {
	int n,i,j;
	do
	{
	printf("\nUnesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50)
	printf("Pogresan unos");
	}
	while(n<=0 || n>50);
	for(i=0;i<n;i++)
		{
		
				for(j=0;j<i;j++)
				printf(" ");
			printf("*");
				for(j=1;j<2*(n-i-1);j++)
				{
				printf(" ");
				}
			if(n==1)
			printf("*");
			if(i!=n-1)
			printf("*");
			
				for(j=0;j<2*i-1;j++)
				printf(" ");
			if(n==1)
			printf("*");
			if(i!=0)
			printf("*");
		
			for(j=1;j<2*(n-i-1);j++)
				{
				printf(" ");
				}
			
			if(i!=n-1)
			printf("*");
			
			printf("\n");
			
		}
		
	return 0;
}
