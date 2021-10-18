#include <stdio.h>

int main()
	{
		int i, j, n;
		LOOP:
		printf("Unesite broj n: ");
		scanf("%d",&n);
		
	    while(n<=0 || n>50)
	    {
	       printf("Pogresan unos\n");
           goto LOOP;
	    }
	    
	    if(n==1)
	    {
	    	printf("***");
	    }
	    else {
	    
	    for(i=1; i<=n; i++)
	    {
	    	for(j=1; j<=n*4-3; j++)
	         {
	         	if(j==i || j==n*2-i || j==n*2+i-2 || j==n*4-i-2)
	         	{
	         		{
	         			printf("*");
	         		}
	         	}
	         	else
	         	{
	         		printf(" ");
	         	}
	         }
	    	
	    	printf("\n");
	    	}
	    }
	    return 0;
}

