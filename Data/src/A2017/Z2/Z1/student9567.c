#include <stdio.h>

int main() {
	int i,j,n=1,npolovina;

do {
	
printf ("\nUnesite broj N: ");	
scanf ("%d", &n);
if (n<0 || n%4!=0 || n<8 || n==4)
{printf ("Neispravno N!");
}

} while (n%4!=0   ||  n<8);
printf ("\n");
 npolovina= n/2;
for (i=0 ; i<n ; i++)
{
	for (j=0; j<n ; j++)
	
	{
		if (i<npolovina && j<npolovina)
		{
			if (i==j)
			printf ("\\"); 
		
			else if (i==(n/2)-j-1)
			printf ("/"); 
			
			else 
			printf (" "); 
		
		}
		else if (i<npolovina && j>=npolovina)
		{
			if (i==0 || i==(n/2)-1)
			{
				if (j==(n/2) || j==n-1)
				printf ("+");
				else 
				printf ("-");
			}
			else if ((j==n/2 || j==n-1) && i!=0 && i!=(n/2)-1)
			{
			printf ("|");
			}
			else 
			printf (" ");
		}
		else if (i>=npolovina && j<npolovina)
		{
			if (i==n/2 || i==n-1)
			{
				if (j==0 || j== (n/2)-1)
				printf ("+");
				else 
				printf ("-");
			}
			else if ((j==0 || j==((n/2)-1)) && i!=n/2 && i!=n-1 )
			printf ("|");
			else 
			printf (" ");
		}
		
		else
		{
			if ((i== npolovina+npolovina/2 || i==npolovina+npolovina/2 -1 ) && j!=npolovina+npolovina/2 && j!=npolovina+npolovina/2-1)
	printf ("-");
	else if ((j== npolovina+npolovina/2 || j==npolovina+npolovina/2 -1 ) && i!=npolovina+npolovina/2 && i!=npolovina+npolovina/2-1)
	printf ("|");
	else if ((i== npolovina+npolovina/2 || i==npolovina+npolovina/2 -1 ) && (j!=npolovina+npolovina/2 || j!=npolovina+npolovina/2-1))
	printf ("+");
	else
	printf (" ");
		}
		
		
		
		
		
		
		
		
		
	
	}
		printf ("\n");
}


return 0;
	
}


