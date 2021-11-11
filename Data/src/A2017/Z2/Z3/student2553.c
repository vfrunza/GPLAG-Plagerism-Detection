#include <stdio.h>

int main()
{
    int i,j,A,B,C,D;
    double matA[100][100],matB[100][100],matp[100][100]={0};
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d",&A,&B);
    printf("Unesite clanove matrice A: ");
    for(i=0; i<B; i++) {
        for(j=0; j<A; j++)
            scanf("%lf",&matA[i][j]);
    }
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d",&C,&D);
    printf("Unesite clanove matrice B: ");
    for(i=0; i<D; i++) {
        for(j=0; j<C; j++)
            scanf("%lf",&matB[i][j]);
    }
    for(i=0; i<B; i++) {
        for(j=0; j<A; j++)
            matp[j][A-1-i]=matA[i][j];
    }

    for(i=0; i<B; i++) {
        for(j=0; j<A; j++)
           { if(matp[i][j]!=matB[i][j])
             {   printf("NE");
        return 0;}}
    }
    printf("DA");
    return 0;
}
