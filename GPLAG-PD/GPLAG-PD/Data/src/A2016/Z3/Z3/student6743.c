#include <stdio.h>
#define vel 200
int main() {
	int mat[vel][vel], M, N, i, j, k, l, n, x=0, y=0, brojac=0, brojac1=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M>200 || N>200 || M<1 || N<1) printf("Brojevi nisu u trazenom opsegu.\n");
		
	}while(M>200 || N>200 || M<1 || N<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &mat[i][j]);
		}
	}
//int M=4, N=4, i, j, k, l, n, y=0,brojac=0, brojac1=0;
//int mat[4][4]={{1,2,3,2},{4,5,6,5},{1,2,3,2},{7,8,9,8}};
for(i=0; i<M; i++){
    for(k=i+1; k<M; k++){
        x=0;
        if(mat[i][0]==mat[k][0]){
            for(j=1; j<N; j++){
                if(mat[i][j]==mat[k][j]) brojac++;
            }
            x=1;
            break;
        }
    }
    if(brojac==N-1 && x==1){
        for(l=k; l<M-1; l++){
            for(n=0; n<N; n++){
                mat[l][n]=mat[l+1][n];
            }
        }
        M--;
        i--;
    }
}
for(i=0; i<N; i++){
    for(k=i+1; k<N; k++){
        y=0;
        if(mat[0][i]==mat[0][k]){
        for(j=1; j<M; j++){
            if(mat[j][i]==mat[j][k]) brojac1++;
        }
        y=1;
        break;
    }
    }
    if(y==1 && brojac1==M-1){
        for(l=k; l<N-1; l++){
            for(n=0; n<M; n++){
                mat[n][l]=mat[n][l+1];
    }
}
N--;
i--;
}
}
//printf("%d", brojac);



    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0; i<M; i++){
    	for(j=0; j<N; j++){
    		printf("%5.d", mat[i][j]);
    	}
    	printf("\n");
    }
    
	return 0;
}