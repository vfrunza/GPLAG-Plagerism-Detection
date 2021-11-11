#include <stdio.h>
#define RED 200
#define KOL 200
int main() {
int M,N,j,k,i,l,br=0,mat[RED][KOL];
do{
printf("Unesite brojeve M i N: ");
scanf("%d %d",&M,&N);
    if(M>200 || M<1 || N>200 || N<1) printf("Brojevi nisu u trazenom opsegu. \n");}
    while(M>200||M<1 || N>200 || N<1);
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d",&mat[i][j]);
        }
    }
for(i=0;i<M-1;i++)
    for(k=i+1;k<M;k++){
        br=0;
            for(j=0;j<N;j++){
                if(mat[i][j]==mat[k][j]) br++;
                else break;
            }
            if(br==N){
                for(l=k;l<M;l++)
                for(j=0;j<N;j++)
                mat[l][j]=mat[l+1][j];
                M--;
                k--;
            }
        }

for(j=0;j<N-1;j++)
for(k=j+1;k<N;k++){
    br=0;
    for(i=0;i<M;i++){
        if(mat[i][j]==mat[i][k]) br++;
        else break;
    }
    if(br==M){
        for(i=0;i<M;i++)
        for(l=k;l<N;l++)
        mat[i][l]=mat[i][l+1];
        N--;
        k--;
    }
}
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
	return 0;
}
