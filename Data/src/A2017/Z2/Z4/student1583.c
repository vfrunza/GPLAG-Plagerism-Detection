#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[110][110], B[110][110], C[110][110];
    int M,N,i,j;
    int nizA[10000],nizB[10000],nizC[10000];
    int brojacA=0,brojacB=0,brojacC=0,ind_min;
    int tempA,tempB,tempC;

    printf("Unesite brojeve M i N: ");

    do{
        scanf("%d%d", &M,&N);
        if(M<0 || M>100 || N<0 || N>100){
            printf("Unesite brojeve M i N: ");
        }

    }while(M<0 || M>100 || N<0 || N>100);

    printf("Unesite clanove matrice A: ");

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d", &A[i][j]);
        }
    }
    printf("Unesite clanove matrice B: ");

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d", &B[i][j]);
        }
    }
    printf("Unesite clanove matrice C: ");

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d", &C[i][j]);
        }
    }

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
                nizA[brojacA]=A[i][j];
        brojacA++;
        }
    }

    for(i=0;i<M*N;i++){
          ind_min=i;
        for(j=i+1;j<M*N;j++){
                if(nizA[j]<nizA[ind_min]){
                    ind_min=j;
                }
        }
        tempA=nizA[i];
        nizA[i]=nizA[ind_min];
        nizA[ind_min]=tempA;
    }


    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
                nizB[brojacB]=B[i][j];
        brojacB++;
        }
    }

    for(i=0;i<M*N;i++){
            ind_min=i;
        for(j=i+1;j<M*N;j++){
                if(nizB[j]<nizB[ind_min]){
                    ind_min=j;
                }
        }
        tempB=nizB[i];
        nizB[i]=nizB[ind_min];
        nizB[ind_min]=tempB;
    }


    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
                nizC[brojacC]=C[i][j];
        brojacC++;
        }
    }

    for(i=0;i<M*N;i++){
            ind_min=i;
        for(j=i+1;j<M*N;j++){
                if(nizC[j]<nizC[ind_min]){
                    ind_min=j;
                }
        }
        tempC=nizC[i];
        nizC[i]=nizC[ind_min];
        nizC[ind_min]=tempC;
    }
    
	
    for(i=0;i<M*N;i++){
        if(nizA[i]!=nizB[i] || nizA[i]!=nizC[i]){
            printf("NE");
            return 0;
        }
    }

    printf("DA");
    return 0;
}
