#include <stdio.h>
#include <math.h>

int main() {
	
	int m, n, i, j, teplicova_matrica=0, cirkularna_matrica=0;
	float e=0.0000001;
	double mat[100][100];
	for (i=0; i<100; i++)
	{
		for (j=0; j<100; j++)
		mat[i][j]=0;
	}
	
	do {
		printf ("Unesite M i N: ");
		scanf ("%d %d", &m,&n);
		if (m<1 || m>100 || n<1 || n>100)
		printf ("Pogresan unos!\n");
	}
	while (m<1 || m>100 || n<1 || n>100);
	
	printf("Unesite elemente matrice: ");
	
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		scanf ("%lf", &mat[i][j]);
	}
	
		if (m==1)
	{
		printf ("Matrica je cirkularna");
		return 0;
		
	}
	if (n==1)
	{
		printf ("Matrica je Teplicova");
		return 0;
	}
	
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			if (fabs (mat[i][j]-mat[i+1][j+1])<e && fabs (mat[m-1][n-1]-mat[m-2][n-2])<e)
			teplicova_matrica=1;
			/*Provjera za zadnji red jer nije obuhvacen prethodnim uslovom*/
			if (i==m-1 && j>0 && fabs(mat[i][j]-mat[i-1][j-1])>e)
			teplicova_matrica=0; 
			
		}
	}
	
	if (teplicova_matrica)
	{
		/*Ispitivanje da li je matrica cirkularna*/
		for (i=0; i<m-1; i++)
		{
			if (fabs (mat[i][n-1]-mat[i+1][0])<e)
		    cirkularna_matrica=1;
		    else
		    {
		    	cirkularna_matrica=0;
		    	break;
		    }
		}
		if (cirkularna_matrica)
		printf ("Matrica je cirkularna");
		else
		printf ("Matrica je Teplicova");
		
	}
	
	else printf ("Matrica nije ni cirkularna ni Teplicova");
	

	
	return 0;
}