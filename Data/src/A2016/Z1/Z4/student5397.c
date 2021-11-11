#include <stdio.h>
#include <math.h>

int main() 
{
	int n, m, i, j, k, h, f, g;
	double d;
    m=0;
    while (m==0)
    {
     printf ("Unesite broj n: ");
     scanf ("%lf", &d);
     n= (int) d;
	 if (n!=d)
	 {
	 	printf ("Pogresan unos\n");
	 }
	 else if (n>50)
	 {
	 	printf ("Pogresan unos\n");
	 }
	 else if (n<=0)
	 {
	 	printf ("Pogresan unos\n");
	 }
	 else 
	 {
	 	m=1;
	 }
    }
	
	for (i=0; i<n; i++)
	{
	  if (i==0)
	  {
		for (j=0; j<3; j++)
		{
			printf ("*");
			h=2*n-3;
			if (h<0)
			{
				h=0;
			}
			for (k=0; k<(2*n-3); k++)
			{
			  printf (" ");
			}
		}
	  }
	  
	  else if (i>0 && i<(n-1))
	  
	  {
	  	for (j=0; j<4; j++)
		{
		  if (j==0)
		  {
			for (f=0; f<i; f++)
			{
			  printf (" ");
			}
		  }
		  
		  if (j==1)
		  {
		  	printf ("*");
		  	
		  	g=2*i-1;
			if (g<0)
			{
				g=0;
			}
			for (k=0; k<g; k++)
			{
			  printf (" ");
			}
		  	
		  }
		  
		  if (j==0 || j==1)
		  {
		    printf ("*");
			
			for (k=0; k<(2*n-3-2*i); k++)
			{
			  printf (" ");
			}
		  }
		  if (j==3)
		  {
		  	printf ("*");
		  }
		}
	  }
	  
	  else if (i==(n-1))
	  {
	  	for (j=0; j<2; j++)
	  	{
	  	  if (j==0)
	  	  {
	  		for (f=0; f<i; f++)
			{
			  printf (" ");
			}
	  	  }
			
	  		printf ("*");
	  		
			for (k=0; k<(2*n-3); k++)
			{
			  printf (" ");
			}
	  	}
	  }
	  
		printf ("\n");
	}

	return 0;
}
