#include <stdio.h>
#define A 101
int main() 
{
	int nista=0,t=0,c=0,i,j,m,n;
	double matrix[A][A];
	
	do
	{
	    printf ("Unesite M i N: ");
    	scanf ("%i %i",&m,&n);
    	if (m>100 || n>100 || m<1 || n<1)
    	{
    	    printf ("Pogresan unos!\n");
    	}
    	else 
    	break;
	}while (m>=100 || n>=100 || m<1 || n<1);
	
	/************unos******************/
	printf ("Unesite elemente matrice: ");
	
	for (i=0;i<m;i++)
	{
	    for (j=0;j<n;j++)
	    {
	        scanf ("%lf",&matrix[i][j]);
	    }
	}
	/*****************************************/
	if ( n==1 && m!=1 )
	{
		printf ("Matrica je Teplicova");
		return 0;
	}
	/************//////////////**************/
	
	t=1;
	for (i=0;i<m-1;i++)
	{
		for (j=0;j<n-1;j++)
		{
			if (matrix[i][j]!=matrix[i+1][j+1])
			{
				t=0;
				break;
			}
		}
	}
	c=1;
	for (i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if (matrix[i][n-1]!=matrix[i+1][0])
			{
				c=0;
				break;
			}
		}
	}
	if (c==0 && t==1)
	printf ("Matrica je Teplicova");
	else if (t==1&&c==1)
	printf ("Matrica je cirkularna");
	else
	printf ("Matrica nije ni cirkularna ni Teplicova");
	
	
	
	return 0;
}
