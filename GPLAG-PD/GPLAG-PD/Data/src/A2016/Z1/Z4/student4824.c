#include <stdio.h>

int main() {
	int n;
	unos:
	printf("\nUnesite broj n: ");
	scanf("%d",&n);
	if((n<1)||(n>50))
	{ 
		printf("Pogresan unos");
		goto unos;
	}
	int i,j,k,z,q;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(n==1)
			printf("**");
			if(i==j)
			printf("*");
			else 
			printf(" ");
			
		}
		for(k=0;k<n-1;k++)
		{
			if(i+k==n-2)
			printf("*");
			else
			printf(" ");
			
		}
		for(z=0;z<n-1;z++)
		{
			if(i==z+1)
			printf("*");
			else printf(" ");
			
		}
		for(q=0;q<=n;q++)
		{
			if(i+q==n-2)
			printf("*");
			else printf(" ");
			
		}
		printf("\n");
		
    }
	return 0;
}
