#include <stdio.h>
#define V 200
 
int main(){
    int a=1;
    int mat[V][V];
    int i,j,k,M,N,l;
    do
    {
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &M, &N);
    if(M<1 || M>200 || N>200 || N<1) /* petlja while ce se nastavljati sve dok M i N ne budu u trazenom opsegu */
    {
    printf("Brojevi nisu u trazenom opsegu.\n");
    continue;
    }
    break;
    }while(1);
    
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        
            scanf("%d", &mat[i][j]);
        }
    
    
    for(i=0; i<M; i++)/* petlja za izbacivanje identicnih redova date matrice*/
     {
        for(j=i+1; j<M; j++)
        {
            a=1;
            if(mat[i][0] == mat[j][0])
            {
                for(k=0; k<N; k++)
                {
                    if(mat[i][k] != mat[j][k]) /* prekid petlje i izmjena logicke varijable a znaci nailazak na clanove reda koji su razliciti */
                    {
                        a=0;
                        break;
                    }
                }
                if(a == 1){
                    for(l=j+1; l<M; l++)
                    {
                        for(k=0; k<N; k++)
                        {
                            mat[l-1][k]=mat[l][k]; /* pomjeranje redova preko onog u kome se nalaze isti clanovi */
                        }
                    }
                    M--; /* smanjenje broja redova matrice */
                    j--; /* ponovna provjera clanova reda kojeg poredimo */
                }
            }
        }
    }
    for(j=0; j<N; j++) /* na nacin slican prethodnom vrsimo brisanje kolona date matrice*/
    
        for(i=j+1; i<N; i++)
        {
            a=1;
            if(mat[0][j] == mat[0][i]){
                for(k=0; k<M; k++){
                    if(mat[k][j] != mat[k][i]){
                        a=0;
                        break;
                    }
                }
                if(a == 1){
                    for(l=i+1; l<N; l++){
                        for(k=0; k<M; k++){
                            mat[k][l-1]=mat[k][l];
                        }
                    }
                    
                    N--;
                    i--;
                }
            }
        }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
   
    return 0;
}