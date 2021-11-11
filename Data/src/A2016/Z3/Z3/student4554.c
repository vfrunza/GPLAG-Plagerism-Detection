#include <stdio.h>
int main() 
{
	int N, M;
	int m[100][100];
	int l, j, i, f, r, kol;
	int ind1=0, ind2=0;
	
	do 
	{
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
		if ( M < 1 || N < 1 || M > 200 || N > 200 ) 
		{
		   printf("Brojevi nisu u trazenom opsegu.\n");
		}
		
	} while ( M < 1 || N < 1 || M > 200 || N >200 );
	      printf("Unesite elemente matrice: ");
	for ( i=0; i<M; i++ ) {
		for ( j=0; j<N; j++ ) {
			scanf ("%d", &m[i][j]);
		}
	}
	for ( i=0; i<M-1; i++ ) {
		if (ind1 == 1)
		   i--;
		for ( f=i+1; f<M; f++ ) {
			kol = 0;
			while (kol < N) 
			{
				if (m[i][kol]==m[f][kol])
				{
				   ind1 = 1;
				}
				else {
					ind1 = 0;
					break;
				}
			    kol++;
		    }
	    if (ind1 == 1) {
		    for ( j=f; j<M-1; j++ ) {
			    for ( l=0; l<N; l++ ) {
				    m[j][l]=m[j+1][l];
			    }
		    }
		    M--;
		    f--;
	    }
	    }
	 }
     for ( i=0; i<N-1; i++ ) {
    	if (ind2 == 1)
    	{
    	   i--;
    	}
    	for ( f=i+1; f<N; f++ ) {
    		r = 0;
    		while (r < M) {
    			if (m[r][i]==m[r][f])
    			{
    			   ind2 = 1;
    			}
    			else {
    				ind2 = 0;
    				break;
    			}
    			r++;
    		}
    	if(ind2 == 1) {
    		for ( j=f; j<N; j++ ) {
    			for (l=0; l<M; l++) {
    			m[l][j]=m[l][j+1];
    		}
    	}
    	N--;
    	f--;
    	}
    	}
    }
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for ( i=0; i<M; i++ ) {
		for ( j=0; j<N; j++ )
		    printf("%5d", m[i][j]);
		printf("\n");
	}
	return 0;
}
