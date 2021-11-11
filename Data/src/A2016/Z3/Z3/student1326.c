#include <stdio.h>

int main() {
	int m, n;
	do 
	{
		printf("\nUnesite brojeve M i N: ");
		scanf ("%d", &m);
		scanf ("%d", &n);
		
		if (m>=200 || n>=200 || m<=0 || n<=0)
		{
			printf ("Brojevi nisu u trazenom opsegu. ");
		}
	}
	while (m>=200 || n>=200 || m<=0 || n<=0);
	int mat [200][200];
	int i, j;
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
{
    for (j=0; j<n; j++)
	{
		scanf ("%d", &mat[i][j]);
	}
}
    
    for (i=0; i<m; i++)
{
	for (j=i+1; j<m; j++)
	{
		int isti=1;
		int k;
		for (k=0; k<n; k++)
		if (mat[i][k]!=mat[j][k])
		{
			isti=0;
			break;
	}
	

    if (isti==1)
    { 
    	m--;
    	

    	int p; 
    	int q;
    	for (p=j; p<m; p++)
    {
    	for (q=0; q<n; q++)
    	{
    		mat[p][q]= mat[p+1][q];
    	}
    }
    if (i>0) i--;
    if (j>0) j--;
}
}
}

 for (i=0; i<n; i++)
{
	for (j=i+1; j<n; j++)
	{
		int isti=1;
		int k;
		for (k=0; k<m; k++)
		if (mat[k][i]!=mat[k][j])
		{
			isti=0;
			break;
	}
	

    if (isti==1)
    { 
    	n--;
    
  
    	int p; 
    	int q;
    	for (p=j; p<n; p++)
    {
    	for (q=0; q<m; q++)
    	{
    		 mat[q][p]= mat[q][p+1];
    		
    	
    	}
    	
    }
     if (i>0) i--;
    if (j>0) j--;
}
}
}

	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
     for (i=0; i<m; i++)
{
    for (j=0; j<n; j++)
    	printf("%5d",mat[i][j]);
	printf("\n");
}	

	
	return 0;
}
