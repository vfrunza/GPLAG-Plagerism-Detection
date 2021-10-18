#include <stdio.h>

int main() {
	int n,i,j;
	
	ponavljanje:
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if (n<=0 || n>50)
	{
		printf ("Pogresan unos\n");
		goto ponavljanje;
	}
	
	if (n==1)
    {   
    	printf("***");
        return 0;
    }
  
    else
	for (i=0;i<n;i++)
	{
		for (j=0;j<(4*n-3);j++)
		{
			if (i==j)
		    printf("*");
		    else if (j-i-(4*n-3)/2==0)
	     	printf("*");
		    else if (i+j-(4*n-3)/2==0)
	     	printf ("*");
	    	else if (i+j-(4*n-4)==0)
	      	printf ("*");
		    else
            printf (" ");
			
		}
		
		printf("\n");
		
	}
	
	
	
	return 0;
}
