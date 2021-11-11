#include <stdio.h>
int main()
{
	int mat[200][200], M,N,i,j,k;
	do
	{
	    printf( "Unesite brojeve M i N: " );
	    scanf( "%d %d", &M,&N );
	    if( M <= 0 || M > 200 || N <= 0 || N > 200 )
	    {
	    	printf( "Brojevi nisu u trazenom opsegu.\n" );
	    }
	    
	}
	while( M <= 0 || M > 200 || N <= 0 || N > 200 );
	
	//Unos elemenata matrice
	printf("Unesite elemente matrice: ");
	for(i=0; i < M; i++)
	{
		for(j=0; j < N; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	//Ispitivanje redova
	int pom=M-1, uslov, r,s;
	for(i=0; i < M ; i++)
	{
		for(k=pom; k > i; k--)
		{
			uslov=1;
			for(j=0; j < N; j++)
			{
				if( mat[i][j] != mat[k][j] ) uslov=0;
			}
			if(uslov == 1)
			{
				for(r=k; r < M-1; r++)
				{
					for(s=0; s < N; s++)
					mat[r][s] = mat[r+1][s];
				}
				M--;
				k--;
			}
		}
		pom=M-1;
	}
		
	//Ispitivanje kolone//
	int pom1=N-1;
	for(i=0; i < N; i++)
	{
		for(k=pom1; k > i; k--)
		{
			uslov=1;
			for(j=0; j < M; j++)
			{
				if( mat[j][i] != mat[j][k]) uslov=0;
			}
			if(uslov == 1)
			{
				for(r=0; r < M; r++)
				{
					for(s=k; s < N-1; s++)
					mat[s][r] = mat[s][r+1];
				}
				N--;
				k--;
			}
		}
	}
	
	//Ispis matrice//
	printf( "Nakon izbacivanja redova/kolona matrica glasi: \n" );
	for(i=0; i < M; i++)
	{
		for(j=0; j < N; j++)
			printf("%5d", mat[i][j]);
			printf("\n");
	}
	
	return 0;
}