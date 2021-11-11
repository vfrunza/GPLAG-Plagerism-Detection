#include <stdio.h>

int main() {
	int n, i, j;
	do
	{
		printf("Unesite broj n: ");
	    scanf("%d", &n);	
	    if(n<=0 || n>50)
	    {
	    	printf("Pogresan unos\n");
	    	continue;
	    }
	    break;
	}while(1==1);
	if(n==1)
	{
		for(i=0;i<2;i++)
		{
			printf("*");
		}
	}
	i=0;
	while(i<n)
	{
		for(j=0;j<4*n-1;j++)
		{
			if(i==j || i+j==2*n-2 || 2*n-2+i==j || i+j==4*n-4 ) printf("*");
			else printf(" ");
		}
		printf("\n");
		i++;
	}
	return 0;
}
