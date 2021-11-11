#include <stdio.h>


int main() {
	
	int M, N, i, j, k, l, control;
	double mat[200][200];
	
	do
	{
		printf ( "Unesite brojeve M i N: " );
		scanf ("%i %i", &M, &N );
		
		if ( ( M < 1 || N < 1 ) || ( M > 200 || N > 200 ) )
		printf ( "Brojevi nisu u trazenom opsegu.\n" );
	}
	while ( ( ( M < 1 || N < 1 ) || ( M > 200 || N > 200 ) ) );
	
	printf ( "Unesite elemente matrice: " );
	
	for ( i = 0; i < M; i++ )
	{
		for( j = 0; j < N; j++ )
		{
			scanf ( "%lf", &mat[i][j] );
		}
	}
	
/* Ispod je algoritam za izbacivanje redova */
for ( i = 0; i < M-1; i++ )
{
	for ( j = i + 1; j < M; j++ ) {
		
		control = 1;
		
		for ( k = 0; k < N; k++) {
			if ( mat[i][k] != mat[j][k] )
			{	control = 0;
				break;
		
				
			}
		}
		
	}
		
		if ( control == 1 ){
		
		
	
			for ( k = j; k < M-1; k++ )
			
				for ( l = 0; l < N; i++ )
				mat[k][l] = mat[k+1][l];
			
			M--;
			j--;
		}
		/* Dio iznad(for petlja sa if(control==1) kopiran jer je bio na krivom mjestu u kodu */
	
}



	printf ( "Nakon izbacivanja redova/kolona matrica glasi: \n" );
	
	for ( i = 0; i < M; i++ )
	{
		for ( j = 0; j < N; j++ )
		{
			printf ("%5g", mat[i][j] );
		}
		
		printf ( "\n" );
	}
	
	return 0;
}
