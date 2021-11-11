#include <stdio.h>
#define BROJ_EL 200
int main() {
    int matrica[BROJ_EL][BROJ_EL];
    int M,N,i,j,k,r,l,flag;
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&M,&N);
        if(M < 1 || M > 200 || N < 1 || N > 200)
            printf("Brojevi nisu u trazenom opsegu.\n");
    }while(M < 1 || M > 200 || N < 1 || N > 200);
    printf("Unesite elemente matrice: ");
	for(i = 0;i < M;i++){
	    for(j = 0;j < N;j++)
	        scanf("%d",&matrica[i][j]);
	}
for(i = 0;i < M-1;i++){
    for(j = i+1;j < M;j++){
        flag = 1;
        for(k = 0;k < N;k++){
            if(matrica[i][k] != matrica[j][k]){
                flag = 0;
                break;
            }
        }
        if(flag){
           for(r = j;r < M;r++){
               for(l = 0;l < N;l++)
                    matrica[r][l]=matrica[r+1][l];
           }
          M--;
          j--;
        }
        
    }
}
for(i = 0;i < N-1;i++){
    for(j = i+1;j < N;j++){
        flag = 1;
        for(k = 0;k < M;k++){
            if(matrica[k][i] != matrica[k][j]){
                flag = 0;
                break;
            }
        }
        if(flag){
           for(r = j;r < N;r++){
               for(l = 0;l < M;l++)
                    matrica[l][r]=matrica[l][r+1];
           }
          N--;
          j--;
        }
        
    }
}
printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i = 0;i < M;i++){
		for(j = 0;j < N;j++)
			printf("%5d", matrica[i][j]);
		printf("\n");
	}
	
	return 0;
}
