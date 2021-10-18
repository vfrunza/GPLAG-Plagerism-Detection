#include <stdio.h>

int main() {
	int M, N, mat[200][200] = {0}, i, j, k, num = 0, x, y, z;
	
	/*Unos i provjera dimenzija*/
	
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
		if (M <= 0 || N <= 0 || M > 200 || N > 200) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	}
	while (M < 0 || N < 0 || M > 200 || N > 200);
	
	printf ("Unesite elemente matrice: ");
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			scanf ("%d", &mat[i][j]);
		}
	}
	
	/*Provjera clanova redova i kolona i izbacivanje ako se u dva reda ili dvije kolone svi clanovi ponavljaju sa klasicnom petljom za izbacivanje clanova*/
	
    for (i = 0; i < M; i++){
        x = i + 1;
        
        while (x < M){
            num = 0;
            
            for (j = 0; j < N; j++){
                if(i != M - 1){
                    if (mat[i][j] == mat[x][j]){
                        num++;
                        
                        if (num == N){
                            for (k = x; k < M; k++){
                                for (z = 0; z < N; z++){
                                    mat[k][z] = mat[k + 1][z];
                                }
                            }
                        x = i;
                        M--;
                        }
                    }
                }
            }
        x++;
        }
    }
   
	
	
	for (j = 0; j < N; j++){
        if (j != N - 1){
            x = j + 1;
            
            while (x < N){
                if (mat[0][j] == mat[0][x]){
                    num = 0;
                    
                    for (k = 0; k < M; k++){
                        if (mat[k][j] == mat[k][x]){
                            num++;
                            
                            if (num == M){
                                for (y = 0; y < M; y++){
                                    for (z = x; z < N; z++){
                                        mat[y][z] = mat[y][z + 1];
                                        if (M == 1) {
                                            x = j;
                                        }
                                    }
                                }
                            N--;
                            }
                        }  
                    }
                }
                x++;
            }
        }
    }
    
    /*Ispis*/
    
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			printf ("%5d", mat[i][j]);
		}
		printf ("\n");
	}
	
	return 0;
}
