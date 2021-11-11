#include <stdio.h>

int main() {
	int N,i,j;
    do
    {
    	printf ("Unesite broj N: ");
    	scanf ("%d",&N);
        if (N<8 || N%4!=0)
    	printf ("Neispravno N!\n");
    	else
    	printf ("\n");
    }
    while (N<8 || N%4!=0);
    for (i=0;i<N;i++)
    {
    	for (j=0;j<N;j++)
    	{
    		if (j<N/2)
    		{
    			if (i<N/2)
    			{
    				if (i==j)
    				printf ("\\");
    				else if (i==N/2-j-1)
    				printf ("/");
    				else
    				printf (" ");
    				
    			}
    			else if (i>=N/2)
    			{
    				if (i==N/2 || i==N-1)
    				{
    					if (j==0 || j==N/2-1)
    					printf ("+");
    					else
    					printf ("-");
    				}
    				else
    				{
    					if (j==0 || j==N/2-1)
    					printf ("|");
    					else
    					printf (" ");
    				}
    			}
    		}
    		else if (j>=N/2)
    		{
    			if (i<N/2)
    			{
    				if (i==0 || i==N/2-1)
    				{
    					if (j==N/2 || j==N-1)
    					printf ("+");
    					else
    					printf ("-");
    				}
    				else
    				{
    					if (j==N/2 || j==N-1)
    					printf ("|");
    					else
    					printf (" ");
    				}
    			}
    			else if (i>=N/2)
    			{
    				if (j==N-N/4 || j==N-N/4-1)
    				{
    				    if (i==N-N/4 || i==N-N/4-1)
    				    printf ("+");
    				    else
    				    printf ("|");
    				}
    				else
    				{
    				    if (i==N-N/4 || i==N-N/4-1)
    				    printf ("-");
    				    else 
    				    printf (" ");
    				}
    			}
    		}
          
    	}
    	printf ("\n");
    }
	return 0;
}
