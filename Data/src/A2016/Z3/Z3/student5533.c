#include <stdio.h>
void izbaci_redove (int mat[200][200], int*p, int n)
{
	int i=0, j=0,l=0,k=0,svi=0,f=0,m=*p;
	for (i=0; i<m-1;i++)
	     for (k=i+1; k<m; k++)
	     {
	     	svi=1;
	     	for (j=0;j<n;j++)
	     	    if (mat[k][j]!=mat[i][j])
	     	        svi=0;
	     	if (svi)
	     	{
	     		for (l=k; l<m-1; l++)
	     		    for (f=0;f<n;f++)
	     		        mat[l][f]=mat[l+1][f];
	     		m--; k--;
	     	}
	     }
	     *p=m;
}
void izbaci_kolone (int mat[200][200], int m, int*p)
{
	int i=0,j=0,l=0,k=0,svi=0,f=0,n=*p;
	for (j=0; j<n-1;j++)
	    for (k=j+1; k<n; k++)
	    {
	    	svi=1;
	    	for (i=0;i<m;i++)
	    	    if (mat[i][j]!=mat[i][k])
	    	       svi=0;
	    	if (svi)
	    	{
	    		for (l=k; l<n-1; l++)
	    		    for (f=0; f<m;f++)
	    		         mat[f][l]=mat[f][l+1];
	    		n--; k--;
	    	}
	    }
	    *p=n;
}
int main() {
	int mat[200][200], i,j,m,n;
	do
	{
       printf ("Unesite brojeve M i N: ");
       scanf ("%d %d", &m, &n );
       if (m<=0 || n<=0 || m>200 || n>200)
       printf ("Brojevi nisu u trazenom opsegu.\n");
	} while (m<=0 || m>200 || n<=0 || n>200);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	
		for (j=0; j<n; j++)
		
	
			scanf ("%d", &mat[i][j]);
    izbaci_redove(mat,&m,n);
    izbaci_kolone(mat,m,&n);
    printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for (i=0; i<m; i++)
    {
    	for (j=0; j<n; j++)
    	    printf ("%5d", mat[i][j]);
    	    printf ("\n");
    }
    return 0;
}
		

	