#include <stdio.h>

int main() {
	int mat [235][235];
	int i, j, k, p, r, M, N, pret=1, h=0, s=0;
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d",&M, &N);
		if(M > 200 || M <= 0) printf ("Brojevi nisu u trazenom opsegu. \n");
		else if(N > 200 || N <= 0) printf ("Brojevi nisu u trazenom opsegu. \n");
	} while ((M > 200 || M <= 0) || (N > 200 || N <= 0) );
	h=M; 
	s=N;
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d",&mat[i][j]);
		}
	}
	
	
	
	for (i=0; i<M; i++)
	{ 
		
		for (k=i+1; k<M; k++)
		{
			pret=1;
			for(j=0; j<N; j++)
				if(mat[i][j]!=mat[k][j]) pret=0;
			if (pret==1) 
			{
				for (p=k; p<M-1; p++) 
					for (r=0; r<N; r++)
						mat[p][r]=mat[p+1][r];
				p--;
				M--;
				k--;
			} 
		}
	}
	for (j=0; j<N; j++)
	{ 
		
		for (k=j+1; k<N; k++)
		{
			pret=1;
			for(i=0; i<M; i++)
				if(mat[i][j]!=mat[i][k]) pret=0;
			if (pret==1) 
			{
				for (p=k; p<N-1; p++) 
					for (r=0; r<M; r++)
						mat[r][p]=mat[r][p+1];
				p--;
				N--;
				k--;
			} 
		}
	}

	
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			 if (mat[i][j]>9 || mat[i][j]<0) printf ("   ");
			 else printf ("    ");
			 printf ("%d",mat[i][j]);
		}
		printf ("\n");
	}	
		
		
		
		
		
		
		
	return 0;
}
