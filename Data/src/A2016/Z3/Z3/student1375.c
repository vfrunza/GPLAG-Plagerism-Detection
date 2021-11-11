#include <stdio.h>

int main() {
	 int M, N, mat[200][200], i, j, k, e, f, jeste, m, n;

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>200 || N<=0 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<=0 || M>200 || N<=0 || N>200);
	printf("Unesite elemente matrice: ");

	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
		scanf("%d", &mat[i][j]);	
		}

	}
	 m = M;
    for (i = 0; i < m; i++){
        for (j = i + 1; j < m; j++){
            jeste = 1;
            for (k = 0; k < N; k++){
                if (mat[i][k] != mat[j][k]){
                    jeste = 0;
                    break;
                }
            }
            if (jeste){
                for (e = j; e < m - 1; e++){
                    for (f = 0; f < N; f++){
                        mat[e][f] = mat[e+1][f];
                    }
                }
                j--;
                m--;
            }
        }
    }
    n = N;
 
    for (j = 0; j < n; j++){
        for (i = j + 1; i < n; i++){
            jeste = 1;
            for (k = 0; k < m; k++){

                if (mat[k][j] != mat[k][i]){
                    jeste = 0;
                    break;
                }
            }
            if (jeste){
                for (e = i; e < n - 1; e++){
                    for (f = 0; f < m; f++){
                        mat[f][e] = mat[f][e+1];
                         }
                }
                i--;
                n--;
            }
        }
    }
 

	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		printf("%5d", mat[i][j]);	
		}
		printf("\n");
	}

	
	return 0;
}
